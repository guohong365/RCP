#include <iostream>
#include "SubscriberTest.h"
#include <Poco/Util/XMLConfiguration.h>
#include <Poco/Util/LoggingConfigurator.h>
#include <Poco/Logger.h>
#include "CppUnit/TestSuite.h"
#include "CppUnit/TestCaller.h"
#include "../rcp/QuotationSubscriber.h"
#include "../rcp/StrategyServerConfigurator.h"

SubscriberTest::SubscriberTest(const std::string& name)
	: TestCase(name)
	, _pConfig(new Poco::Util::XMLConfiguration)
{
	
}

SubscriberTest::~SubscriberTest()
{
}

void SubscriberTest::testLogger()
{
	Poco::Logger& logger =Poco::Logger::get("subscriber");
	logger.trace("trace");
	logger.debug("debug");
	logger.information("information");
	logger.notice("notice");
	logger.error("error");
	logger.critical("critical");
	logger.fatal("fatal");
}

void SubscriberTest::testRun()
{
	std::cerr << "=================" << std::endl;
	
	Poco::Logger& logger = Poco::Logger::get("testRun");
	
	rcp::CtpConfiguration ctp;	
	rcp::StrategyServerConfigurator::configure(_pConfig, ctp);
	
	logger.trace("ctp configured.");
	rcp::QuotationSubscriber subscriber(ctp, nullptr);
	TaskManager taskManager;
	taskManager.start(&subscriber);
	logger.trace("started");
#ifdef WIN32
	Sleep(20000);
#else
	sleep(20);
#endif
	taskManager.cancelAll();
	taskManager.joinAll();
	
}

void SubscriberTest::testHandler()
{
}

void SubscriberTest::setUp()
{
	_pConfig->load("../etc/strategy_server.xml");
	Poco::Util::LoggingConfigurator configurator;
	configurator.configure(_pConfig);
}

void SubscriberTest::tearDown()
{
}

CppUnit::Test* SubscriberTest::suite()
{
	CppUnit::TestSuite * pSuite = new CppUnit::TestSuite("SubscriberTest");
	CppUnit_addTest(pSuite, SubscriberTest, testLogger);
	CppUnit_addTest(pSuite, SubscriberTest, testRun);
	CppUnit_addTest(pSuite, SubscriberTest, testHandler);
	return pSuite;
}
