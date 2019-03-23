#pragma once
#include <Poco/Util/AbstractConfiguration.h>
#include "TradeStrategy.h"
#include <map>

using Poco::Util::AbstractConfiguration;
namespace rcp {

	class ITradeStrategyConfigurator
	{
	public:
		virtual ~ITradeStrategyConfigurator() = default;
		virtual const char* type()=0;
		virtual ITradeStrategy * NewInstance() = 0;
		virtual void ReleaseInstance(ITradeStrategy *pStrategy) = 0;
		virtual void configure(AbstractConfiguration* pConfig, ITradeStrategy *pStrategy)=0;
	};

	class AbstractTradeStrategyConfigurator:public ITradeStrategyConfigurator
	{
	public:
		void configure(AbstractConfiguration* pConfig, ITradeStrategy* pStrategy) override;
		void ReleaseInstance(ITradeStrategy* pStrategy) override;
	};

	class DllTradeStrategyConfigurator: public AbstractTradeStrategyConfigurator
	{
	public:
		const char* type() override;
		ITradeStrategy* NewInstance() override;
		void configure(AbstractConfiguration* pConfig, ITradeStrategy *pStrategy) override;
	};

	class TradeStrategyFactory
	{
	public:
		TradeStrategyFactory()
		{
			registerInner();
		}
		ITradeStrategy * create(AbstractConfiguration*pConfig);
		static TradeStrategyFactory& instance();
	private:
		void registerInner();
		std::map<std::string, ITradeStrategyConfigurator*> _configurators;
	};
}
