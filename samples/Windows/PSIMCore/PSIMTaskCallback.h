#pragma once
#include "MarsWrapper.h"
#include "PSIMCallBack.h"

class CPSIMTaskCallback: public Login_Callback, public Msg_Callback, public OffMsg_Callback
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

private:
	CPSIMCallBack* GetPSIMCallBack();

private:
	static CPSIMTaskCallback* m_pInstance;
};