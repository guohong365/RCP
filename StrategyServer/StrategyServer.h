#ifndef _STRATEGY_SERVER_H_
#define _STRATEGY_SERVER_H_
#include <Poco/Util/ServerApplication.h>
using Poco::Util::ServerApplication;

namespace rcp {
	class StrategyServer : public ServerApplication
	{
	public:
		StrategyServer();
		~StrategyServer();
	protected:
		void defineOptions(Poco::Util::OptionSet& options) override;
		void displayHelp();
		virtual void handleHelp(const std::string& name, const std::string& value);
		int main(const std::vector<std::string>& args) override;
		void initialize(Application& app) override;
	private:
		bool _displayHelp;
	};
}
#endif
