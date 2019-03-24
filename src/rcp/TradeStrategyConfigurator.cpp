#include "TradeStrategyConfigurator.h"
#include "DllTradeStrategy.h"
#define CURRENT_STRATEGY_VERSION "1.0.0"
void rcp::AbstractTradeStrategyConfigurator::configure(AbstractConfiguration* pConfig, ITradeStrategy* pStrategy)
{
	pStrategy->name(pConfig->getString("name", "anonymous").c_str());
	pStrategy->description(pConfig->getString("description", "").c_str());	
	pStrategy->instrument(pConfig->getString("instrument", "").c_str());
	pStrategy->enabled(pConfig->getBool("enabled", false));
	pStrategy->path( pConfig->getString("path", "").c_str());
	pStrategy->protocol(pConfig->getString("protocol", CURRENT_STRATEGY_VERSION).c_str());
}

void rcp::AbstractTradeStrategyConfigurator::ReleaseInstance(ITradeStrategy* pStrategy)
{
	delete pStrategy;
}

const char* rcp::DllTradeStrategyConfigurator::type()
{
	return "dll";
}

rcp::ITradeStrategy* rcp::DllTradeStrategyConfigurator::NewInstance()
{
	return new DllTradeStrategy();
}

void rcp::DllTradeStrategyConfigurator::configure(AbstractConfiguration* pConfig, ITradeStrategy* pStrategy)
{
	AbstractTradeStrategyConfigurator::configure(pConfig, pStrategy);
	DllTradeStrategy *pDllTradeStrategy = dynamic_cast<DllTradeStrategy*>(pStrategy);
	poco_assert(pDllTradeStrategy);

	pDllTradeStrategy->initMethod(pConfig->getString("methods[@initialize]", "").c_str());
	pDllTradeStrategy->onTickMethod(pConfig->getString("methods[@onTick]", "").c_str());
	pDllTradeStrategy->uninitMethod(pConfig->getString("methods[@onUninitialize]", "").c_str());

}

namespace
{
	static Poco::SingletonHolder<rcp::TradeStrategyFactory> _tradeStrategyFactory;
}

rcp::ITradeStrategy* rcp::TradeStrategyFactory::create(AbstractConfiguration* pConfig)
{
	std::string type = pConfig->getString("type", "");
	std::map<std::string, ITradeStrategyConfigurator*>::iterator it = _configurators.find(type);
	if (it != _configurators.end())
	{
		ITradeStrategyConfigurator* pConfigurator = (*it).second;
		ITradeStrategy *pStrategy = pConfigurator->NewInstance();
		pConfigurator->configure(pConfig, pStrategy);
		if (pStrategy->checkValid()) return pStrategy;
		pConfigurator->ReleaseInstance(pStrategy);
	}
	return nullptr;
}

rcp::TradeStrategyFactory& rcp::TradeStrategyFactory::instance()
{
	return *_tradeStrategyFactory.get();
}

void rcp::TradeStrategyFactory::registerInner()
{
	_configurators.insert_or_assign("dll", new DllTradeStrategyConfigurator);
}
