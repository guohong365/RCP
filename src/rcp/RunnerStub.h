#pragma once
#include <rcp.h>
#include <Poco/PipeStream.h>
#include <Poco/Process.h>
#include <set>

using Poco::PipeOutputStream;
using Poco::ProcessHandle;
namespace rcp {
	
	class RCP_API RunnerStub
	{
	public:
		const std::string & instrument() const;
		void instrument(const std::string& value);
		const std::string & config() const;
		void config(const std::string& value);
		const std::string& execPath() const;
		void execPath(const std::string& path);
		void launch();
		void shutdown();
		void send(const char * pBuff, size_t size);
		bool running();
		RunnerStub();
		RunnerStub(const std::string& instrument,const std::string& exec, const std::string& config);
		~RunnerStub();
		void join();
	private:
		PipeOutputStream * _pStream;
		ProcessHandle *_pHandle;

		std::string _instrument;
		std::string _config;
		std::string _execPath;
	};
	typedef std::set<std::string> InstrumentSet;
	typedef std::vector<RunnerStub*> RunnerList;
	typedef std::map<std::string, RunnerList *> RunnerMap;
}
