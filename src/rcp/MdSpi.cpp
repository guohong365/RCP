
#include "MdSpi.h"
#include <iostream>
#include <vector>
#include "Quotation.h"
#include "QuotationHandler.h"
#include "CtpQuotation.h"
#include "CtpHelper.h"
using namespace std;

//#pragma warning(disable : 4996)


// USER_API参数

// 请求编号
int rcp::CMdSpi::_requestId = 0;


void rcp::CMdSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo,
		int nRequestID, bool bIsLast)
{
	cerr << "--->>> "<< "OnRspError" << endl;
	isError(pRspInfo);
}

void rcp::CMdSpi::OnFrontDisconnected(int nReason)
{
	cerr << "--->>> " << "OnFrontDisconnected" << endl;
	cerr << "--->>> Reason = " << nReason << endl;
}
		
void rcp::CMdSpi::OnHeartBeatWarning(int nTimeLapse)
{
	cerr << "--->>> " << "OnHeartBeatWarning" << endl;
	cerr << "--->>> nTimerLapse = " << nTimeLapse << endl;
}

void rcp::CMdSpi::OnFrontConnected()
{
	cerr << "--->>> " << "OnFrontConnected" << endl;
	///用户登录请求
	reqUserLogin();
}

void rcp::CMdSpi::reqUserLogin()
{
	CThostFtdcReqUserLoginField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, _config.brokerId.c_str());
	strcpy_s(req.UserID, _config.userId.c_str());
	strcpy_s(req.Password, _config.password.c_str());
	int iResult = _pUserApi->ReqUserLogin(&req, ++_requestId);
	cerr << "--->>> 发送用户登录请求: " << ((iResult == 0) ? "成功" : "失败") << endl;
}

void rcp::CMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cerr << "--->>> " << "OnRspUserLogin" << endl;
	if (bIsLast && !isError(pRspInfo))
	{
		///获取当前交易日
		cerr << "--->>> 获取当前交易日 = " << _pUserApi->GetTradingDay() << endl;
		// 请求订阅行情
		subscribeMarketData(_config.instruments);	
		// 请求订阅询价,只能订阅郑商所的询价，其他交易所通过traderapi相应接口返回
		//subscribeForQuotationResponse(_instruments);	
	}
}

char ** prepareInstrumentsBuffer(std::set<std::string> &instruments)
{
	char **ppInstruments = new char*[instruments.size()];
	int index = 0;
	int count = instruments.size();
	for (std::set<std::string>::const_iterator it= instruments.begin(); 
		it!=instruments.end(); ++it)
	{
		std::string::size_type len =(*it).length() + 1;
		ppInstruments[index] = new char[len];
		strcpy_s(ppInstruments[index], len, (*it).c_str());
		index++;
	}
	return  ppInstruments;
}

void freeInstrumentsBuffer(char **ppInstruments, int count)
{
	if(!ppInstruments || count ==0) return;
	
	for (int i = 0; i < count; ++i)
	{
		delete[] ppInstruments[i];
	}
	delete[] ppInstruments;
}

rcp::CMdSpi::CMdSpi(const CtpConfiguration & config,IQuotationHandler *pHandler)
	: _config(config)
	, _pHandler(pHandler)
	, _ppInstruments(nullptr)
{
	_pUserApi = CThostFtdcMdApi::CreateFtdcMdApi(config.cachePath.c_str());
}

void rcp::CMdSpi::connect()
{
	char frontAddress[1024];
	strcpy_s(frontAddress, _config.marketFrontEnd.c_str()); //"tcp://180.168.146.187:10031";		// 前置地址
	_pUserApi->RegisterSpi(this);
	_pUserApi->RegisterFront(frontAddress);
	_pUserApi->Init();
}

void rcp::CMdSpi::connect(const CtpConfiguration& config)
{
	_config = config;
	connect();
}

void rcp::CMdSpi::subscribeMarketData(std::set<std::string> & instruments)
{
	_ppInstruments = prepareInstrumentsBuffer(instruments);
	int iResult = _pUserApi->SubscribeMarketData(_ppInstruments, instruments.size());	

	cerr << "--->>> 发送行情订阅请求: " << ((iResult == 0) ? "成功" : "失败") << endl;
}

void rcp::CMdSpi::subscribeForQuotationResponse(std::set<std::string> & instruments)
{
	char **ppInstruments = prepareInstrumentsBuffer(instruments);
	int iResult = _pUserApi->SubscribeForQuoteRsp(ppInstruments, instruments.size());
	freeInstrumentsBuffer(ppInstruments, instruments.size());
	cerr << "--->>> 发送询价订阅请求: " << ((iResult == 0) ? "成功" : "失败") << endl;
}

void rcp::CMdSpi::join()
{
	_pUserApi->Join();
}

void rcp::CMdSpi::release()
{
	_pUserApi->Release();
	freeInstrumentsBuffer(_ppInstruments, _config.instruments.size());
}

void rcp::CMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument,
                                CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	cerr << "OnRspSubMarketData" << pSpecificInstrument->InstrumentID <<endl;
}

void rcp::CMdSpi::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument,
                                 CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	cerr << "OnRspSubForQuoteRsp" << endl;
}

void rcp::CMdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument,
                                  CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	cerr << "OnRspUnSubMarketData" << endl;
}

void rcp::CMdSpi::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument,
                                   CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	cerr << "OnRspUnSubForQuoteRsp" << endl;
}

void rcp::CMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
	cerr << "OnRtnDepthMarketData" << endl;
	std::string str=CtpHelper::getMarketDataString(pDepthMarketData);
	cerr << str << endl;;
	if (_pHandler)
	{
		_pHandler->onQuotation(new CtpQuotation(pDepthMarketData));
	}

}

void rcp::CMdSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp)
{
	cerr << "OnRtnForQuoteRsp" << endl;
}

bool rcp::CMdSpi::isError(CThostFtdcRspInfoField *pRspInfo)
{
	// 如果ErrorID != 0, 说明收到了错误的响应
	bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
	if (bResult)
		cerr << "--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
	return bResult;
}
