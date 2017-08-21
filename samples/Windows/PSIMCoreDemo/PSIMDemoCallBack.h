#pragma once
#include "PSIMCall.h"

class CPSIMDemoCallBack : public CPSIMCallBack
{
public:
	CPSIMDemoCallBack();
	~CPSIMDemoCallBack();

	// ��¼-�ص�����;
	virtual void OnLoginResponse(const int& iCode, const char* strInfo);

	// ������Ϣ-�ص�����;
	virtual void OnSendMsgResponse(const PSMsgResp& msgResp);

	// ��ȡ������Ϣ-�ص�����;
	virtual void OnGetOffMsgResponse(const int& iCode, const char* strInfo);

	virtual void OnRecvMessage(const PSMessageItem& msgItem);

	// ����Ⱥ-�ص�����;
	virtual void OnCreateGroupResponse(const CreateGroupResp& respCreateGroup);

	// ����Ⱥ-�ص�����;
	virtual void OnAddGroupUserResponse(const BaseResp& respAddGroupUser);
};