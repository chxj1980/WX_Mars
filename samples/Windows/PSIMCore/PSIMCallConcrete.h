#pragma once
#include "PSIMCall.h"

// ��ʯIMCall�ľ���ʵ��
class CPSIMCallConcrete: public CPSIMCall
{
private:
	CPSIMCallConcrete();

public:
	CPSIMCallConcrete(CPSIMCallBack* pPSIMCallBack);
	virtual ~CPSIMCallConcrete();

	CPSIMCallBack* GetIMPSCallBack();

	// ��ʼ��;
	virtual bool Init();
	// ����ʼ��;
	virtual bool UnInit();

	// ��¼
	virtual void MsgLogin(const char* strAppID, const char* strAppToken, const char* strUserID, const char* strUserName, const char* strDeviceToken);
	// ע��
	virtual void MsgLogout();

private:
	// Core Back
	CPSIMCallBack*	m_pPSIMCallBack;
};

