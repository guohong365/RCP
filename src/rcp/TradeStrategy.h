#ifndef _TRADE_STRATEGY_INFO_H_
#define _TRADE_STRATEGY_INFO_H_

#include <string>
#include <sstream>

#include <Poco/Util/AbstractConfiguration.h>
#include <rcp.h>
namespace rcp {
	class RCP_API ITradeStrategy
	{
	public:
		virtual const std::string& protocol() const=0;
		virtual void protocol(const std::string&  protocol) = 0;
		virtual const std::string&  name() const=0;
		virtual void name(const std::string& name) = 0;
		virtual const std::string&  description() const=0;
		virtual void description(const std::string&  desc) = 0;
		virtual const std::string&  instrument() const = 0;
		virtual void instrument(const std::string&  instrument) = 0;
		virtual const std::string&  type() const=0;
		virtual const std::string&  path() const = 0;
		virtual void path(const std::string&  path) = 0;
		virtual bool enabled() const=0;
		virtual void enabled(bool enabled)=0;
		virtual bool checkValid() = 0;
		virtual ~ITradeStrategy()=default;
	};
	class RCP_API AbstractTradeStrategy : public ITradeStrategy
	{
		std::string _protocol;
		std::string _name; // 服务名
		std::string _description;	// 服务描述。
		std::string _instrument;
		/*
		std::string _type;
		// 处理器类型
		// inner - 内部
		// dll - 动态库
		// exe - 执行程序
		// com - COM
		// corba - CORBA
		// ws - Web Service
		*/
		std::string _path;
		std::string _type;
		bool _enabled;    // 1 - enabled 0 - disabled
	public:
		const std::string&  protocol() const override;
		const std::string&   name() const override;
		const std::string&   description() const override;
		const std::string&   instrument() const override;
		const std::string&   path() const override;
		const std::string& type() const override;
		bool enabled() const override;
		void enabled(bool enabled) override;
		void protocol(const std::string&  version_) override;
		void name(const std::string&  name_) override;
		void instrument(const std::string&  instrument) override;
		void description(const std::string&  desc) override;
		void path(const std::string&  path_) override;
		bool checkValid() override;
		virtual ~AbstractTradeStrategy();
	protected:
		AbstractTradeStrategy(const std::string& type)
			: _enabled(true)
			, _type(type)
		{
		}

	private:
		explicit AbstractTradeStrategy(const ITradeStrategy* pStrategy) = delete;
	};

	class StrategyFormatter
	{
	public:
		virtual ~StrategyFormatter()=default;

		virtual std::string format(const ITradeStrategy * pItem)
		{
			std::stringstream output;
			output << "name=[" << pItem->name() << "] "
				<< "description=[" << pItem->description() << "] "
				<< "protocol=[" << pItem->protocol() << "] "
				<< "instrument=[" << pItem->instrument() << "] "
				<< "type=[" << pItem->type() << "] "
				<< "path=[" << pItem->path() << "] "
				<< "enabled=[" << pItem->enabled() << "]";
			return output.str();
		}
	};
}

#endif
