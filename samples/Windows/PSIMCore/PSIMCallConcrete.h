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
	virtual void MsgLogin(IN const char* strAppID,
		IN const char* strAppToken,
		IN const char* strUserID,
		IN const char* strUserName,
		IN const char* strDeviceToken);

	// ע��
	virtual void MsgLogout();

	// ��ȡȺ��Ϣ;
	virtual void GetGroupInfo(const char* strGroupID);

	// ��ȡȺ��Ա;
	virtual void GetGroupUsers(const char* strGroupID, const int iPageNum, const int iPageSize);
	// ���Ⱥ��Ա;
	virtual void AddGroupUsers(const char* strGroupID);
	// ���Ⱥ��Ա;
	virtual void DeleteGroupUsers(const char* strGroupID);

	// ����Ⱥ��Ա��ɫ
	virtual void SetGroupUserRole(const char* strGroupID);

	// ����
	virtual void Shutup(const char* strGroupID);
	// ���
	virtual void UnShutup(const char* strGroupID);
	// ��ȡ�����б�
	virtual void GetShutupList(const char* strGroupID);

	// ����Ⱥ��Ա
	virtual void InviteGroupUsers(const char* strGroupID);

	// �����ı���Ϣ
	virtual void SendTextMessage(OUT int& iReqID,
		IN const PS_SendMode& eSendMode,
		IN const char* strFrom,
		IN const char* strTo,
		IN const char* strContent,
		IN const int& iContentLen,
		IN const char* strPushInfo);

	// ��ȡ������Ϣ
	virtual void GetOfflineMsgs(OUT PS_OffMsgDesc_t* pOffMsgDescs,
		IN const int& iDescCount);

	// ��Ϣ����
	virtual void RevokeMsg();

private:
	// Core Back
	CPSIMCallBack*	m_pPSIMCallBack;
};

