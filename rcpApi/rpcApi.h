#ifndef _RPC_API_HEADER_
#define _RPC_API_HEADER_

#ifdef WIN32

#ifdef RCPAPI_EXPORTS
#define RPC_API __declspec(dllexport)
#else
#define RPC_API __declspec(dllimport)
#endif
#endif

#endif


