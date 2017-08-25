#pragma once
#include "PSIMCall.h"

class CPSIMDemoCallBack : public CPSIMCallBack
{
public:
	CPSIMDemoCallBack();
	~CPSIMDemoCallBack();

	// ��¼-�ص�����;
	virtual void OnMsgLoginResponse(const PSMsgLoginResp& respMsgLogin);
	// ע��-�ص�����;
	virtual void OnMsgLogoutResponse(const PSMsgLoginResp& respMsgLogout);
	// �����߳�-�ص�����;
	virtual void OnKickOutResponse(const PSKickOutResp& respKickOut);

	// ����Ⱥ-�ص�����;
	virtual void OnCreateGroupResponse(const PSCreateGroupResp& respCreateGroup);
	// ɾ��Ⱥ-�ص�����;
	virtual void OnDeleteGroupResponse(const PSDeleteGroupResp& respDeleteeGroup);

	// ���Ⱥ��Ա-�ص�����;
	virtual void OnAddGroupUsersResponse(const PSAddGroupUsersResp& respAddGroupUsers);
	// �Ƴ�Ⱥ��Ա-�ص�����;
	virtual void OnRemoveGroupUsersResponse(const PSRemoveGroupUsersResp& respRemoveGroupUsers);

	// �����Ⱥ-�ص�����;
	virtual void OnAddGroupChildsResponse(const PSAddGroupChildsResp& respAddGroupChilds);
	// �Ƴ���Ⱥ-�ص�����;
	virtual void OnRemoveGroupChildsResponse(const PSRemoveGroupChildsResp& respRemoveGroupChilds);

	// ������Ϣ-�ص�����;
	virtual void OnSendMsgResponse(const PSMsgResp& msgResp);

	// ��ȡ������Ϣ-�ص�����;
	virtual void OnGetOffMsgResponse(const int& iCode, const char* strInfo);

	virtual void OnRecvMessage(const PSMessageItem& msgItem);
};