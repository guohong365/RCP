#ifndef _TRADE_STRATEGY_INFO_H_
#define _TRADE_STRATEGY_INFO_H_

#include <string>
namespace rcp {
	class TradeStrategyInfo
	{
		std::string _version;
		std::string _name; // 服务名
		std::string _description;	// 服务描述。
		int _type = 0;
		// 处理器类型
		// 0 - 内部
		// 1 - 动态库
		// 2 - 执行程序
		// 3 - COM
		// 4 - CORBA
		// 5 - Web Service
		bool _valid = false;		// 0 - invalid 1 - valid
		bool _enabled = false;    // 1 - enabled 0 - disabled
	public:
		const std::string& version() const
		{
			return _version;
		}
		const std::string& name()const
		{
			return _name;
		}
		const std::string& description() const
		{
			return _description;
		}
		int type() const
		{
			return _type;
		}
		bool isValid() const
		{
			return _valid;
		}
		void isValid(bool valid)
		{
			_valid = valid;
		}
		bool isEnabled() const
		{
			return _enabled;
		}
		void isEnabled(bool enabled)
		{
			_enabled = enabled;
		}
		virtual ~TradeStrategyInfo() {}

		TradeStrategyInfo(
			const std::string& version,
			const std::string& name,
			int type,
			bool valid = true,
			bool enabled = true,
			const std::string & description = "")
			:_version(version)
			, _name(name)
			, _description(description)
			, _type(type)
			, _valid(valid)
			, _enabled(enabled)
		{

		}
		TradeStrategyInfo(){}
		virtual long load(const std::string configFile);
		virtual long save(const std::string configFile);
	};

}

#endif