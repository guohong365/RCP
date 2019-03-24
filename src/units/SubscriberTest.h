#pragma once
#include <Poco/Foundation.h>
#include "CppUnit/TestCase.h"
#include <Poco/AutoPtr.h>
#include <Poco/Util/XMLConfiguration.h>

class SubscriberTest : public CppUnit::TestCase
{
public:
	explicit SubscriberTest(const std::string& name);
	~SubscriberTest();

	void testLogger();
	void testRun();
	void testHandler();
	void setUp() override;
	void tearDown() override;

	static  Test* suite();
private:
	Poco::AutoPtr<Poco::Util::XMLConfiguration> _pConfig;
};

