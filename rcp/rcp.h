#ifndef _RPC_H_
#define _RPC_H_

#ifdef WIN32
#ifdef RCP_EXPORTS
#define RCP_API __declspec(dllexport)
#else
#define RCP_API __declspec(dllimport)
#endif
#endif


#endif

