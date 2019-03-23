
#include "CtpHelper.h"

std::string rcp::CtpHelper::getMarketDataString(CThostFtdcDepthMarketDataField* pDepthMarketData)
{
	std::string str = "Quote SDK 接收行情信息:InstrumentID:";
	str += pDepthMarketData->InstrumentID;
	str += " TradingDay:";
	str += pDepthMarketData->TradingDay;
	str += " LastPrice:";
	str += std::to_string(pDepthMarketData->LastPrice);
	str += " Volume:";
	str += std::to_string(pDepthMarketData->Volume);
	str += " OpenPrice:";
	str += std::to_string(pDepthMarketData->OpenPrice);
	str += " HighestPrice:";
	str += std::to_string(pDepthMarketData->HighestPrice);
	str += " LowestPrice:";
	str += std::to_string(pDepthMarketData->LowestPrice);
	str += " ClosePrice:";
	str += std::to_string(pDepthMarketData->ClosePrice);
	str += " PreClosePrice:";
	str += std::to_string(pDepthMarketData->PreClosePrice);
	str += " UpdateTime:";
	str += pDepthMarketData->UpdateTime;
	return str;
}
