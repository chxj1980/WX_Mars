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
	virtual void OnSendMsgResponse(const int& iCode, const char* strInfo) = 0;

	// ��ȡ������Ϣ-�ص�����;
	virtual void OnGetOffMsgResponse(const int& iCode, const char* strInfo) = 0;

	virtual void OnRecvMessage(const MessageItem& msgItem) = 0;
};