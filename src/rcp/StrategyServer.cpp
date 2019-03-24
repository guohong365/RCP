// StrategyServer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <Poco/Pipe.h>
#include <Poco/Util/HelpFormatter.h>
#include "StrategyServer.h"
#include "StrategyServerConfigurator.h"
#include "MdSpi.h"
#include "QuotationSubscriber.h"
#include <Poco/AutoPtr.h>


using Poco::Util::HelpFormatter;
using Poco::AutoPtr;
using Poco::Util::AbstractConfiguration;

Poco::Event rcp::StrategyServer::_terminated;

rcp::StrategyServer::StrategyServer()
	:_displayHelp(false)
{
	setUnixOptions(true);
	Logger::setLevel("", Poco::Message::PRIO_TRACE);
}


rcp::StrategyServer::~StrategyServer()
{
}

int rcp::StrategyServer::run()
{	
	if (_displayHelp) 
	{
		displayHelp();
		return EXIT_OK;
	}
	return ServerApplication::run();
}


void rcp::StrategyServer::name(const std::string& name)
{
	_name = name;
}

const char* rcp::StrategyServer::name() const
{
	return _name.c_str();
}

const std::string& rcp::StrategyServer::version()
{
	return _version;
}

void rcp::StrategyServer::version(const std::string& version_)
{
	_version = version_;
}

rcp::CtpConfiguration& rcp::StrategyServer::ctp()
{
	return _ctpConfiguration;
}

void rcp::StrategyServer::onQuotation(const rcp::IQuotation* pQuotation)
{
	logger().trace("quotation about [%s] is incoming....", pQuotation->instrumentId());
	
	RunnerMap::iterator it= ctp().map.find(pQuotation->instrumentId());
	if(it!=ctp().map.end())
	{
		std::string message = pQuotation->toJsonString();
		RunnerList * pList = (*it).second;
		for (RunnerList::iterator rt=pList->begin(); rt!=pList->end(); ++ rt)
		{
			(*rt)->send(message.c_str(), message.length());
		}
	} 
	else
	{
		logger().warning("no runner about instrument [%s]", pQuotation->instrumentId());
	}
}



void rcp::StrategyServer::configServer()
{
	AutoPtr<AbstractConfiguration> pServer = config().createView("StrategyServer");
	_name=pServer->getString("[@name]", "");
	_version=pServer->getString("[@version]", "");
	StrategyServerConfigurator::configure(pServer, ctp());
}

void rcp::StrategyServer::defineOptions(Poco::Util::OptionSet& options)
{
	ServerApplication::defineOptions(options);
	options.addOption(Poco::Util::Option("help", "h", "display help information.")
		.repeatable(false)
		.callback(Poco::Util::OptionCallback<StrategyServer>(this, &StrategyServer::handleHelp))
	);
}

void rcp::StrategyServer::displayHelp()
{
	HelpFormatter formatter(options());
	formatter.setUnixStyle(true);
	formatter.setCommand(commandName());
	formatter.setUsage("参数");
	formatter.setHeader("RCP 策略运行服务器 ver 0.0.1");
	formatter.format(std::cout);
}

void rcp::StrategyServer::handleHelp(const std::string& name, const std::string& value)
{
	_displayHelp = true;
	stopOptionsProcessing();
}

#ifdef WIN32
BOOL rcp::StrategyServer::ConsoleCtrlHandler(DWORD ctrlType)
{
	switch (ctrlType)
	{
	case CTRL_C_EVENT:
	case CTRL_CLOSE_EVENT:
	case CTRL_BREAK_EVENT:
		instance().logger().critical("CTRL+C key was inputted. server is shutting down.");
		_terminated.set();
		return _terminated.tryWait(10000) ? TRUE : FALSE;
	default:
		return FALSE;
	}
}
#endif
int rcp::StrategyServer::main(const std::vector<std::string>& args)
{
	logger().information(std::string("Server [") + name() + "(" + version() + ")] started ...");
	QuotationSubscriber quotationSubscriber(ctp(), this);
	for(RunnerList::iterator it=ctp().runners.begin(); it!=ctp().runners.end(); ++it)	
	{
		logger().information("launch runner for [%s] with config [%s]", (*it)->instrument(), (*it)->config());
		(*it)->launch();		
	}
	logger().trace("all strategy runner launched....");
	_taskManager.start(&quotationSubscriber);
	join();
	_taskManager.cancelAll();
	_taskManager.joinAll();
	logger().trace("server terminated...");

	return EXIT_OK;
}

void rcp::StrategyServer::initialize(Application& app)
{	
	char separator = Poco::Path::separator();
	std::string binDir=app.config().getString("application.dir");
	Poco::Path binPath(binDir);
	std::string rootDir= binPath.parent().toString();
	std::string configDir = rootDir + "etc" + separator;
	std::string dataDir = rootDir + "data" + separator;
	std::string cacheDir = rootDir + "cache" + separator;
	app.config().setString("application.configDir", configDir);	
	
	loadConfiguration(configDir + "strategy_server.xml");
	ServerApplication::initialize(app);
	
	setLogger(Poco::Logger::get("SYS"));

	app.config().setString("application.dataDir", dataDir);
	app.config().setString("application.cacheDir", cacheDir);
	app.config().setString("application.tempDir", cacheDir);

	logger().trace("--------------------  initial configuration ------------------------------");
	logger().trace("path=[%s] name=[%s] baseName=[%s] dir=[%s] configDir=[%s] dataDir=[%s] cacheDir=[%s] tempDir=[%s]", 
		app.config().getString("application.path"),
		app.config().getString("application.name"),
		app.config().getString("application.baseName"),
		app.config().getString("application.dir"),
		app.config().getString("application.configDir"),
		app.config().getString("application.dataDir"),
		app.config().getString("application.cacheDir"),
		app.config().getString("application.tempDir"));

	StrategyServerConfigurator ::configure(&config(), ctp());
	logger().trace("CTP: user=[%s] password=[%s] brokerId=[%s] front-end-uri=[%s] cache=[%s]",
		ctp().userId,
		ctp().password,
		ctp().brokerId,
		ctp().marketFrontEnd,
		ctp().cachePath);
	logger().trace("=====STRATEGIES=====");
	for(RunnerList::const_iterator it=ctp().runners.begin();it!=ctp().runners.end(); ++it)
	{		
		logger().trace("instrument=[%s] config=[%s]", (*it)->instrument(), (*it)->config());
	}
}

void rcp::StrategyServer::join()
{
#ifdef WIN32
	SetConsoleCtrlHandler(ConsoleCtrlHandler, TRUE);
#endif
	_terminated.wait();
}
