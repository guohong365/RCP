#pragma once
#include "Quotation.h"
#include <tradeapi/ThostFtdcUserApiStruct.h>
namespace rcp {
	class CtpQuotation : public AbstractQuotation
	{
	public:
		explicit CtpQuotation(const CThostFtdcDepthMarketDataField* pMarketDataField);
		~CtpQuotation();
	};

}
