#pragma once
#include "CppUnit/TestCase.h"
#include <CppUnit/TestSuite.h>

class RunnerStubTest:public CppUnit::TestCase
{
public:
	RunnerStubTest(const std::string& name);
	~RunnerStubTest();
	void setUp() override;
	void tearDown() override;
	void testRunner();
	static CppUnit::Test *suite();
};

