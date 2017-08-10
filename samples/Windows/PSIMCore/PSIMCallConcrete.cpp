#include "PSIMCallConcrete.h"
#include "PSIMTaskCallback.h"

enum DeviceType
{
	DeviceTypeIos = 1,
	DeviceTypeAndroid = 2,
	DeviceTypeWindows = 3,
	DeviceTypeOther = 6
};

CPSIMCallConcrete::CPSIMCallConcrete()
{
}

CPSIMCallConcrete::CPSIMCallConcrete(CPSIMCallBack* pPSIMCallBack)
{
	m_pPSIMCallBack = pPSIMCallBack;
}

CPSIMCallConcrete::~CPSIMCallConcrete()
{
}

CPSIMCallBack* CPSIMCallConcrete::GetIMPSCallBack()
{
	return m_pPSIMCallBack;
}

// ��ʼ��;
bool CPSIMCallConcrete::Init()
{
	MarsWrapper::GetInstance().Start();

	return true;
}

// ����ʼ��;
bool CPSIMCallConcrete::UnInit()
{
	CPSIMTaskCallback::ReleaseInstance();

	return true;
}

// ��¼
void CPSIMCallConcrete::MsgLogin(const char* strAppID, const char* strAppToken, const char* strUserID, const char* strUserName, const char* strDeviceToken)
{
	int iDeviceType = DeviceType::DeviceTypeWindows;
	MarsWrapper::GetInstance().MsgLogin(strAppID, strAppToken, strUserID, strUserName, iDeviceType, strDeviceToken, CPSIMTaskCallback::GetInstance());
}

// ע��
void CPSIMCallConcrete::MsgLogout()
{

}