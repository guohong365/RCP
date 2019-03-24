#pragma once
#include "Quotation.h"
namespace rcp {

	class IQuotationHandler
	{
	public:
		virtual ~IQuotationHandler() = default;
		virtual void onQuotation(const IQuotation * pQuotation) = 0;
	};
}
