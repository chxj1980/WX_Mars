#pragma once
#include "MarsWrapper.h"
#include "PSIMCallBack.h"

class CPSIMTaskCallback
	: public MessagePush
	, public Login_Callback
	, public Msg_Callback, public OffMsg_Callback
	, public CreateGroup_Callback, public DeleteGroup_Callback
	, public AddGroupUser_Callback
{
private:
	CPSIMTaskCallback();

public:
	~CPSIMTaskCallback();

	static CPSIMTaskCallback* GetInstance();

	static void ReleaseInstance();

protected:


	// ��¼-�ص�����;
	virtual void OnResponse(Login_Task* task, MessageService::LoginResp& response);

	// ������Ϣ-�ص�����;
	virtual void OnResponse(Msg_Task* task, MessageService::SendMsgResp& response);

	// ��ȡ������Ϣ-�ص�����;
	virtual void OnResponse(OffMsg_Task* task, MessageService::OfflineMsgResp& response);

	// ����Ⱥ��-�ص�����;
	virtual void OnResponse(CreateGroup_Task* task, CreateGroupResp_Json& response);

	// ɾ��Ⱥ��-�ص�����;
	virtual void OnResponse(DeleteGroup_Task* task, DeleteGroupResp_Json& response);

	// ���Ⱥ��Ա-�ص�����;
	virtual void OnResponse(AddGroupUser_Task* task, AddGroupUserResp_Json& response);

	// ��������-�ص�����;
	virtual void OnKickOut(const PSKickOutResp& response);

	// ������Ϣ-�ص�����;
	virtual void OnRecvMessage(const PSMessageItem& msgItem);

	// ����������Ϣ����-�ص�����;
	virtual void OnRecvOffMsgNotice(const PSOffMsgInfoNotice& offmsgNotice);

private:
	CPSIMCallBack* GetPSIMCallBack();

private:
	static CPSIMTaskCallback* m_pInstance;
};