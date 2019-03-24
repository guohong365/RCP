#pragma once
#include <exception>
#include "../include/rcp.h"
namespace rcp {
	class InvalidFormat : public std::exception
	{
	public:
		InvalidFormat();
		explicit InvalidFormat(const char * what_);
		~InvalidFormat();
	};
}

