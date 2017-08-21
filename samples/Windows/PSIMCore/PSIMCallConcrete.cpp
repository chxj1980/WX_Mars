#include "PSIMCallConcrete.h"
#include "PSIMTaskCallback.h"
#include "xlogger/xlogger.h"
#include "log/appender.h"

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
	// init xlog
	std::string logPath = "D://Log";	//use your log path
	std::string pubKey = "aaa";			//use you pubkey for log encrypt						 

	xlogger_SetLevel(kLevelAll);
	//xlogger_SetLevel(kLevelInfo);
	//xlogger_SetLevel(kLevelWarn);
	appender_set_console_log(true);
	appender_open(kAppednerAsync, logPath.c_str(), "Test", pubKey.c_str());

	MarsWrapper::GetInstance().Start();
	MarsWrapper::GetInstance().SetMsgPushObserver(CPSIMTaskCallback::GetInstance());

	return true;
}

// ����ʼ��;
bool CPSIMCallConcrete::UnInit()
{
	CPSIMTaskCallback::ReleaseInstance();

	// uninit xlog
	appender_close();

	return true;
}

// ��¼
void CPSIMCallConcrete::MsgLogin(IN const char* strAppID,
	IN const char* strAppToken,
	IN const char* strUserID,
	IN const char* strUserName,
	IN const char* strDeviceToken)
{
	int iDeviceType = PS_DeviceType_Windows;
	MarsWrapper::GetInstance().MsgLogin(strAppID, strAppToken, strUserID, strUserName, iDeviceType, strDeviceToken, CPSIMTaskCallback::GetInstance());
}

// ע��
void CPSIMCallConcrete::MsgLogout()
{
	MarsWrapper::GetInstance().MsgLogout();
}

// ����Ⱥ��
bool CPSIMCallConcrete::CreateGroup(const PSGroupInfo& groupInfo)
{
	return MarsWrapper::GetInstance().CreateGroup(groupInfo, CPSIMTaskCallback::GetInstance());
}

// ��ȡȺ��Ա;
void CPSIMCallConcrete::GetGroupUsers(const char* strGroupID, const int iPageNum, const int iPageSize)
{

}

// ���Ⱥ��Ա;
bool CPSIMCallConcrete::AddGroupUsers(IN const char* strGroupID, IN const PSUserInfo* pUsers, IN const int iAddCount)
{
	return MarsWrapper::GetInstance().AddGroupUsers(strGroupID, pUsers, iAddCount, CPSIMTaskCallback::GetInstance());
}

// ���Ⱥ��Ա;
void CPSIMCallConcrete::DeleteGroupUsers(const char* strGroupID)
{

}

// ����Ⱥ��Ա��ɫ
void CPSIMCallConcrete::SetGroupUserRole(const char* strGroupID)
{

}

// ����
void CPSIMCallConcrete::Shutup(const char* strGroupID)
{

}

// ���
void CPSIMCallConcrete::UnShutup(const char* strGroupID)
{

}

// ��ȡ�����б�
void CPSIMCallConcrete::GetShutupList(const char* strGroupID)
{

}

// ����Ⱥ��Ա
void CPSIMCallConcrete::InviteGroupUsers(const char* strGroupID)
{

}

// �����ı���Ϣ
bool CPSIMCallConcrete::SendTextMessage(OUT int& iReqID,
	IN const PS_SendMode& eSendMode,
	IN const char* strFrom,
	IN const char* strTo,
	IN const char* strContent,
	IN const int& iContentLen,
	IN const char* strPushInfo)
{
	return MarsWrapper::GetInstance().SendTextMessage(iReqID, eSendMode, strFrom, strTo, strContent, iContentLen, strPushInfo, CPSIMTaskCallback::GetInstance());
}

// ��ȡ������Ϣ
void CPSIMCallConcrete::GetOfflineMsgs(OUT PSOffMsgDesc* pOffMsgDescs, IN const int & iDescCount)
{
	std::vector<PSOffMsgDesc> vecMsgDesc;
	for (int i = 0; i < iDescCount; i++)
	{
		PSOffMsgDesc OffMsgDesc;
		OffMsgDesc.strFrom = pOffMsgDescs[i].strFrom;
		OffMsgDesc.strTo = pOffMsgDescs[i].strTo;
		OffMsgDesc.iSendMode = pOffMsgDescs[i].iSendMode;
		OffMsgDesc.iStartMsgID = pOffMsgDescs[i].iStartMsgID;
		OffMsgDesc.iMsgCount = pOffMsgDescs[i].iMsgCount;
		vecMsgDesc.push_back(OffMsgDesc);
	}
	MarsWrapper::GetInstance().GetOfflineMsgs(vecMsgDesc, CPSIMTaskCallback::GetInstance());
}

// ��Ϣ����
void CPSIMCallConcrete::RevokeMsg()
{

}