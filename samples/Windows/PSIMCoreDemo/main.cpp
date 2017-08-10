#include <stdio.h>
#include "PSIMDemoCallBack.h"
#include <windows.h>

int main()
{

	CPSIMDemoCallBack* pCallBack = new CPSIMDemoCallBack();
	CPSIMCallFactory::CreateInstance(pCallBack);
	AfxGetPSIMCall()->Init();

	Sleep(2 * 1000);

	AfxGetPSIMCall()->MsgLogin("xes", "token", "100001", "testname", "1111");

	Sleep(30 * 1000);

	return 1;
}