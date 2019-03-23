#include "pch.h"
#include "JsonTest.h"
#include <Poco/JSON/Object.h>
#include <CppUnit/TestSuite.h>
#include <CppUnit/TestCaller.h>


JsonTest::JsonTest(const std::string& name)
	:TestCase(name)
{
}

JsonTest::~JsonTest()
{
}

void JsonTest::testJson()
{
	Poco::JSON::Object object;
	object.set("Name", "Rain");
	object.set("Age", 4);
	object.set("Birthday", Poco::DateTime(2014, 11, 4));
	object.set("Height", 90.5);
	object.stringify(std::cout);
}

CppUnit::Test* JsonTest::suite()
{
	CppUnit::TestSuite *pSuite = new CppUnit::TestSuite("JsonTest");
	CppUnit_addTest(pSuite, JsonTest, testJson);
	return pSuite;
}
