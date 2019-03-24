#include "RunnerStubTest.h"
#include <CppUnit/TestCaller.h>
#include "../rcp/RunnerStub.h"
#include <Poco/Logger.h>
#include <Poco/AutoPtr.h>
#include <Poco/Util/XMLConfiguration.h>
#include <Poco/Util/LoggingConfigurator.h>


RunnerStubTest::RunnerStubTest(const std::string &name)
	:TestCase(name)
{
}


RunnerStubTest::~RunnerStubTest()
{
}

void RunnerStubTest::setUp()
{
	Poco::AutoPtr<Poco::Util::XMLConfiguration> pConfig(new Poco::Util::XMLConfiguration);
	pConfig->load("../etc/strategy_server.xml");
	Poco::Util::LoggingConfigurator configurator;
	configurator.configure(pConfig);
}

void RunnerStubTest::tearDown()
{
}

void RunnerStubTest::testRunner()
{
	rcp::RunnerStub stub("12344", "StrategyRunner", "../etc/strategy2.xml");
	stub.launch();
	std::string hello = "Hello world!\n How are you?\n";
	stub.send(hello.c_str(), hello.length());
	Poco::Logger & logger = Poco::Logger::get("runner");
	logger.information("sey hello to child.");
	hello = "bye bye!\n";
	stub.send(hello.c_str(), hello.length());
	logger.information("say bye bye to child.");
	stub.shutdown();
	logger.information("shutdown");
}

CppUnit::Test* RunnerStubTest::suite()
{
	CppUnit::TestSuite *pSuite = new CppUnit::TestSuite("RunnerStubTest");
	CppUnit_addTest(pSuite, RunnerStubTest, testRunner);
	return  pSuite;
}
