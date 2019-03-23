#include "StrategyRunner.h"
#include "../rcp/TradeStrategy.h"
#include <Poco/Util/HelpFormatter.h>
#include "StrategyRunnerAdapterFactory.h"

StrategyRunner::StrategyRunner()
	: _displayHelp(false)
	, _name("StrategyRunner")
	, _pAdapter(nullptr)
{
	setUnixOptions(true);
}

StrategyRunner::~StrategyRunner()
{
	delete _pAdapter;
}

const char* StrategyRunner::name() const
{
	return _name.c_str();
}

int StrategyRunner::run(int argc, char** argv)
{
	try {
		init(argc, argv);
		if (_displayHelp) return EXIT_OK;
		return Application::run();
	}	
	catch (Poco::Exception & ex)
	{
		logger().fatal(ex.message());
	}
	catch (std::exception & ex)
	{
		logger().fatal(ex.what());
	}
	catch (...)
	{
		logger().error("unknown error..");
	}
	return EXIT_OSERR;
}

int StrategyRunner::main(const std::vector<std::string>& args)
{
	_pAdapter->initialize();
	std::string input;
	int ch=0;
	logger().information("prepare read data....");
	while(true)
	{		
		ch=std::cin.get();
		if (ch == -1 || std::cin.fail()) break;
		if (ch != '\n')
		{
			input.push_back(char(ch));
		} 
		else
		{
			logger().information(input);
			_pAdapter->onTick(input.c_str(), input.length());
			input.clear();
		}
	}
	logger().warning("stdin was closed. runner is shutting down ...");
	_pAdapter->uninitialize();
	return EXIT_OK;
}

void StrategyRunner::initialize(Application& app)
{
	try
	{	
		loadConfiguration(_config);
		Application::initialize(app);
		AbstractConfiguration::Keys keys;
		Poco::AutoPtr<AbstractConfiguration> pStrategy = config().createView("Strategy");
		pStrategy->keys(keys);
		std::string name = pStrategy->getString("name");
		std::string type = pStrategy->getString("type");
		if (name.empty()) 
		{
			throw Poco::Exception("strategy is missing [name] config");

		}
		if (type.empty())
		{
			throw Poco::Exception("strategy was missing [type] config");
		}
		_pAdapter = rcp::StrategyRunnerAdapterFactory::instance().create(type, name);
		if (!_pAdapter) 
		{
			throw Poco::Exception("RunnerAdapter was created failed. ");
		}
		_pAdapter->setup(pStrategy);
		if (!_pAdapter->checkValid())
		{
			throw Poco::Exception("RunnerAdapter was not properly prepared.");
		}
		if(!_pAdapter->enabled())
		{
			throw Poco::Exception("RunnerAdapter was disabled.");
		}
	}
	catch (...)
	{
		throw;
	}
}

void StrategyRunner::handleOption(const std::string& name, const std::string& value)
{
	if (name == "help")
	{
		Poco::Util::HelpFormatter formatter(options());
		formatter.setUnixStyle(true);
		formatter.setCommand(commandName());
		formatter.setUsage("options");
		formatter.setHeader("Strategy Runner ver 0.0.1");
		formatter.format(std::cerr);
		_displayHelp = true;
		stopOptionsProcessing();
	}	
	else if (name == "config")
	{
		_config = value;
	}
	else if (name =="name")
	{
		_name = value;
	}
	else if (name == "instrument")
	{
		_instrument = value;
	}
}

void StrategyRunner::defineOptions(Poco::Util::OptionSet& options)
{
	Application::defineOptions(options);
	options.addOption(Poco::Util::Option("help", "h", "print THIS program's usage.", false));
	options.addOption(Poco::Util::Option("config", "c", "config file", true, "config", true));
	options.addOption(Poco::Util::Option("instrument", "i", "related instrument id", false, "<id>", true));
	options.addOption(Poco::Util::Option("name", "n", "name of current process log file", false, "<name>", true));
}
#ifdef WIN32
BOOL StrategyRunner::ControlHandler(DWORD ctrlType)
{
	switch (ctrlType)
	{
	case CTRL_C_EVENT:
	case CTRL_CLOSE_EVENT:
	case CTRL_BREAK_EVENT:
		
		return TRUE;
	default:
		return FALSE;
	}
}
#endif