#pragma once
#include <iostream>
namespace  rcp {
	class RCP_API Dumpable
	{
	public:
		virtual const std::string& prefix() { return ""; };
		virtual void dump(std::ostream & output) = 0;
		virtual ~Dumpable() = default;
	};
}

