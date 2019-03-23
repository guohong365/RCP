#pragma once
#include <rcp.h>
#include "CtpConfiguration.h"
#include "QuotationHandler.h"
#include <Poco/Task.h>
#include <Poco/Logger.h>

using Poco::Logger;
using Poco::Task;
namespace rcp {

	class RCP_API QuotationSubscriber :public Task
	{
	public:
		QuotationSubscriber(const CtpConfiguration& config, IQuotationHandler* pHandler);
		void runTask() override;
	protected:
		Logger& logger();
	private:
		IQuotationHandler * _pHandler;
		CtpConfiguration _config;
		Logger * _pLogger;
	};
}
