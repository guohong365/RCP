#pragma once
#include <rcp.h>
#include "TradeStrategy.h"

namespace rcp {
	class RCP_API DllTradeStrategy : public AbstractTradeStrategy
	{
	public:
		DllTradeStrategy();
		~DllTradeStrategy();
		const std::string&  initMethod()const;
		void initMethod(const std::string&  initMethod);
		const std::string&  onTickMethod() const;
		void onTickMethod(const std::string&  value);
		const std::string& uninitMethod() const;
		void uninitMethod(const std::string&  uninitMethod);
		bool checkValid() override;
	private:
		std::string _initMethod;
		std::string _onTickMethod;
		std::string _uninitMethod;
	};
}

