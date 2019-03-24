#include "TradeStrategy.h"
#include <string>


const std::string&  rcp::AbstractTradeStrategy::protocol() const
{
	return _protocol;
}

const std::string&  rcp::AbstractTradeStrategy::name() const
{
	return _name;
}

const std::string&  rcp::AbstractTradeStrategy::description() const
{
	return _description;
}

const std::string&  rcp::AbstractTradeStrategy::instrument() const
{
	return _instrument;
}

const std::string&  rcp::AbstractTradeStrategy::path() const
{
	return _path;
}

const std::string& rcp::AbstractTradeStrategy::type() const
{
	return _type;
}


bool rcp::AbstractTradeStrategy::enabled() const
{
	return _enabled;
}

void rcp::AbstractTradeStrategy::enabled(bool enabled)
{
	_enabled = enabled;
}

rcp::AbstractTradeStrategy::~AbstractTradeStrategy()
{
}

void rcp::AbstractTradeStrategy::protocol(const std::string& version_)
{
	_protocol = version_;
}

void rcp::AbstractTradeStrategy::name(const std::string& name_)
{
	_name = name_;
}

void rcp::AbstractTradeStrategy::instrument(const std::string&  instrument)
{
	_instrument = instrument;
}

void rcp::AbstractTradeStrategy::description(const std::string&  desc)
{
	_description = desc;
}

void rcp::AbstractTradeStrategy::path(const std::string&  path_)
{
	_path = path_;
}

bool rcp::AbstractTradeStrategy::checkValid()
{
	return !(_protocol.empty() || _path.empty());
}

