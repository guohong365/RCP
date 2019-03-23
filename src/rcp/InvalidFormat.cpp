#include "InvalidFormat.h"


rcp::InvalidFormat::InvalidFormat()
	:exception("Format Error.")
{
}

rcp::InvalidFormat::InvalidFormat(const char* what_)
	:exception(what_)
{
}


rcp::InvalidFormat::~InvalidFormat()
{
}
