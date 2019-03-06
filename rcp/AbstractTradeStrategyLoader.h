#ifndef _ABSTRACT_TRADE_STRATEGY_LOADER_H_
#define _ABSTRACT_TRADE_STRATEGY_LOADER_H_
#include "AbstractTradeStrategy.h"

namespace rcp {
	class TradeStrategyItem;

	 class RCP_API AbstractTradeStrategyLoader {
	public:
		virtual ~AbstractTradeStrategyLoader() = default;
		virtual AbstractTradeStrategy *create(const TradeStrategyItem * pInfo) = 0;
	};


	
}

#endif
