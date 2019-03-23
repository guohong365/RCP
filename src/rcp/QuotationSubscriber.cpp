#include "MdSpi.h"
#include "QuotationSubscriber.h"

rcp::QuotationSubscriber::QuotationSubscriber(const rcp::CtpConfiguration& config, IQuotationHandler* pHandler):
	Task("Quotation Subscriber")
	, _pHandler(pHandler)
	, _config(config)
	, _pLogger(nullptr)
{	
}

void rcp::QuotationSubscriber::runTask()
{
	logger().trace("subscriber task begin to start.....");	
	

	CMdSpi spi(_config, _pHandler);
	logger().trace("CTP api prepared....");
	spi.connect();
	logger().trace("connect to quotation server....");

	logger().information("subscriber is stated....");
	while(state()==TASK_RUNNING)
	{
		logger().trace("quotation subscriber running....");
		sleep(5000);
	}
	logger().warning("quotation subscriber was shutdown....");
	spi.release();
	spi.join();
	logger().information("quotation subscriber shutdown safely....");
}


Logger& rcp::QuotationSubscriber::logger()
{
	if(!_pLogger) _pLogger =& Logger::get("subscriber");
	return  *_pLogger;
}
