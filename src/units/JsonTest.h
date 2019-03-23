#pragma once
#include <CppUnit/TestCase.h>

class JsonTest :public CppUnit::TestCase
{
public:
	explicit JsonTest(const std::string& name);
	~JsonTest();
	void setUp() override{};
	void tearDown() override{};
	void testJson();
	static Test* suite();
};

