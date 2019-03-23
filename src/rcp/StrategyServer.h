#ifndef _STRATEGY_SERVER_H_
#define _STRATEGY_SERVER_H_
#include <rcp.h>
#include <Poco/Util/ServerApplication.h>
#include <Poco/TaskManager.h>
#include "CtpConfiguration.h"
#ifdef WIN32
#include <Poco/Process_WIN32U.h>
#else
#include <Poco/PipeImpl_POSIX.h>
#endif
#include "Quotation.h"
#include "QuotationHandler.h"
#include "RunnerStub.h"

using Poco::TaskManager;
namespace rcp {	
	class RCP_API StrategyServer : public Poco::Util::ServerApplication, public IQuotationHandler
	{
	public:

		StrategyServer();
		~StrategyServer();
		
		void name(const std::string&  name);
		const char* name() const override;
		const std::string& version();
		void version(const std::string & version_);
		CtpConfiguration & ctp();
		void onQuotation(const IQuotation* pQuotation) override;
		void add(RunnerStub * pRunner);
	protected:
		void configServer();
		int run() override;
		void defineOptions(Poco::Util::OptionSet& options) override;
		void displayHelp();
		virtual void handleHelp(const std::string& name, const std::string& value);
		int main(const std::vector<std::string>& args) override;
		void initialize(Application& app) override;
		static void join();
	private:
#ifdef WIN32
		static BOOL __stdcall ConsoleCtrlHandler(DWORD ctrlType);
#endif
		static Poco::Event _terminated;
		bool _displayHelp;
		std::string _name;
		std::string _version;
		CtpConfiguration _ctpConfiguration;

		TaskManager _taskManager;
	};
}
#endif
