#ifndef _ABSTRACT_TRADE_STRATEGY_H_
#define _ABSTRACT_TRADE_STRATEGY_H_

#define OBJECT_ID_LEN 32
#define OBJECT_NAME_LEN 64
#define DESCRIPTION_LEN 256
#include <string>
#include "../include/rcp_type.h"
#include "rcp.h"
#include "TradeStrategyInfo.h"

namespace rcp {

	
	RCP_API class  AbstractTradeStrategy : public TradeStrategyInfo
	{
	public:
		AbstractTradeStrategy();
		virtual ~AbstractTradeStrategy();
		virtual void initialize() =0;
		virtual long onMarketData(void * pData, size_t size) =0;
	};	

	class TradeStrategyContext
	{
		
	};	   	 

}
#endif