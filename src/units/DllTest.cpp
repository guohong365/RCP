#include <rcp.h>
#include "DllTest.h"
#include <Poco/AutoPtr.h>
#include <Poco/SharedLibrary.h>
#include <CppUnit/TestSuite.h>
#include <CppUnit/TestCaller.h>

typedef int(__stdcall *ON_INITIALIZE_CALLBACK)();
typedef void(__stdcall *ON_TICK_CALLBACK)(const void *, unsigned);
typedef void(__stdcall *ON_UNINITIALIZE_CALLBACK)();

DllTest::DllTest(const std::string& name)
	:TestCase(name)
{
}

DllTest::~DllTest()
{
}

void DllTest::testEchoStrategy()
{
	Poco::SharedLibrary library;
	library.load("EchoStrategy.dll");
	ON_INITIALIZE_CALLBACK fpInit =reinterpret_cast<ON_INITIALIZE_CALLBACK>(library.getSymbol("onStart"));
	ON_TICK_CALLBACK fpOnTick = reinterpret_cast<ON_TICK_CALLBACK>(library.getSymbol("onTickIn"));
	ON_UNINITIALIZE_CALLBACK fpUninit = reinterpret_cast<ON_UNINITIALIZE_CALLBACK>(library.getSymbol("onStop"));
	std::string hello = "Hello world!";
	fpInit();
	fpOnTick(hello.c_str(), hello.length());
	fpUninit();
}

void DllTest::testStrategy1()
{
	Poco::SharedLibrary library;
	library.load("strategy1.dll");
	ON_INITIALIZE_CALLBACK fpInit = reinterpret_cast<ON_INITIALIZE_CALLBACK>(library.getSymbol("onInitialize"));
	ON_TICK_CALLBACK fpOnTick = reinterpret_cast<ON_TICK_CALLBACK>(library.getSymbol("onTick"));
	ON_UNINITIALIZE_CALLBACK fpUninit = reinterpret_cast<ON_UNINITIALIZE_CALLBACK>(library.getSymbol("onUninitialize"));
	std::string hello = "Hello world!";
	fpInit();
	fpOnTick(hello.c_str(), hello.length());
	fpUninit();
}

void DllTest::setUp()
{
}

void DllTest::tearDown()
{
}

CppUnit::Test* DllTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("DllTest");
	CppUnit_addTest(pSuite, DllTest, testEchoStrategy);
	CppUnit_addTest(pSuite, DllTest, testStrategy1);
	return pSuite;
}
