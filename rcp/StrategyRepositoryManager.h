#pragma once
#include <vector>
#include "AbstractTradeStrategy.h"
#include <Poco/SharedPtr.h>

namespace rcp {
	class StrategyRepositoryManager
	{
		std::vector<Poco::SharedPtr<AbstractTradeStrategy>> repository;
	public:
		StrategyRepositoryManager();
		~StrategyRepositoryManager();
		void add(AbstractTradeStrategy* pStrategy);
		AbstractTradeStrategy* find(const std::string& name);
	};
}
