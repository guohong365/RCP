#ifndef _RPC_API_HEADER_
#define _RPC_API_HEADER_

#ifdef WIN32

#endif
#endif


typedef int (_stdcall *ON_INITIALIZE_CALLBACK)();
typedef void  (_stdcall *ON_TICK_CALLBACK)(void *);
typedef void  (_stdcall *ON_UNINITIALIZE_CALLBACK)();