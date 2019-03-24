// MarketProxy.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <Poco/Util/XMLConfiguration.h>
#include <tradeapi/ThostFtdcMdApi.h>
#include "../rcp/MdSpi.h"

// UserApi对象
CThostFtdcMdApi* pUserApi;

// 配置参数
char FRONT_ADDR[] = "tcp://180.168.146.187:10031";		// 前置地址
char *ppInstrumentID[] = { "cu1205", "cu1206" };			// 行情订阅列表
int iInstrumentID = 2;									// 行情订阅数量

// 请求编号
int iRequestID = 0;

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
