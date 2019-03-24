// strategy1.cpp : 定义 DLL 应用程序的导出函数。
//

#include <iostream>
#ifdef __GNUC__
#define __stdcall
#endif
#ifdef __cplusplus
extern "C" {
	int __stdcall onInitialize();
	void __stdcall onTick(const void * data, unsigned len);
	void __stdcall onUninitialize();
}
#endif 

int __stdcall onInitialize()
{
	std::cerr << "strategy 1 dll initialized." << std::endl;
	return 0;
}
static unsigned long count=0;
void __stdcall onTick(const void * data, unsigned len)
{
	std::cerr << "strategy1 : onTick ["<< count++ << "]" << std::endl;
}
void __stdcall onUninitialize()
{
	std::cerr << "strategy 1 dll uninitialized" << std::endl;
}

