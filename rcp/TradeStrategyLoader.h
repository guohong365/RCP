#ifndef _ABSTRACT_TRADE_STRATEGY_LOADER_H_
#define _ABSTRACT_TRADE_STRATEGY_LOADER_H_
#include <Poco/XML/XML.h>
#include <Poco/DOM/Element.h>
#include <string>
#include "../include/rcp.h"
namespace rcp {
	class ITradeStrategyItem;

	 class RCP_API ITradeStrategyLoader {
	public:
		virtual ~ITradeStrategyLoader() = default;
		virtual ITradeStrategyItem *load(const std::string & configFile) = 0;
	};

	class RCP_API ITradeStrategyParser  
	{		
	public:
		const std::string TAG_NAME = "strategy";
		virtual ~ITradeStrategyParser() = default;
		virtual ITradeStrategyItem * parse(const Poco::XML::Element *pElement)=0;
	};

	class RCP_API DllTradeStrategyParser : public ITradeStrategyParser
	{
	public:
		virtual ~DllTradeStrategyParser();
		ITradeStrategyItem* parse(const Poco::XML::Element* pElement) override;
	};


}

#endif
