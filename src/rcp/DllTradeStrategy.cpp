#include "stdafx.h"
#include "DllTradeStrategy.h"

rcp::DllTradeStrategy::DllTradeStrategy()
	:AbstractTradeStrategy("dll")
{
}


rcp::DllTradeStrategy::~DllTradeStrategy()
{
}

const std::string&  rcp::DllTradeStrategy::initMethod()const
{
	return _initMethod;
}

void rcp::DllTradeStrategy::initMethod(const std::string&  initMethod)
{
	_initMethod = initMethod;
}

const std::string&  rcp::DllTradeStrategy::onTickMethod()const
{
	return _onTickMethod;
}

void rcp::DllTradeStrategy::onTickMethod(const std::string&  value)
{
	_onTickMethod = value;
}

const std::string&  rcp::DllTradeStrategy::uninitMethod() const
{
	return _uninitMethod;
}

void rcp::DllTradeStrategy::uninitMethod(const std::string&  uninitMethod)
{
	_uninitMethod = uninitMethod;
}

bool rcp::DllTradeStrategy::checkValid()
{
	return AbstractTradeStrategy::checkValid() && !(_initMethod.empty() || _onTickMethod.empty() || _uninitMethod.empty());
}

