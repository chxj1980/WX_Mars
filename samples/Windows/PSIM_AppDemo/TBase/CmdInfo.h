#pragma once
#include <windows.h>
#include <list>
#include "TString\TString.h"
#include "LiveLockEx.h"
#include "CurlEx.h"
#include "JsonValueEx.h"
#include <memory>
#include "TBaseExport.h"

class TBASE_API CmdInfo
{
public:
	CmdInfo()
	{
		strCmd = _T("");
		strUrl = _T("");
		strPara = _T("");
		bVerifyRes = true;
		vecHeader.clear();

		iDelay = 0;
		bSucess = true;
		iErrorCode = 0;
		strError = _T("");
		jsResult.clear();
		hCallBackWnd = NULL;
	}
	CmdInfo(const CmdInfo& other) :strCmd(other.strCmd), strUrl(other.strUrl), strPara(other.strPara), bVerifyRes(other.bVerifyRes), vecHeader(other.vecHeader), bSucess(other.bSucess), strError(other.strError)
	{
		jsResult = other.jsResult;
		hCallBackWnd = other.hCallBackWnd;
	}

	TString			strCmd;
	TString			strUrl;
	TString			strPara;
	bool			bVerifyRes;
	VecURLHeader	vecHeader;

	int				iDelay;
	bool			bSucess;
	int				iErrorCode;
	TString			strError;
	JsonValueEx		jsResult;
	HWND			hCallBackWnd;		// �ص�ʱ�����ھ��������Ϣ;
};

typedef void(*Curl_CallBack) (CmdInfo& pCmdInfo);

class TBASE_API CmdItem
{
public:
	CmdItem()
	{
		pFunc = NULL;
	}
	CmdItem(const CmdItem& other) :cmdInfo(other.cmdInfo), pFunc(other.pFunc)
	{
	}

	CmdInfo			cmdInfo;
	Curl_CallBack	pFunc;
};

typedef std::shared_ptr<CmdItem> CmdItemPtr;
typedef std::list<CmdItem> CmdList;				// �������;

// �������;
class TBASE_API CmdManager
{
private:
	CmdManager();
	~CmdManager();

public:
	static CmdManager* GetInstance();
	static void ReleaseInstance();

	void AddCmd(IN TString& strCmd, IN Curl_CallBack pFunc = NULL);
	void AddCmd(IN CmdItem& cmdInfo);

private:
	CmdList		m_listCmd;						// �������;
	DWORD		m_dwThreadID;
	HANDLE		m_hThCmd;						// �߳̾��;
	bool		m_bStop;						// �������;
	CLiveLockEx	m_lockList;						// �������������ͷ;

	void DeInit();

	static DWORD WINAPI Th_Cmd(LPVOID lpParam);

	static DWORD WINAPI Th_Cmd_Excute(LPVOID lpParam);

	static CmdManager*	m_pInstance;
	static CLiveLockEx	m_lockInst;
};

#define AflGetCmdManager	CmdManager::GetInstance