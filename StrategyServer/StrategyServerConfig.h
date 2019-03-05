#pragma once
#include <vector>

namespace rcp {
	class StrategyServerConfig
	{
	public:
		std::string ServerName;
		//CTP相关配置
		std::vector<std::string> MarketServers;
		std::string flowPath;

		//策略库相关
		std::string strategyRepositoryPath;


	};
}
