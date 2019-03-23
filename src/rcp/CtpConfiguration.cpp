#include "stdafx.h"
#include "CtpConfiguration.h"
#include <tradeapi/ThostFtdcMdApi.h>


rcp::CtpConfiguration::CtpConfiguration()
{
}

rcp::CtpConfiguration::CtpConfiguration(const std::string& userId_, const std::string& brokerId_,
	const std::string& pwd, const std::string& frontend, 
	const std::vector<std::string>& instruments_,
	const std::string& cache_)
	:userId(userId_)
	,brokerId(brokerId_)
	,password(pwd)
	,marketFrontEnd(frontend)
	,cachePath(cache_)
{
	instruments.insert(instruments_.begin(), instruments_.end());
}

rcp::CtpConfiguration::CtpConfiguration(const CtpConfiguration& config)
	:userId(config.userId)
	,brokerId(config.brokerId)
	,password(config.password)
	,marketFrontEnd(config.marketFrontEnd)
	,cachePath(config.cachePath)
{
	instruments.insert(config.instruments.begin(), config.instruments.end());
}

rcp::CtpConfiguration& rcp::CtpConfiguration::operator=(const CtpConfiguration& config)
{
	brokerId = config.brokerId;
	userId = config.userId;
	password = config.password;
	marketFrontEnd = config.marketFrontEnd;
	cachePath = config.cachePath;
	instruments.clear();
	instruments.insert(config.instruments.begin(), config.instruments.end());
	return *this;
}

void rcp::CtpConfiguration::dump(std::ostream& output)
{
	output << "CTP CONFIG:" << std::endl
		<< "\t\tbrokenId=[" << brokerId << "]" << std::endl
		<< "\t\tuser=[" << userId << "]" << std::endl
		<< "\t\tpassword=[" << password << "]" << std::endl
		<< "\t\tfront-end=[" << marketFrontEnd << "]" << std::endl
		<< "\t\tcache-path=[" << cachePath << "]" << std::endl;
	output << "\tinstruments=[";
	int count = instruments.size();
	int index = 0;
	for (InstrumentSet::const_iterator it= instruments.begin(); it!=instruments.end(); ++it)
	{
		output << (*it);
		if (index < count - 1) output << ",";
		index++;
	}
	output << "]" << std::endl;
}

void rcp::CtpConfiguration::add(RunnerStub* pRunner)
{
	runners.push_back(pRunner);
	instruments.insert(pRunner->instrument());
	RunnerMap::iterator it = map.find(pRunner->instrument());
	if (it != map.end())
	{
		(*it).second->push_back(pRunner);
	}
	else
	{
		map.insert_or_assign(pRunner->instrument(), new RunnerList);
		map.at(pRunner->instrument())->push_back(pRunner);
	}
}
