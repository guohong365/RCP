#ifndef _CTP_API_HANDLER_H_
#define  _CTP_API_HANDLER_H_
#include <rcp.h>
#include <tradeapi/ThostFtdcMdApi.h>
#include <stdio.h>
#include <iostream>
#ifdef WIN32
#include <Windows.h>
#endif
namespace rcp {
	class CtpApiHandler : public CThostFtdcMdSpi
	{
	public:
		CtpApiHandler(CThostFtdcMdApi * pApi);
		virtual ~CtpApiHandler();

	
		///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
		void OnFrontConnected() override;;

		///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
		///@param nReason ����ԭ��
		///        0x1001 �����ʧ��
		///        0x1002 ����дʧ��
		///        0x2001 ����������ʱ
		///        0x2002 ��������ʧ��
		///        0x2003 �յ�������
		void OnFrontDisconnected(int nReason) override;;

		///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
		///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
		void OnHeartBeatWarning(int nTimeLapse) override;;


		///��¼������Ӧ
		void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo,
		                    int nRequestID, bool bIsLast) override;;

		///�ǳ�������Ӧ
		void OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID,
		                     bool bIsLast) override;;

		///����Ӧ��
		void OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;;

		///��������Ӧ��
		void OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument,
		                        CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;;

		///ȡ����������Ӧ��
		void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument,
		                          CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;;

		///����ѯ��Ӧ��
		void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument,
		                         CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;;

		///ȡ������ѯ��Ӧ��
		void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument,
		                           CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override;;

		///�������֪ͨ
		void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData) override;

		///ѯ��֪ͨ
		void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp) override;
	private:
		CThostFtdcMdApi * _pApi;
		static int requestId;
		static bool isError(CThostFtdcRspInfoField* pRspInfo);
		void login();
	};
}
#endif

