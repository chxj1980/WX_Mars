#pragma once
#include "PSCoreCallBack.h"

class CPSMsgAdaptee
{
public:
	CPSMsgAdaptee();
	CPSMsgAdaptee(CPSCoreCallBack*	pCallBack);
	~CPSMsgAdaptee();

	// ��ʼ��;
	bool Init();
	// ����ʼ��;
	bool UnInit();

private:
	CPSCoreCallBack*	m_pCallBack;
};