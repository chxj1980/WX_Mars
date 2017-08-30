#pragma once
#include "PSIMCall.h"

class CPSIMDemoCallBack : public CPSIMCallBack
{
public:
	CPSIMDemoCallBack();
	~CPSIMDemoCallBack();

	// ��¼-�ص�����;
	virtual void OnMsgLoginResponse(const PSMsgLoginResp& resp);
	// ע��-�ص�����;
	virtual void OnMsgLogoutResponse(const PSMsgLoginResp& resp);
	// ��������-�ص�����;
	virtual void OnKickOutResponse(const PSKickOutResp& resp);

	// ����Ⱥ-�ص�����;
	virtual void OnCreateGroupResponse(const PSCreateGroupResp& resp);
	// ɾ��Ⱥ-�ص�����;
	virtual void OnDeleteGroupResponse(const PSDeleteGroupResp& resp);

	// ���Ⱥ��Ա-�ص�����;
	virtual void OnAddGroupUsersResponse(const PSAddGroupUsersResp& resp);
	// �Ƴ�Ⱥ��Ա-�ص�����;
	virtual void OnRemoveGroupUsersResponse(const PSRemoveGroupUsersResp& resp);

	// �����Ⱥ-�ص�����;
	virtual void OnAddGroupChildsResponse(const PSAddGroupChildsResp& resp);
	// �Ƴ���Ⱥ-�ص�����;
	virtual void OnRemoveGroupChildsResponse(const PSRemoveGroupChildsResp& resp);

	// ������Ϣ-�ص�����;
	virtual void OnSendMsgResponse(const PSSendMsgResp& msgResp);

	// ��ȡ������Ϣ-�ص�����;
	virtual void OnGetOffMsgResponse(const PSOffMsgResp& resp);

	// ������Ϣ-�ص�����;
	virtual void OnRecvMessageResponse(const PSMessageItem& resp);

	// ����������Ϣ����-�ص�����;
	virtual void OnRecvOffMsgNoticeResponse(const PSOffMsgInfoNotice& resp);
};