
#include "stdafx.h"
#include "resource.h"
#include "UpdateDialog.h"
#include "MyVersion.h"
#include <UrlMon.h>
#include <atlconv.h>
#pragma comment(lib, "urlmon.lib")
#include "TstringTool.h"
#include <direct.h>
#include <fstream>
#include "CurlEx.h"

// ���汾,���°汾����true;
bool CheckVersion(TString& strUpdateUrl, TString& strUpdateVersion)
{
	char  szFileDesc[128];
	char  szProductVersion[32];
	CMyVersion::GetFileDescriptionAndProductVersionA(".\\KHB.exe", szFileDesc, 128, szProductVersion, 32);
	CMyVersion oldVersion(szProductVersion);
	
	// ���ȴ���DownLoad�ļ���;
	_mkdir(".\\DownLoad");
	CCurlEx curlEx;
	TCHAR chCurDir[MAX_PATH] = { 0 };
	GetCurrentDirectory(MAX_PATH, chCurDir);
	TString strCur(chCurDir);

	if (g_strVersionUrl.empty())
	{
		LPWSTR str = new WCHAR[1024];
		//GetPrivateProfileString(_T("URL"), _T("UpdateURL"), _T("http://update.yizhibo.tv/anchor-pc"), str, 1024, _T(".\\Config\\server.ini"));
		//g_strVersionUrl = TString(str);
		g_strVersionUrl = _T("");
		delete []str;
		str = NULL;
	}

	if (curlEx.DownLoadFile(g_strVersionUrl.c_str(), strCur + _T(".\\DownLoad\\version.xml")))
	{
		CMarkup markUp;
		markUp.LoadFromPath(_T(".\\DownLoad\\version.xml"), XMLFILE_ENCODING_ASNI);
		CMarkupNode noteRoot = markUp.GetRoot();

		//LPCTSTR lpInfo = noteRoot.GetAttributeValue(_T("Info"));
		strUpdateUrl = noteRoot.GetAttributeValue(_T("Url"));
		strUpdateVersion = noteRoot.GetAttributeValue(_T("Version"));

		CMyVersion newVersion(_T2A(strUpdateVersion).c_str());
		int iRes = oldVersion.Compare(newVersion); 
		if (iRes < 0)
		{
			return true;
		}
	}

	return false;
}

// ���°汾,����������������;
bool DownFile(TString strUpdateUrl, TString& strUpdateVersion)
{
	TString strPath = _T(".\\DownLoad\\");
	strPath = strPath + _T("Update_Version_") + strUpdateVersion + _T(".exe");

	fstream fsFile;
	fsFile.open(strPath, ios::in);
	if (fsFile)
	{
		fsFile.close();
	}
	else
	{
		CCurlEx curlEx;
		if (!curlEx.DownLoadFile(strUpdateUrl, strPath))
		{
			AflMessageBox(NULL, _T("���ᱦ��������������ʧ��"));
			return false;
		}
	}

	// ִ��������;
	WinExec(_T2A(strPath).c_str(), SW_SHOWNORMAL);
	return true;
}

// ���°汾,��ʾ�Ի���;
bool ShowUpdateDlg(HINSTANCE hInstance)
{
	CPaintManagerUI::SetInstance(hInstance);
#if 1
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skin\\"));
	CPaintManagerUI::SetResourceZip(_T("update.zip"));
#else
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skin\\update"));
#endif

	CUpdateDialog* pDialog = new CUpdateDialog();
	assert(pDialog);
	pDialog->Create(NULL, LIVE_UPDATE_NAME, UI_WNDSTYLE_FRAME, WS_EX_STATICEDGE | WS_EX_APPWINDOW, 0, 0, 0, 0);
	pDialog->CenterWindow();

	UINT uiRet = pDialog->ShowModal();
	if (uiRet == IDOK)
	{
	}

	// �����˳�;
	PostQuitMessage(0);
	CPaintManagerUI::MessageLoop();

	return true;
}

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr))
	{
		return 0;
	}

	TString strUpdateUrl;
	TString strUpdateVersion;
	if (CheckVersion(strUpdateUrl, strUpdateVersion))
	{
		DownFile(strUpdateUrl, strUpdateVersion);
	}
	else
	{
		ShowUpdateDlg(hInstance);
	}

	::CoUninitialize();
	return 0;
}