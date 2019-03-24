#pragma once
#include <rcp.h>
#include <vector>
#include <map>
#include "RunnerStub.h"
#include <set>

namespace  rcp {
	class RCP_API CtpConfiguration
	{
	public:
		CtpConfiguration();
		CtpConfiguration(const std::string& userId_, const std::string & brokerId_, 
			const std::string& pwd, const std::string& frontend,
			const std::vector<std::string> & instruments_,
			const std::string & cache="");
		CtpConfiguration(const CtpConfiguration& config);
		CtpConfiguration & operator=(const CtpConfiguration & config);
		//CTP相关配置
		std::string userId;
		std::string brokerId;
		std::string password;
		std::string marketFrontEnd;
		std::string cachePath;
		InstrumentSet instruments;
		RunnerMap map;
		RunnerList runners;
		void dump(std::ostream& output);
		void add(RunnerStub* pRunner);
	};
}

