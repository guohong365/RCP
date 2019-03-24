#pragma once
#include <CppUnit/TestCase.h>

class DllTest :public CppUnit::TestCase
{
public:
	explicit DllTest(const std::string &name);
	~DllTest();
	void testEchoStrategy();
	void testStrategy1();
	void setUp() override;
	void tearDown() override;
	static Test *suite();
};

