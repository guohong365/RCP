// EchoStratey.cpp : 定义 DLL 应用程序的导出函数。
//

#include <iostream>
#ifdef __GNUC__
#define __stdcall
#endif

#ifdef __cplusplus
extern "C" {
	int __stdcall onStart();
	void __stdcall onTickIn(const void * data, unsigned len);
	void __stdcall onStop();
}
#endif 

int __stdcall onStart()
{
	std::cerr << "EchoStrategy dll initialized." << std::endl;
	return 0;
}

void __stdcall onTickIn(const void * data, unsigned len)
{
	std::cerr << "EchoStrategy: onTick [" << static_cast<const char*>(data) << "]" << std::endl;
}
void __stdcall onStop()
{
	std::cerr << "EchoStrategy dll uninitialized" << std::endl;
}

