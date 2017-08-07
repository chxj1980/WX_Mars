#include "MarsWrapper.h"
#include "PSLiveAdaptee.h"


CPSLiveAdaptee::CPSLiveAdaptee()
{
	m_pCallBack = nullptr;
}

CPSLiveAdaptee::CPSLiveAdaptee(CPSCoreCallBack*	pCallBack)
{
	m_pCallBack = pCallBack;
}

CPSLiveAdaptee::~CPSLiveAdaptee()
{
}

// ��ʼ��;
bool CPSLiveAdaptee::Init()
{
	MarsWrapper::Instance().start();

	//MarsWrapper::Instance().setChatMsgObserver(this);

	return true;
}

// ����ʼ��;
bool CPSLiveAdaptee::UnInit()
{
	return true;
}