#pragma once
#include <Poco/TaskManager.h>
#include <Poco/SharedLibrary.h>
#include <Poco/Util/ServerApplication.h>
#include "StrategyRunnerAdapter.h"

class StrategyRunner : public Poco::Util::Application
{
public:
	StrategyRunner();
	~StrategyRunner();
	const char* name() const override;
	int run(int argc, char**argv);
protected:
	int main(const std::vector<std::string>& args) override;
	void initialize(Application& app) override;
	void handleOption(const std::string& name, const std::string& value) override;
	void defineOptions(Poco::Util::OptionSet& options) override;
#ifdef WIN32
	static BOOL ControlHandler(DWORD ctrlType);
#endif
private:
	bool _displayHelp;
	std::string _name;
	std::string _instrument;
	std::string _config;
	rcp::AbstractRunnerAdapter * _pAdapter;
};
