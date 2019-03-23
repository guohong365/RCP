#include "pch.h"

#include "StrategyRunnerAdapter.h"
#include "../rcp/DllTradeStrategy.h"

void rcp::AbstractRunnerAdapter::setup(AbstractConfiguration* pConfig)
{
	std::string item = pConfig->getString("description", "");
	description(item);
	enabled(pConfig->getBool("enabled", false));
	item = pConfig->getString("path", "");
	path(item);
	item = pConfig->getString("protocol", "");
	protocol(item);
}

rcp::AbstractRunnerAdapter::AbstractRunnerAdapter(const std::string& name, const std::string & type)
	: AbstractTradeStrategy(type)
	, _pLogger(&Poco::Logger::get(name))
{
}

Poco::Logger& rcp::AbstractRunnerAdapter::logger()
{
	return *_pLogger;
}


rcp::DllRunnerAdapter::DllRunnerAdapter(const std::string &name)
	: AbstractRunnerAdapter(name, "dll")
	, _fInit(nullptr)
	, _fonTick(nullptr)
	,_fUninit(nullptr)
{

}

void rcp::DllRunnerAdapter::setup(AbstractConfiguration* pConfig)
{
	AbstractRunnerAdapter::setup(pConfig);
	_initMethod = pConfig->getString("methods[@initialize]", "");
	_onTickMethod = pConfig->getString("methods[@onTick]", "");
	_uninitMethod = pConfig->getString("methods[@onUninitialize]", "");
}

int rcp::DllRunnerAdapter::initialize()
{
	try {
		_library.load(path());
		void *p = _library.getSymbol(_initMethod);
		_fInit = static_cast<ON_INITIALIZE_CALLBACK>(p);
		p = _library.getSymbol(_onTickMethod);
		_fonTick = static_cast<ON_TICK_CALLBACK>(p);
		p = _library.getSymbol(_uninitMethod);
		_fUninit = static_cast<ON_UNINITIALIZE_CALLBACK>(p);
		_fInit();
		return 0;
	}catch (Poco::LibraryLoadException& ex)
	{
		logger().error(ex.what());
		enabled(false);
		return -1;
	}
	catch(Poco::NotFoundException & ex)
	{
		logger().log(ex);
		enabled(false);
		return -2;
	}
	catch(...)
	{
		logger().fatal("system failed.");
		enabled(false);
		return -3;
	}

}

void rcp::DllRunnerAdapter::onTick(const void* data, unsigned len)
{
	_fonTick(data, len);
}

void rcp::DllRunnerAdapter::uninitialize()
{
	_fUninit();
}

bool rcp::DllRunnerAdapter::checkValid()
{
	return AbstractRunnerAdapter::checkValid() &&
		!(_initMethod.empty() || _onTickMethod.empty() || _uninitMethod.empty());
}
