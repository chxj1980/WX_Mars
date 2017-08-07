#pragma once
#include "PSCoreCallBack.h"

// client ���ʵĳ�����;
class CPSCore
{
public:
	CPSCore() {};
	virtual ~CPSCore() {};

	// ��ʼ��;
	virtual bool Init() = 0;
	// ����ʼ��;
	virtual bool UnInit() = 0;

};

class PSCORE_API CPSCoreFactory
{
public:
	// ����ʱ,��Ҫ���ݻص��ӿ�;
	static void CreateInstance(CPSCoreCallBack* pCallBack);

	// ��ȡ m_pInstance;
	static CPSCore* GetInstance();

	// �ͷ� m_pInstance;
	static void ReleaseInstance();

private:
	static CPSCore* m_pInstance;
};

#define AfxGetPSCore	CPSCoreFactory::GetInstance