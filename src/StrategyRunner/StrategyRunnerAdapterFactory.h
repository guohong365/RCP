#pragma once
#include <Poco/DynamicFactory.h>
#include "StrategyRunnerAdapter.h"
#include "../rcp/TradeStrategy.h"
#include <Poco/Util/LoggingConfigurator.h>

namespace  rcp {	
	class IStrategyRunnerAdapterInstantiator
	{
	public:
		virtual ~IStrategyRunnerAdapterInstantiator()
		{
		}
		virtual AbstractRunnerAdapter * create(const std::string & name) = 0;
	};
	template <class AdapterClass> class StrategyRunnerAdapterInstantiator : public IStrategyRunnerAdapterInstantiator
	{
	public:
		~StrategyRunnerAdapterInstantiator()
		{
		}
		AbstractRunnerAdapter * create(const std::string & name) override
		{
			return new AdapterClass(name);
		}
	};

	class StrategyRunnerAdapterFactory
	{
	public:
		StrategyRunnerAdapterFactory();
		virtual ~StrategyRunnerAdapterFactory();
		void registerFactory(const std::string& typeName, IStrategyRunnerAdapterInstantiator* pFactory);
		AbstractRunnerAdapter * create(const std::string& type, const std::string & name);
		static StrategyRunnerAdapterFactory& instance();
	protected:
		void registerBuiltins();
	private:
		typedef std::map<std::string, IStrategyRunnerAdapterInstantiator*> FactoryMap;
		FactoryMap _runnerMap;
	};
}
