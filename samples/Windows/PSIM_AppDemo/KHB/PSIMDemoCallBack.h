#pragma once
#include <stdio.h>
#include "PSIMCall.h"

class CPSIMDemoCallBack : public CPSIMCallBack
{
public:
	CPSIMDemoCallBack();
	~CPSIMDemoCallBack();

	// ��¼-�ص�����;
	virtual void OnMsgLoginResponse(const PSResp& resp) {};
	// ע��-�ص�����;
	virtual void OnMsgLogoutResponse(const PSResp& resp) {};
	// ��������-�ص�����;
	virtual void OnKickOutResponse(const PSResp& resp) {};

	// ����Ⱥ-�ص�����;
	virtual void OnCreateGroupResponse(const PSResp& resp) {};
	// ɾ��Ⱥ-�ص�����;
	virtual void OnDeleteGroupResponse(const PSResp& resp) {};
	// �޸�Ⱥ-�ص�����;
	virtual void OnUpdateGroupResponse(const PSResp& resp) {};
	// ��ѯȺ-�ص�����;
	virtual void OnGetGroupInfoResponse(const PSGetGroupInfoResp& resp) {};

	// ��ȡȺ�Ӽ�-�ص�����;
	virtual void OnGetGroupChildrensResponse(const PSGetGroupChildrensResp& resp) {};

	// ���Ⱥ��Ա-�ص�����;
	virtual void OnAddGroupUsersResponse(const PSResp& resp) {};
	// �Ƴ�Ⱥ��Ա-�ص�����;
	virtual void OnRemoveGroupUsersResponse(const PSResp& resp) {};

	// �����Ⱥ-�ص�����;
	virtual void OnAddGroupChildsResponse(const PSResp& resp);
	// �Ƴ���Ⱥ-�ص�����;
	virtual void OnRemoveGroupChildsResponse(const PSResp& resp);

	// ������Ϣ-�ص�����;
	virtual void OnSendMsgResponse(const PSSendMsgResp& msgResp) {};

	// ��ȡ������Ϣ-�ص�����;
	virtual void OnGetOffMsgsResponse(const PSOffMsgResp& resp) {};

	// ������Ϣ-�ص�����;
	virtual void OnRecvMessageResponse(const PSMessageItem& resp) {};

	// ����������Ϣ����-�ص�����;
	virtual void OnRecvOffMsgNoticeResponse(const PSOffMsgDescResp& resp) {};
};