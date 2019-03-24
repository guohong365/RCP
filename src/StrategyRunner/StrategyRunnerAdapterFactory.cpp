#include "StrategyRunnerAdapterFactory.h"
#include <Poco/SingletonHolder.h>
#include "../rcp/TradeStrategy.h"

namespace
{
	static Poco::SingletonHolder<rcp::StrategyRunnerAdapterFactory> sh;
}

rcp::StrategyRunnerAdapterFactory::StrategyRunnerAdapterFactory()
{
	registerBuiltins();
}

rcp::StrategyRunnerAdapterFactory::~StrategyRunnerAdapterFactory()
{
}

void rcp::StrategyRunnerAdapterFactory::registerFactory(const std::string& typeName,
                                                        IStrategyRunnerAdapterInstantiator* pFactory)
{
	FactoryMap::iterator it = _runnerMap.find(typeName);
	if (it == _runnerMap.end())
	{
		_runnerMap[typeName] = pFactory;
	}
	else
	{
		throw Poco::ExistsException(typeName);
	}
}

rcp::AbstractRunnerAdapter* rcp::StrategyRunnerAdapterFactory::create(const std::string & type,const std::string& name)
{
	FactoryMap::const_iterator it = _runnerMap.find(type);
	if(it==_runnerMap.end()) throw Poco::NotFoundException("Cannot found Factory for type ["+ type +"]");
	AbstractRunnerAdapter *pAdapter = (*it).second->create(name);
	return pAdapter;
}

rcp::StrategyRunnerAdapterFactory& rcp::StrategyRunnerAdapterFactory::instance()
{
	return *sh.get();
}

void rcp::StrategyRunnerAdapterFactory::registerBuiltins()
{
	registerFactory("dll", new StrategyRunnerAdapterInstantiator<DllRunnerAdapter>);
}
