#pragma once
#include "PSIMCall.h"

class CPSIMDemoCallBack: public CPSIMCallBack
{
public:
	CPSIMDemoCallBack();
	~CPSIMDemoCallBack();

	// ��¼-�ص�����;
	virtual void OnLoginResponse(const int& iCode, const char* strInfo);

	// ������Ϣ-�ص�����;
	virtual void OnSendMsgResponse(const int& iCode, const char* strInfo);

	// ��ȡ������Ϣ-�ص�����;
	virtual void OnGetOffMsgResponse(const int& iCode, const char* strInfo);
};