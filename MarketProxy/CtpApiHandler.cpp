#include "pch.h"
#include "CtpApiHandler.h"
#include <iostream>


rcp::CtpApiHandler::CtpApiHandler(): _pMdApi(nullptr)
{
}


rcp::CtpApiHandler::~CtpApiHandler()
{
}

void rcp::CtpApiHandler::connect()
{
	//创建并初始化API
	char address[100];
	strcpy_s(address, sizeof(address), "tcp://180.168.146.187:10031");
	_pMdApi = CThostFtdcMdApi::CreateFtdcMdApi("", true);
	_pMdApi->RegisterSpi(this);
	_pMdApi->RegisterFront(address);
	_pMdApi->Init();
}

void rcp::CtpApiHandler::login() const
{
	CThostFtdcReqUserLoginField t = {0};
	strcpy_s(t.BrokerID, 11, "9999");
	strcpy_s(t.UserID, 16, "137637");
	strcpy_s(t.Password, 41, "GUOHONG");
	while (_pMdApi->ReqUserLogin(&t, 1) != 0)
	{
#ifdef WIN32
		Sleep(1000);
#else
				sleep(1);
#endif
	}
}

void rcp::CtpApiHandler::subscribe()
{
	char** ppInstrument = new char *[1];
	ppInstrument[0] = new char[100];
	strcpy_s(ppInstrument[0], 100,"IF1809");
	while (_pMdApi->SubscribeMarketData(ppInstrument, 1) != 0)
	{
#ifdef WIN32
		Sleep(1000);
#else
		sleep(1);
#endif
	}
}

void rcp::CtpApiHandler::OnFrontConnected()
{
	std::cout << "connected...." << std::endl;
}

void rcp::CtpApiHandler::OnFrontDisconnected(int nReason)
{
	std::cout << "disconnected [" << nReason << "]" << std::endl;
}

void rcp::CtpApiHandler::OnHeartBeatWarning(int nTimeLapse)
{
	std::cout << "heart beat warning [" << nTimeLapse << "]" << std::endl;
}

void rcp::CtpApiHandler::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo,
                                        int nRequestID, bool bIsLast)
{
	std::cout << "resp user login:" << std::endl;
}

void rcp::CtpApiHandler::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo,
                                         int nRequestID, bool bIsLast)
{
	std::cout << "rsp user logout:" << std::endl;
}

void rcp::CtpApiHandler::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	std::cout << "rsp ERROR: " << std::endl;
}

void rcp::CtpApiHandler::OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument,
                                            CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	std::cout << "rsp subscribe market data." << std::endl;
}

void rcp::CtpApiHandler::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument,
                                              CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	std::cout << "rsp unsubscribe market data." << std::endl;
}

void rcp::CtpApiHandler::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument,
                                             CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	std::cout << "OnRspSubForQuoteRsp :" << std::endl;
}

void rcp::CtpApiHandler::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument,
                                               CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	std::cout << "OnRspUnSubForQuoteRsp :" << std::endl;
}

void rcp::CtpApiHandler::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData)
{
	std::cout << "OnRtnDepthMarketData :" << std::endl;
}

void rcp::CtpApiHandler::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp)
{
	std::cout << "OnRtnForQuoteRsp :" << std::endl;
}

