#include "AllTestSuit.h"
#include "SubscriberTest.h"
#include "RunnerStubTest.h"
#include "DllTest.h"
#include "JsonTest.h"


CppUnit::TestSuite* AllTestSuit::suite()
{
	CppUnit::TestSuite *pSuite = new CppUnit::TestSuite("allSuite");
	pSuite->addTest(SubscriberTest::suite());
	pSuite->addTest(RunnerStubTest::suite());
	pSuite->addTest(DllTest::suite());
	pSuite->addTest(JsonTest::suite());
	return pSuite;
}
