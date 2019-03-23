#include "stdafx.h"

#include "StrategyServerConfigurator.h"
#include <Poco/UTF8Encoding.h>
#include <Poco/AutoPtr.h>
#include <cassert>
#include "TradeStrategyConfigurator.h"



using Poco::Util::AbstractConfiguration;
using Poco::AutoPtr;
void rcp::StrategyServerConfigurator::configure(AbstractConfiguration* pConfig, CtpConfiguration& ctp)
{
	poco_check_ptr(pConfig);

	const std::string key = "StrategyServer.CTP";
	AutoPtr<AbstractConfiguration> pCTP = pConfig->createView(key);
	ctp.userId = pCTP->getString("user", "");
	ctp.brokerId = pCTP->getString("brokerId", "");
	ctp.password = pCTP->getString("password", "");
	ctp.marketFrontEnd = pCTP->getString("front-end", "");
	ctp.cachePath =pConfig->getString("application.cacheDir", "");

	AbstractConfiguration::Keys keys;
	AutoPtr<AbstractConfiguration> pStrategies = pConfig->createView("StrategyServer.Runners");
	pStrategies->keys(keys);
	for (AbstractConfiguration::Keys::const_iterator it = keys.cbegin(); it != keys.cend(); ++it)
	{
		std::string item = (*it);
		std::string instrument = pStrategies->getString(item + "[@instrument]", "");
		std::string config = pStrategies->getString(item + "[@config]", "");
		std::string exec = pStrategies->getString(item + "[@exec]", "");

		RunnerStub *pRunner = new RunnerStub(instrument,exec, config);
		ctp.add(pRunner);
	}
}
