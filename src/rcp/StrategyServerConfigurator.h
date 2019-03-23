#pragma once
#include <rcp.h>
#include <vector>

#include <Poco/Util/AbstractConfiguration.h>
#include "StrategyServer.h"

namespace rcp {
	class RCP_API StrategyServerConfigurator
	{
	public:
		static void configure(Poco::Util::AbstractConfiguration *pConfig, CtpConfiguration & ctp);
	};
}
