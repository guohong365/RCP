#ifndef __RCP_H__
#define __RCP_H__
#include <string>

#ifdef WIN32
#ifdef RCP_EXPORTS
#define RCP_API __declspec(dllexport)
#else
#define RCP_API __declspec(dllimport)
#endif
#else
#define RCP_API

#endif

#define RCP_VERSION "0.0.1"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <string>

#endif

