// StrategyServer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <Poco/Util/HelpFormatter.h>
#include "StrategyServer.h"

using Poco::Util::HelpFormatter;

int main(int argc, char** argv)
{
	rcp::StrategyServer server;
	server.run(argc, argv);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件


rcp::StrategyServer::StrategyServer()
	:_displayHelp(false)
{
}


rcp::StrategyServer::~StrategyServer()
{
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

int rcp::StrategyServer::main(const std::vector<std::string>& args)
{
	if (_displayHelp) {
		displayHelp();
	}
	else {
		std::cout << "Hello world." << std::endl;
	}
	return EXIT_OK;	
}

void rcp::StrategyServer::initialize(Application& app)
{
}
