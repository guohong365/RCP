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


		///����Ӧ��
		void OnRspError(CThostFtdcRspInfoField *pRspInfo,
			int nRequestID, bool bIsLast) override;

		///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
		///@param nReason ����ԭ��
		///        0x1001 �����ʧ��
		///        0x1002 ����дʧ��
		///        0x2001 ����������ʱ
		///        0x2002 ��������ʧ��
		///        0x2003 �յ�������
		void OnFrontDisconnected(int nReason) override;

		///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
		///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
		void OnHeartBeatWarning(int nTimeLapse) override;

		///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
		void OnFrontConnected() override;

		///��¼������Ӧ
		void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override;

		///��������Ӧ��
		void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override;

		///����ѯ��Ӧ��
		void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override;

		///ȡ����������Ӧ��
		void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument,
			CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;

		///ȡ������ѯ��Ӧ��
		void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo,
			int nRequestID, bool bIsLast) override;

		///�������֪ͨ
		void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData) override;

		///ѯ��֪ͨ
		void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) override;

		void connect();
		void connect(const CtpConfiguration& config);
		void subscribeMarketData(std::set<std::string>& instruments);
		void subscribeForQuotationResponse(std::set<std::string> & instruments);
		void join();
		void release();
	private:
		CtpConfiguration _config;
		//std::string _brokerId;// = "9999";				// ���͹�˾����
		//std::string _investorId;// = "137637";			// Ͷ���ߴ���
		//std::string _password;// = "710929";			// �û�����
		void reqUserLogin();
		CThostFtdcMdApi* _pUserApi;
		IQuotationHandler *_pHandler;
		static bool isError(CThostFtdcRspInfoField *pRspInfo);
		static int _requestId;
		char **_ppInstruments;
	};

}
