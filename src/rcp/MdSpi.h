#pragma once
#include "rcp.h"
#include <tradeapi/ThostFtdcMdApi.h>
#include "CtpConfiguration.h"
#include "QuotationHandler.h"
#include <vector>
#include <set>

namespace  rcp {

	class RCP_API CMdSpi : public CThostFtdcMdSpi
	{

	public:
		explicit CMdSpi(const CtpConfiguration & config, IQuotationHandler *pHandler);
		virtual ~CMdSpi() = default;


		///错误应答
		void OnRspError(CThostFtdcRspInfoField *pRspInfo,
			int nRequestID, bool bIsLast) override;

		///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		///@param nReason 错误原因
		///        0x1001 网络读失败
		///        0x1002 网络写失败
		///        0x2001 接收心跳超时
		///        0x2002 发送心跳失败
		///        0x2003 收到错误报文
		void OnFrontDisconnected(int nReason) override;

		///心跳超时警告。当长时间未收到报文时，该方法被调用。
		///@param nTimeLapse 距离上次接收报文的时间
		void OnHeartBeatWarning(int nTimeLapse) override;

		///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
		void OnFrontConnected() override;

		///登录请求响应
		void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override;

		///订阅行情应答
		void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override;

		///订阅询价应答
		void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override;

		///取消订阅行情应答
		void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument,
			CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		///取消订阅询价应答
		void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo,
			int nRequestID, bool bIsLast) override;

		///深度行情通知
		void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData) override;

		///询价通知
		void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) override;

		void connect();
		void connect(const CtpConfiguration& config);
		void subscribeMarketData(std::set<std::string>& instruments);
		void subscribeForQuotationResponse(std::set<std::string> & instruments);
		void join();
		void release();
	private:
		CtpConfiguration _config;
		//std::string _brokerId;// = "9999";				// 经纪公司代码
		//std::string _investorId;// = "137637";			// 投资者代码
		//std::string _password;// = "710929";			// 用户密码
		void reqUserLogin();
		CThostFtdcMdApi* _pUserApi;
		IQuotationHandler *_pHandler;
		static bool isError(CThostFtdcRspInfoField *pRspInfo);
		static int _requestId;
		char **_ppInstruments;
	};

}
