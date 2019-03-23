#include "CtpQuotation.h"
#include <tradeapi/ThostFtdcUserApiStruct.h>
namespace rcp {
	CtpQuotation::CtpQuotation(const CThostFtdcDepthMarketDataField* pMarketDataField)
		:AbstractQuotation(pMarketDataField->InstrumentID, pMarketDataField->TradingDay,
			pMarketDataField->ExchangeID, pMarketDataField->ExchangeInstID, pMarketDataField->LastPrice,
			pMarketDataField->PreSettlementPrice, pMarketDataField->PreClosePrice, pMarketDataField->PreOpenInterest,
			pMarketDataField->OpenPrice, pMarketDataField->HighestPrice, pMarketDataField->LowestPrice,
			pMarketDataField->Volume, pMarketDataField->Turnover, pMarketDataField->OpenInterest, pMarketDataField->ClosePrice,
			pMarketDataField->SettlementPrice, pMarketDataField->UpperLimitPrice, pMarketDataField->LowerLimitPrice,
			pMarketDataField->PreDelta, pMarketDataField->CurrDelta, pMarketDataField->UpdateTime, pMarketDataField->UpdateMillisec,
			pMarketDataField->BidPrice1, pMarketDataField->BidVolume1, pMarketDataField->AskPrice1, pMarketDataField->AskVolume1,
			pMarketDataField->BidPrice2, pMarketDataField->BidVolume2, pMarketDataField->AskPrice2, pMarketDataField->AskVolume2,
			pMarketDataField->BidPrice3, pMarketDataField->BidVolume3, pMarketDataField->AskPrice3, pMarketDataField->AskVolume3,
			pMarketDataField->BidPrice4, pMarketDataField->BidVolume4, pMarketDataField->AskPrice4, pMarketDataField->AskVolume4,
			pMarketDataField->BidPrice5, pMarketDataField->BidVolume5, pMarketDataField->AskPrice5, pMarketDataField->AskVolume5,
			pMarketDataField->AveragePrice, pMarketDataField->ActionDay)
	{
	}

	CtpQuotation::~CtpQuotation()
	{
	}
}