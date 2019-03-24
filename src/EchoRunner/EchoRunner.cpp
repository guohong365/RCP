// echoRunner.cpp : 程序执行将在此处开始并结束。
//
 
#include <iostream>
#include <Poco/Util/Application.h>
#include <Poco/LoggingFactory.h>
#include <Poco/PatternFormatter.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/WindowsConsoleChannel.h>
#include <Poco/FormattingChannel.h>
#include <Poco/Util/HelpFormatter.h>
using Poco::Util::Application;
using Poco::Logger;
using Poco::Channel;
using Poco::FormattingChannel;

class EchoApp :public Application
{
public:
	EchoApp();
	int run(int argc, char**argv);
	void initialize(Application& app) override;
protected:
	void defineOptions(Poco::Util::OptionSet& options) override;
	void displayHelp();
	void handleOption(const std::string& name, const std::string& value) override;
	int main(const std::vector<std::string>& args) override;

private:
	std::string _instrument;
	std::string _execPath;
	std::string _configPath;
	bool _help;
};

void EchoApp::initialize(Application& app)
{
	Poco::PatternFormatter *pFormatter=new Poco::PatternFormatter();
	pFormatter->setProperty("pattern", "%P [%p] %Y-%m-%d %H:%M:%S.%i %t [%s]");
	Poco::Channel *pConsoleChannel = new Poco::WindowsColorConsoleChannel();
	pConsoleChannel->setProperty("enableColors", "true");
	pConsoleChannel->setProperty("traceColor", "darkgray");
	pConsoleChannel->setProperty("debugColor", "lightBlue");
	pConsoleChannel->setProperty("informationColor", "lightBlue");
	pConsoleChannel->setProperty("noticeColor", "lightBlue");
	pConsoleChannel->setProperty("warningColor", "lightBlue");
	pConsoleChannel->setProperty("errorColor", "lightBlue");
	pConsoleChannel->setProperty("criticalColor", "lightBlue");
	pConsoleChannel->setProperty("fatalColor", "lightBlue");	
	FormattingChannel *pFormattingChannel = new FormattingChannel();
	pFormattingChannel->setFormatter(pFormatter);
	pFormattingChannel->setChannel(pConsoleChannel);
	Logger::setChannel("", pFormattingChannel);
	Logger::setLevel("", Poco::Message::PRIO_TRACE);
	
	setLogger(Logger::get("echo"));
	logger().information("echo app initialized.");
}

void EchoApp::defineOptions(Poco::Util::OptionSet& options)
{
	options.addOption(Poco::Util::Option("help", "h", "Display usage messages", false));
	options.addOption(Poco::Util::Option("instrument", "i", "instrument id", true, "id", true));
	options.addOption(Poco::Util::Option("config", "c", "XML strategy config file path name.", true, "file", true));

}

void EchoApp::displayHelp()
{
	Poco::Util::HelpFormatter formatter(options());
	formatter.setUnixStyle(true);

	formatter.format(std::cout);
}

void EchoApp::handleOption(const std::string& name, const std::string& value)
{
	if (name == "instrument") {
		_instrument = value;
	}	
	else if (name == "config") {
		_configPath = value;
	}
	else if(name=="help")
	{
		_help = true;
		displayHelp();
		stopOptionsProcessing();
	}
}


int EchoApp::main(const std::vector<std::string>& args)
{
	logger().trace("echo runner was started....");
	logger().trace("instrument=[%s] config=[%s]", _instrument, _configPath);
	std::string message;
	int c=0;
	while (true) {

		c=std::cin.get();
		if (std::cin.fail() || c == -1) break;
		if (c != '\n')
		{
			logger().trace("read char [%c]", char(c));
			message.push_back(c);
		} 
		else
		{
			logger().information(message);
			message.clear();
		}
	}
	if (message.length()) {
		logger().information(message);
	}
	return EXIT_OK;
}

EchoApp::EchoApp()
	:_help(false)
{
}

int EchoApp::run(int argc, char**argv)
{
	try {
		setUnixOptions(true);
		init(argc, argv);
		if (!_help)
		{
			return Application::run();
		}
		return EXIT_OK;
	}
	catch (Poco::Exception &ex)
	{
		logger().log(ex);
	}
	catch(std::exception& ex)
	{
		logger().error(ex.what());
	}
	catch(...)
	{
		logger().error("system fatal.");
	}
	return EXIT_OSERR;
}

int main(int argc, char** argv)
{
	EchoApp app;
	return app.run(argc, argv);
}

