#include "stdafx.h"
#include "StrategyRepositoryManager.h"


rcp::StrategyRepositoryManager::StrategyRepositoryManager()
{
}


rcp::StrategyRepositoryManager::~StrategyRepositoryManager()
{
}

void rcp::StrategyRepositoryManager::add(AbstractTradeStrategy* pStrategy)
{
	repository.push_back(Poco::SharedPtr<AbstractTradeStrategy>(pStrategy));
}

rcp::AbstractTradeStrategy* rcp::StrategyRepositoryManager::find(const std::string& name)
{
	for (Poco::SharedPtr<AbstractTradeStrategy>  strategy : repository)
	{
		if (strategy->name()._Equal(name))
		{
			return strategy.get();
		}
	}
	return nullptr;
}
