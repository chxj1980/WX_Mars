#include "PSMsgAdaptee.h"

CPSMsgAdaptee::CPSMsgAdaptee()
{
	m_pCallBack = nullptr;
}

CPSMsgAdaptee::CPSMsgAdaptee(CPSCoreCallBack*	pCallBack)
{
	m_pCallBack = pCallBack;
}

CPSMsgAdaptee::~CPSMsgAdaptee()
{
}

// ��ʼ��;
bool CPSMsgAdaptee::Init()
{
	return true;
}

// ����ʼ��;
bool CPSMsgAdaptee::UnInit()
{
	return true;
}