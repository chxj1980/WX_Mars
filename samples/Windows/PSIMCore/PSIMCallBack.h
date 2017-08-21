#pragma once
#include "PSDefs.h"

class CPSIMCallBack
{
public:
	CPSIMCallBack() {};
	virtual ~CPSIMCallBack() {};

	// �߳�-�ص�����;
	//virtual void OnKickOut(const int& iCode, const char* strInfo) = 0;

	// ��¼-�ص�����;
	virtual void OnLoginResponse(const int& iCode, const char* strInfo) = 0;

	// ������Ϣ-�ص�����;
	virtual void OnSendMsgResponse(const PSMsgResp& respMsg) = 0;

	// ��ȡ������Ϣ-�ص�����;
	virtual void OnGetOffMsgResponse(const int& iCode, const char* strInfo) = 0;

	virtual void OnRecvMessage(const PSMessageItem& msgItem) = 0;

	// ����Ⱥ-�ص�����;
	virtual void OnCreateGroupResponse(const CreateGroupResp& respCreateGroup) = 0;

	// ����Ⱥ-�ص�����;
	virtual void OnAddGroupUserResponse(const BaseResp& respAddGroupUser) = 0;
};