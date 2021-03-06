﻿// units.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


#include <Poco/Util/XMLConfiguration.h>
#include <CppUnit/TestSuite.h>
#include "CppUnit/TestRunner.h"
#include "SubscriberTest.h"
#include "AllTestSuit.h"

using Poco::Util::AbstractConfiguration;

void printKeys(AbstractConfiguration *pConfig,const std::string & key)
{
	AbstractConfiguration::Keys keys;
	pConfig->keys(key, keys);
	for (AbstractConfiguration::Keys::const_iterator it = keys.cbegin(); it != keys.cend(); ++it)
	{
		std::cerr << *it << std::endl;
	}
}

void printStrategies(AbstractConfiguration * pConfiguration)
{
	AbstractConfiguration::Keys keys;
	Poco::AutoPtr<AbstractConfiguration> pStrategies = pConfiguration->createView("StrategyServer.Strategies");
	pStrategies->keys( keys);
	for (AbstractConfiguration::Keys::const_iterator it = keys.cbegin(); it != keys.cend(); ++it)
	{	
		std::string item = (*it) + "[@name]";
		std::string name= pStrategies->getString(item);
		item = (*it) + "[@description]";
		std::string description=pStrategies->getString(item);
		item = (*it) + "[@contract]";
		std::string contract = pStrategies->getString(item);
		item = (*it) + "[@type]";
		std::string type = pStrategies->getString(item);
		item = (*it) + "[@enabled]";
		bool enabled= pStrategies->getBool(item);
		item = (*it) + "[@path]";
		std::string path = pStrategies->getString(item);
		item = (*it) + "[@version]";
		std::string version = pStrategies->getString(item);
		//rcp::ITradeStrategyItem * pStrategy = new rcp::TradeStrategyItem(version, name, contract, type, path, true, enabled, description);
	}
}

/*
int main()
{
	//setlocale(LC_ALL, ".65001");
    std::cout << "Hello World!\n";

	Poco::AutoPtr<Poco::Util::XMLConfiguration> pConfig=new Poco::Util::XMLConfiguration();
	try
	{
		pConfig->load("../etc/strategy_server.xml");
		printKeys(pConfig, "");
		std::cerr << "----------------" << std::endl;
		printKeys(pConfig->createView("StrategyServer"), "");

		std::cerr << "----------------" << std::endl;
		printKeys(pConfig, "StrategyServer.CTP");
		std::cerr << "----------------" << std::endl;
		printKeys(pConfig, "StrategyServer.Strategies");
		std::cerr << "----------------" << std::endl;
		printStrategies(pConfig);

	}
	catch (rcp::InvalidFormat ex)
	{
		std::cerr << "invalid format :" << ex.what() << std::endl;
	}

}
*/

CppUnitMain(AllTestSuit)