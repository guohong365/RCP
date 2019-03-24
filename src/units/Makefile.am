CPPUNIT=~/poco-1.9.1/CppUnit/include
noinst_PROGRAMS= test
test_SOURCES= AllTestSuit.cpp AllTestSuit.h DllTest.cpp DllTest.h JsonTest.cpp JsonTest.h RunnerStubTest.cpp RunnerStubTest.h SubscriberTest.cpp SubscriberTest.h units.cpp
test_CPPFLAGS=-I$(top_srcdir)/include -I$(POCO_UNIT_ROOT)/include
test_LDADD=-L../rcp -lrcp -lPocoFoundation -lPocoUtil -lPocoJSON -lCppUnit
EXTRA_DIST=units.vcxproj
