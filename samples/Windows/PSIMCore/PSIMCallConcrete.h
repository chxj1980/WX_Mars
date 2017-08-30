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

	// ��¼;
	virtual void MsgLogin(IN const char* strAppID,
		IN const char* strAppToken,
		IN const char* strUserID,
		IN const char* strUserName,
		IN const int iDeviceType,
		IN const char* strDeviceToken);
	// ע��;
	virtual void MsgLogout();

	// ����Ⱥ��;
	virtual void CreateGroup(IN const PSGroupInfo& groupInfo);
	// ɾ��Ⱥ;
	virtual void DeleteGroup(IN const char* strGroupID);

	// ��ȡȺ��Ա;
	//virtual void GetGroupUsers(IN const PSGroupInfo& groupUsers);
	//virtual void GetGroupUsers(const char* strGroupID, const int iPageNum, const int iPageSize);
	// ���Ⱥ��Ա;
	virtual void AddGroupUsers(IN const char* strGroupID, IN const PSUserInfo* pUsers, IN const int iAddCount);
	// �Ƴ�Ⱥ��Ա;
	virtual void RemoveGroupUsers(IN const char* strGroupID, IN const PSUserInfo* pUsers, IN const int iRemoveCount);

	// �����Ⱥ;
	virtual void AddGroupChilds(IN const char* strGroupID, IN const PSGroupInfo* pGroups, IN const int iAddCount);
	// �Ƴ���Ⱥ;
	virtual void RemoveGroupUsers(IN const char* strGroupID, IN const PSGroupInfo* pUsers, IN const int iRemoveCount);

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
		IN const PSString& strContent,
		IN const char* strPushInfo);

	// ��ȡ������Ϣ;
	virtual void GetOfflineMsgs(IN const PSVector<PSOffMsgDesc>& vecOffMsgDescs);

	// ��Ϣ����
	virtual void RevokeMsg();

private:
	// Core Back
	CPSIMCallBack*	m_pPSIMCallBack;
};

