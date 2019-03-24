#include "RunnerStub.h"
#include <Poco/Process.h>
#include <Poco/Pipe.h>
#include <Poco/Util/Application.h>
using Poco::Process;
using Poco::Pipe;
const std::string& rcp::RunnerStub::instrument() const
{
	return _instrument;
}

void rcp::RunnerStub::instrument(const std::string& value)
{
	_instrument = value;
}

const std::string& rcp::RunnerStub::config() const
{
	return _config;
}

void rcp::RunnerStub::config(const std::string& value)
{
	_config = value;
}

const std::string& rcp::RunnerStub::execPath() const
{
	return _execPath;
}

void rcp::RunnerStub::execPath(const std::string& path)
{
	_execPath = path;
}

void rcp::RunnerStub::launch()
{
//	Poco::Util::Application::instance().logger().information("launched [%s --config=%s --instrument=%s", _execPath, _config, _instrument);
	Process::Args args;
	args.push_back("--config=" + _config );
	args.push_back("--instrument=" + _instrument);
	Pipe pipe;
	_pHandle = new ProcessHandle(Process::launch(_execPath, args, &pipe, nullptr, nullptr));
	_pStream = new PipeOutputStream(pipe);
}

void rcp::RunnerStub::shutdown()
{
	poco_check_ptr(_pStream);
	poco_check_ptr(_pHandle);

	_pStream->close();
	_pHandle->wait();
}

void rcp::RunnerStub::send(const char* pBuff, size_t size)
{
	poco_check_ptr(_pStream);
	_pStream->write(pBuff, size);
	_pStream->flush();
	//_pStream->close();
}

bool rcp::RunnerStub::running()
{
	if(_pHandle) return	Process::isRunning(_pHandle->id());
	return  false;
}

rcp::RunnerStub::RunnerStub()
	: _pStream(nullptr)
	, _pHandle(nullptr)
{
}

rcp::RunnerStub::RunnerStub(const std::string& instrument, const std::string& exec, const std::string& config)
	: _pStream(nullptr)
	, _pHandle(nullptr)
	, _instrument(instrument)
	, _config(config)
	, _execPath(exec)
{
}

rcp::RunnerStub::~RunnerStub()
{
	delete _pStream;
	delete _pHandle;
}

void rcp::RunnerStub::join()
{
	_pHandle->wait();
}
