#include "stdafx.h"
#include "AbstractTradeStrategy.h"


rcp::AbstractTradeStrategy::AbstractTradeStrategy(
	const std::string& name, int type,	bool valid,	bool enabled, const std::string& description)
	:TradeStrategyItem(RCP_VERSION, "", type, valid, enabled, description)
{
}


rcp::AbstractTradeStrategy::~AbstractTradeStrategy()
{
}
