#pragma once
#include <string>
#include <rcp.h>
#include <tradeapi/ThostFtdcUserApiStruct.h>
namespace rcp {
	class CtpHelper
	{
	public:
		static std::string getMarketDataString(CThostFtdcDepthMarketDataField* pDepthMarketData);
	private:
		CtpHelper() {};
	};
}

