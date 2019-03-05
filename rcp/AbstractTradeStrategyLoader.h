#ifndef _ABSTRACT_TRADE_STRATEGY_LOADER_H_
#define _ABSTRACT_TRADE_STRATEGY_LOADER_H_
#include "AbstractTradeStrategy.h"

namespace rcp {
	class TradeStrategyInfo;

	RCP_API class AbstractTradeStrategyLoader {
	public:
		virtual ~AbstractTradeStrategyLoader() = default;
		virtual AbstractTradeStrategy *create(const TradeStrategyInfo * pInfo) = 0;
	};
	
}

#endif
