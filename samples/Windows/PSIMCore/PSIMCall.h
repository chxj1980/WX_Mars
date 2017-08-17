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
	virtual void MsgLogin(IN const char* strAppID,
		IN const char* strAppToken,
		IN const char* strUserID,
		IN const char* strUserName,
		IN const char* strDeviceToken) = 0;

	// ע��
	virtual void MsgLogout() = 0;

	//// ���Ⱥ;
	//virtual void CreateGroup() = 0;
	//// ɾ��Ⱥ;
	//virtual void DeleteGroup() = 0;
	//// �޸�Ⱥ��Ϣ;
	//virtual void UpdateGroupInfo() = 0;
	//// ��ȡȺ��Ϣ;
	//virtual void GetGroupInfo() = 0;
	//
	//// ��ȡȺ��Ա;
	//virtual void GetGroupUsers() = 0;
	//// ���Ⱥ��Ա;
	//virtual void AddGroupUsers() = 0;
	//// ɾ��Ⱥ��Ա;
	//virtual void DeleteGroupUsers(const char* strGroupID) = 0;

	//// ����Աͬ�⡢�ܾ�
	//// ����Ա����
	//// Ⱥ�����á�ȡ������Ա

	//// ����Ⱥ��Ա��ɫ
	//virtual void SetGroupUserRole() = 0;

	//// ����
	//virtual void Shutup(const char* strGroupID) = 0;
	//// ���
	//virtual void UnShutup(const char* strGroupID) = 0;
	//// ��ȡ�����б�
	//virtual void GetShutupList(const char* strGroupID) = 0;

	//// ����Ⱥ��Ա
	//virtual void InviteGroupUsers(const char* strGroupID) = 0;

	// �����ı���Ϣ
	virtual bool SendTextMessage(OUT int& iReqID,
		IN const PS_SendMode& eSendMode,
		IN const char* strFrom,
		IN const char* strTo,
		IN const char* strContent,
		IN const int& iContentLen,
		IN const char* strPushInfo) = 0;

	// ��ȡ������Ϣ
	virtual void GetOfflineMsgs(IN PS_OffMsgDesc_t* pOffMsgDescs, IN const int& iDescCount) = 0;

	// ��Ϣ����
	virtual void RevokeMsg() = 0;
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