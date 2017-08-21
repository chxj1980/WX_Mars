#pragma once
#include "MarsWrapper.h"
#include "PSIMCallBack.h"

class CPSIMTaskCallback: public MessagePush, 
	public Login_Callback, public Msg_Callback, public OffMsg_Callback, 
	public CreateGroup_Callback, public AddGroupUser_Callback
{
private:
	CPSIMTaskCallback();

public:
	~CPSIMTaskCallback();

	static CPSIMTaskCallback* GetInstance();

	static void ReleaseInstance();

protected:
	// ������Ϣ-�ص�����;
	virtual void OnRecvMessage(const PSMessageItem& msgItem);

	// ��¼-�ص�����;
	virtual void OnResponse(Login_Task* task, MessageService::LoginResp& response);

	// ������Ϣ-�ص�����;
	virtual void OnResponse(Msg_Task* task, MessageService::SendMsgResp& response);

	// ��ȡ������Ϣ-�ص�����;
	virtual void OnResponse(OffMsg_Task* task, MessageService::OfflineMsgResp& response);

	// ����Ⱥ��-�ص�����;
	virtual void OnResponse(CreateGroup_Task* task, CreateGroupResp_Json& response);

	// ���Ⱥ��Ա-�ص�����;
	virtual void OnResponse(AddGroupUser_Task* task, AddGroupUserResp_Json& response);

private:
	CPSIMCallBack* GetPSIMCallBack();

private:
	static CPSIMTaskCallback* m_pInstance;
};