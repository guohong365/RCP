#ifndef _TRADE_STRATEGY_INFO_H_
#define _TRADE_STRATEGY_INFO_H_

#include <string>
#include "../include/rcp.h"

namespace rcp {
	 class RCP_API TradeStrategyItem
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
		const std::string& version() const;
		const std::string& name() const;
		const std::string& description() const;
		int type() const;
		bool isValid() const;
		void isValid(bool valid);
		bool isEnabled() const;
		void isEnabled(bool enabled);
		virtual ~TradeStrategyItem();

		TradeStrategyItem(
			const std::string& version,
			const std::string& name,
			int type,
			bool valid = true,
			bool enabled = true,
			const std::string& description = "");
	protected:
		void version(const std::string& version_);

		void name(const std::string& name_);

		void description(const std::string& desc);

		void type(int type_);
	};
}

#endif