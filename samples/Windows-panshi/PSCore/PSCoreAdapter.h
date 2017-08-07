#pragma once
#include "PSCore.h"
#include "PSLiveAdaptee.h"
#include "PSMsgAdaptee.h"

// �����������;
class CPSCoreAdapter: public CPSCore
{
private:
	CPSCoreAdapter();
public:
	CPSCoreAdapter(CPSCoreCallBack* pCallBack);
	virtual ~CPSCoreAdapter();

	// ��ʼ��;
	virtual bool Init();
	// ����ʼ��;
	virtual bool UnInit();

private:
	CPSLiveAdaptee*			m_pLiveAdaptee;
	CPSMsgAdaptee*			m_pMsgAdaptee;
};