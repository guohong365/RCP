#ifndef _ABSTRACT_TRADE_STRATEGY_H_
#define _ABSTRACT_TRADE_STRATEGY_H_

#define OBJECT_ID_LEN 32
#define OBJECT_NAME_LEN 64
#define DESCRIPTION_LEN 256
#include <string>
#include "../include/rcp_type.h"
#include "rcp.h"
#include "TradeStrategyItem.h"

namespace rcp {

	
	 class RCP_API AbstractTradeStrategy : public TradeStrategyItem
	{
	public:
		AbstractTradeStrategy(
			const std::string& name,
			int type,
			bool valid = true,
			bool enabled = true,
			const std::string& description = "");
		virtual ~AbstractTradeStrategy();
		virtual void initialize() =0;
		virtual long onMarketData(void * pData, size_t size) =0;
	};	

	class TradeStrategyContext
	{
		
	};	   	 

}
#endif