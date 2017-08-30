#pragma once
#include "PSDefs.h"

class CPSIMCallBack
{
public:
	CPSIMCallBack() {};
	virtual ~CPSIMCallBack() {};

	// ��¼-�ص�����;
	virtual void OnMsgLoginResponse(const PSMsgLoginResp& resp) = 0;
	// ע��-�ص�����;
	virtual void OnMsgLogoutResponse(const PSMsgLoginResp& resp) = 0;
	// �����߳�-�ص�����;
	virtual void OnKickOutResponse(const PSKickOutResp& resp) = 0;

	// ����Ⱥ-�ص�����;
	virtual void OnCreateGroupResponse(const PSCreateGroupResp& resp) = 0;
	// ɾ��Ⱥ-�ص�����;
	virtual void OnDeleteGroupResponse(const PSDeleteGroupResp& resp) = 0;

	// ���Ⱥ��Ա-�ص�����;
	virtual void OnAddGroupUsersResponse(const PSAddGroupUsersResp& resp) = 0;
	// �Ƴ�Ⱥ��Ա-�ص�����;
	virtual void OnRemoveGroupUsersResponse(const PSRemoveGroupUsersResp& resp) = 0;

	// �����Ⱥ-�ص�����;
	virtual void OnAddGroupChildsResponse(const PSAddGroupChildsResp& resp) = 0;
	// �Ƴ���Ⱥ-�ص�����;
	virtual void OnRemoveGroupChildsResponse(const PSRemoveGroupChildsResp& resp) = 0;

	// ������Ϣ-�ص�����;
	virtual void OnSendMsgResponse(const PSSendMsgResp& respMsg) = 0;

	// ��ȡ������Ϣ-�ص�����;
	virtual void OnGetOffMsgResponse(const PSOffMsgResp& resp) = 0;

	// ������Ϣ-�ص�����;
	virtual void OnRecvMessageResponse(const PSMessageItem& resp) = 0;

	// ����������Ϣ����-�ص�����;
	virtual void OnRecvOffMsgNoticeResponse(const PSOffMsgInfoNotice& resp) = 0;
};