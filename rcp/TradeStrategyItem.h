#ifndef _TRADE_STRATEGY_INFO_H_
#define _TRADE_STRATEGY_INFO_H_

#include <string>
#include "../include/rcp.h"

namespace rcp {
	class RCP_API ITradeStrategyItem
	{
	public:
		virtual const std::string& version() const=0;
		virtual const std::string& name() const=0;
		virtual const std::string& description() const=0;
		virtual int type() const=0;
		virtual const std::string& path() const = 0;
		virtual bool isValid() const=0;
		virtual void isValid(bool valid)=0;
		virtual bool isEnabled() const=0;
		virtual void isEnabled(bool enabled)=0;
		virtual ~ITradeStrategyItem()=default;
	};
	class RCP_API TradeStrategyItem : public ITradeStrategyItem
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
		std::string _path;
		bool _valid = false;		// 0 - invalid 1 - valid
		bool _enabled = false;    // 1 - enabled 0 - disabled
	public:
		const std::string& version() const override;
		const std::string& name() const override;
		const std::string& description() const override;
		int type() const override;
		const std::string& path() const override;
		bool isValid() const override;
		void isValid(bool valid) override;
		bool isEnabled() const override;
		void isEnabled(bool enabled) override;
		virtual ~TradeStrategyItem();

		TradeStrategyItem(
			const std::string& version,
			const std::string& name,
			int type,
			const std::string& path,
			bool valid = true,
			bool enabled = true,
			const std::string& description = "");
	protected:
		void version(const std::string& version_);
		void name(const std::string& name_);
		void description(const std::string& desc);
		void type(int type_);
		void path(const std::string& path_);
	};
}

#endif