#include "stdafx.h"
#include "TradeStrategyItem.h"


const std::string& rcp::TradeStrategyItem::version() const
{
	return _version;
}

const std::string& rcp::TradeStrategyItem::name() const
{
	return _name;
}

const std::string& rcp::TradeStrategyItem::description() const
{
	return _description;
}

int rcp::TradeStrategyItem::type() const
{
	return _type;
}

bool rcp::TradeStrategyItem::isValid() const
{
	return _valid;
}

void rcp::TradeStrategyItem::isValid(bool valid)
{
	_valid = valid;
}

bool rcp::TradeStrategyItem::isEnabled() const
{
	return _enabled;
}

void rcp::TradeStrategyItem::isEnabled(bool enabled)
{
	_enabled = enabled;
}

rcp::TradeStrategyItem::~TradeStrategyItem()
{
}

rcp::TradeStrategyItem::TradeStrategyItem(const std::string& version, const std::string& name, int type, bool valid,
                                          bool enabled, const std::string& description): _version(version)
                                                                                         , _name(name)
                                                                                         , _description(description)
                                                                                         , _type(type)
                                                                                         , _valid(valid)
                                                                                         , _enabled(enabled)
{
}

void rcp::TradeStrategyItem::version(const std::string& version_)
{
	_version = version_;
}

void rcp::TradeStrategyItem::name(const std::string& name_)
{
	_name = name_;
}

void rcp::TradeStrategyItem::description(const std::string& desc)
{
	_description = desc;
}

void rcp::TradeStrategyItem::type(int type_)
{
	_type = type_;
}
