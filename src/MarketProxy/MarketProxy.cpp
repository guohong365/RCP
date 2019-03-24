// MarketProxy.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <Poco/Util/XMLConfiguration.h>
#include <tradeapi/ThostFtdcMdApi.h>
#include "../rcp/MdSpi.h"

int main(void)
{

	// 初始化UserApi

	rcp::CMdSpi spi(
		rcp::CtpConfiguration("137637","9999", "710929",
			"tcp://180.168.146.187:10031", { "j1905","sm1905" }), nullptr);
	spi.connect();
	spi.join();
	return 0;
}
