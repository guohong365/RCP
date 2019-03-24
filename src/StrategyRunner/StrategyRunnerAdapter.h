#ifndef _STRATEGY_RUNNER_H_
#define _STRATEGY_RUNNER_H_
#include <Poco/Process.h>
#include "../rcp/TradeStrategy.h"
#include <Poco/Util/ServerApplication.h>
#include <Poco/SharedLibrary.h>
#include <Poco/Task.h>
#include <Poco/Util/AbstractConfiguration.h>
#include <Poco/Util/LoggingConfigurator.h>
using Poco::Util::AbstractConfiguration;
namespace rcp {
	
	class AbstractRunnerAdapter : public AbstractTradeStrategy
	{
	public:
		explicit AbstractRunnerAdapter(const std::string& name,const std::string& type);
		virtual int initialize() = 0;
		virtual void onTick(const void* data, unsigned len) = 0;
		virtual void uninitialize() = 0;
		virtual void setup(AbstractConfiguration * pConfig);
	protected:		
		Poco::Logger& logger();
	private:
		Poco::Logger* _pLogger;
	};	

	class DllRunnerAdapter :public AbstractRunnerAdapter
	{
	public:
		DllRunnerAdapter(const std::string& name);
		void setup(AbstractConfiguration* pConfig) override;
		int initialize() override;
		void onTick(const void* data, unsigned len) override;
		void uninitialize() override;
		bool checkValid() override;
	private:
		typedef int(_stdcall *ON_INITIALIZE_CALLBACK)();
		typedef void(_stdcall *ON_TICK_CALLBACK)(const void *, unsigned);
		typedef void(_stdcall *ON_UNINITIALIZE_CALLBACK)();
		std::string _initMethod;
		std::string _onTickMethod;
		std::string _uninitMethod;

		Poco::SharedLibrary _library;
		ON_INITIALIZE_CALLBACK _fInit;
		ON_TICK_CALLBACK _fonTick;
		ON_UNINITIALIZE_CALLBACK _fUninit;
	};
}
#endif

