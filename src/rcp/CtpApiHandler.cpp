
#include <rcp.h>
#include "CtpApiHandler.h"
#include <iostream>
#include <tradeapi/ThostFtdcMdApi.h>


#define BROKEN_ID "9999"
#define PASSWORD "710929"
#define USER_ID "137637"

int rcp::CtpApiHandler::requestId = 0;

rcp::CtpApiHandler::CtpApiHandler(CThostFtdcMdApi* pApi)
	:_pApi(pApi)
{
}

rcp::CtpApiHandler::~CtpApiHandler()
{
}

void rcp::CtpApiHandler::OnFrontConnected()
{
	std::cout << "connected...." << std::endl;
	login();
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

bool rcp::CtpApiHandler::isError(CThostFtdcRspInfoField* pRspInfo)
{
	// 如果ErrorID != 0, 说明收到了错误的响应
	const bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
	if (bResult)
		std::cerr << "--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << std::endl;
	return bResult;
}

void rcp::CtpApiHandler::login()
{
	CThostFtdcReqUserLoginField loginField;
	memset(&loginField,0, sizeof(CThostFtdcLoginInfoField));
	strncpy(loginField.BrokerID, BROKEN_ID, sizeof(TThostFtdcBrokerIDType));
	loginField.BrokerID[sizeof(TThostFtdcBrokerIDType) - 1]=0;
	strncpy(loginField.Password, PASSWORD, sizeof(TThostFtdcPasswordType));
	loginField.Password[sizeof(TThostFtdcPasswordType) - 1] = 0;
	strncpy(loginField.UserID, USER_ID, sizeof(TThostFtdcUserIDType));
	loginField.UserID[sizeof(TThostFtdcUserIDType) - 1] = 0;

	const int result = _pApi->ReqUserLogin(&loginField, ++requestId);
	std::cerr << " login : " << (result == 0 ? "成功" : "失败") << std::endl;
}

