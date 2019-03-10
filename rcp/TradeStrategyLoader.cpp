#include "stdafx.h"

#include "TradeStrategyLoader.h"
#include "TradeStrategyItem.h"

rcp::DllTradeStrategyParser::~DllTradeStrategyParser()
{
}

rcp::ITradeStrategyItem* rcp::DllTradeStrategyParser::parse(const Poco::XML::Element* pElement)
{	
	if(pElement && pElement->tagName() == TAG_NAME)
	{
		const std::string name = pElement->getAttribute("name");
		const int type = std::atoi(pElement->getAttribute("type").c_str());
		const std::string version = pElement->getAttribute("version");
		const std::string desc = pElement->getAttribute("description");
		const bool enabled = pElement->getAttribute("enabled")=="true";
		const std::string path = pElement->getAttribute("path");
		const bool valid = (type > 0 && type < 5);
		ITradeStrategyItem * pItem = new TradeStrategyItem(version, name, type, path, true, enabled, desc);
		return pItem;
	}
	return nullptr;
}
