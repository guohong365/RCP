﻿// StrategyServer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "../rcp/StrategyServer.h"
using  Poco::Util::ServerApplication;
int main(int argc, char** argv)
{
	rcp::StrategyServer server;
	return server.ServerApplication::run(argc, argv);
}


