#pragma once

struct UserLoginField
{
	
};
struct UserLogoutField
{
	
};
struct ResponseInfoField
{
	
};
struct InstrumentField
{
	
};
struct QuotationField
{
	
};
struct ResponseQuotationField
{

};
class IQuotationAdapter 
{
public:
	IQuotationAdapter();
	virtual ~IQuotationAdapter();

protected:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected() {};

	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason) {};

	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse) {};


	///��¼������Ӧ
	virtual void OnRspUserLogin(UserLoginField *pRspUserLogin, ResponseInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(ResponseInfoField *pUserLogout, ResponseInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����Ӧ��
	virtual void OnRspError(ResponseInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������Ӧ��
	virtual void OnRspSubMarketData(InstrumentField *pSpecificInstrument, ResponseInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ȡ����������Ӧ��
	virtual void OnRspUnSubMarketData(InstrumentField *pSpecificInstrument, ResponseInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����ѯ��Ӧ��
	virtual void OnRspSubForQuoteRsp(InstrumentField *pSpecificInstrument, ResponseInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ȡ������ѯ��Ӧ��
	virtual void OnRspUnSubForQuoteRsp(InstrumentField *pSpecificInstrument, ResponseInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������֪ͨ
	virtual void OnRtnDepthMarketData(QuotationField *pDepthMarketData) {};

	///ѯ��֪ͨ
	virtual void OnRtnForQuoteRsp(ResponseQuotationField *pForQuoteRsp) {};
};

