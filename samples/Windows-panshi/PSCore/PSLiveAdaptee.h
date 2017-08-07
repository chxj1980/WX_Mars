#pragma once
#include "PSCoreCallBack.h"

class CPSLiveAdaptee
{
public:
	CPSLiveAdaptee();
	CPSLiveAdaptee(CPSCoreCallBack*	pCallBack);
	~CPSLiveAdaptee();

	// ��ʼ��;
	bool Init();
	// ����ʼ��;
	bool UnInit();

private:
	CPSCoreCallBack*	m_pCallBack;
};

