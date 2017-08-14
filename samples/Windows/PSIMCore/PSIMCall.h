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

	//// ��ȡȺ��Ϣ;
	//virtual void GetGroupInfo(const char* strGroupID) = 0;
	//
	//// ��ȡȺ��Ա;
	//virtual void GetGroupUsers(const char* strGroupID, const int iPageNum, const int iPageSize) = 0;
	//// ���Ⱥ��Ա;
	//virtual void AddGroupUsers(const char* strGroupID) = 0;
	//// ���Ⱥ��Ա;
	//virtual void DeleteGroupUsers(const char* strGroupID) = 0;

	//// ����Ⱥ��Ա��ɫ
	//virtual void SetGroupUserRole(const char* strGroupID) = 0;

	//// ����
	//virtual void Shutup(const char* strGroupID) = 0;
	//// ���
	//virtual void UnShutup(const char* strGroupID) = 0;
	//// ��ȡ�����б�
	//virtual void GetShutupList(const char* strGroupID) = 0;

	//// ����Ⱥ��Ա
	//virtual void InviteGroupUsers(const char* strGroupID) = 0;
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