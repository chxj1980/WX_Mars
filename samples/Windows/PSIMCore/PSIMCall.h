#pragma once
#include "PSIMCallBack.h"

// �ն�SDK ���ʵĳ�����;
class CPSIMCall
{
public:
	CPSIMCall() {};
	virtual ~CPSIMCall() {};

	// ��ʼ��;
	virtual bool Init() = 0;
	// ����ʼ��;
	virtual bool UnInit() = 0;

	// ��¼
	virtual void MsgLogin(const char* strAppID, const char* strAppToken, const char* strUserID, const char* strUserName, const char* strDeviceToken) = 0;
	// ע��
	virtual void MsgLogout() = 0;
};

class CPSIMCallFactory
{
public:
	// ����ʱ,��Ҫ���ݻص��ӿ�;
	static void CreateInstance(CPSIMCallBack* pCallBack);

	// ��ȡ m_pInstance;
	static CPSIMCall* GetInstance();

	static const char* GetPSIMVersion();

	// �ͷ� m_pInstance;
	static void ReleaseInstance();

private:
	static CPSIMCall* m_pInstance;
};

#define AfxGetPSIMCall	CPSIMCallFactory::GetInstance