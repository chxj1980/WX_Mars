#pragma once
#include "PSDefs.h"

class CPSIMCallBack
{
public:
	CPSIMCallBack() {};
	virtual ~CPSIMCallBack() {};

	// ��¼-�ص�����;
	virtual void OnMsgLoginResponse(const PSMsgLoginResp& respMsgLogin) = 0;
	// ע��-�ص�����;
	virtual void OnMsgLogoutResponse(const PSMsgLoginResp& respMsgLogout) = 0;
	// �����߳�-�ص�����;
	virtual void OnKickOutResponse(const PSKickOutResp& respKickOut) = 0;

	// ����Ⱥ-�ص�����;
	virtual void OnCreateGroupResponse(const PSCreateGroupResp& respCreateGroup) = 0;
	// ɾ��Ⱥ-�ص�����;
	virtual void OnDeleteGroupResponse(const PSDeleteGroupResp& respDeleteeGroup) = 0;

	// ���Ⱥ��Ա-�ص�����;
	virtual void OnAddGroupUsersResponse(const PSAddGroupUsersResp& respAddGroupUsers) = 0;
	// �Ƴ�Ⱥ��Ա-�ص�����;
	virtual void OnRemoveGroupUsersResponse(const PSRemoveGroupUsersResp& respRemoveGroupUsers) = 0;

	// �����Ⱥ-�ص�����;
	virtual void OnAddGroupChildsResponse(const PSAddGroupChildsResp& respAddGroupChilds) = 0;
	// �Ƴ���Ⱥ-�ص�����;
	virtual void OnRemoveGroupChildsResponse(const PSRemoveGroupChildsResp& respRemoveGroupChilds) = 0;

	// ������Ϣ-�ص�����;
	virtual void OnSendMsgResponse(const PSMsgResp& respMsg) = 0;

	// ��ȡ������Ϣ-�ص�����;
	virtual void OnGetOffMsgResponse(const int& iCode, const char* strInfo) = 0;

	virtual void OnRecvMessage(const PSMessageItem& msgItem) = 0;
};