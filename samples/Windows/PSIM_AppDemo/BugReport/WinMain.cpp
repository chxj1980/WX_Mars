#include "stdafx.h"
#include "resource.h"
#include "BugReportDialog.h"
#include "TStringTool.h"
#include <shellapi.h>
#include "CurlEx.h"
#include "zip.h"
#include <TlHelp32.h>

#define APP_SERVER	_T("http://log.yizhibo.tv/pc")
LPWSTR g_strDumpPath = NULL;	// �ڴ��ļ�·��;

void StringReplace(TString &strBase, TString strSrc, TString strDes)
{
	TString::size_type pos = 0;
	TString::size_type srcLen = strSrc.size();
	TString::size_type desLen = strDes.size();
	pos = strBase.find(strSrc, pos);
	while ((pos != TString::npos))
	{
		strBase.replace(pos, srcLen, strDes);
		pos = strBase.find(strSrc, (pos + desLen));
	}
}

bool KillProcess(DWORD process_id)
{
	HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, process_id);
	if (NULL == hProcess)
	{
		return false;
	}
	if (!TerminateProcess(hProcess, 0))
	{
		return false;
	}
	return true;
}

// ���ݳ��������ҳ����Ӧ�Ľ���ID;
DWORD  GetProcessIDFromName(char *pName)
{
	if (NULL == pName)
	{
		return -1;
	}

	HANDLE           hSnapshot;
	// �����ṹ��������Ž��̿�����Ϣ;
	PROCESSENTRY32   processinfo;
	processinfo.dwSize = sizeof(processinfo);

	// ���̿��ջ�ȡ�����б�;
	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (NULL == hSnapshot)
	{
		return   0;
	}

	//��Snapshot�������õĽ��̿��գ��õ���һ�����̼�¼��Ϣ
	bool bStatus = Process32First(hSnapshot, &processinfo);
	int nLen = wcslen(processinfo.szExeFile) + 1;
	char *pTemp = new char[2 * nLen + 1];
	while (bStatus)
	{
		// wchar* ת char*;
		WideCharToMultiByte(CP_ACP, 0, processinfo.szExeFile, nLen, pTemp, 2 * nLen, NULL, NULL);
		// �ҵ����ؽ���ID;
		if (0 == strcmp(pName, pTemp))
		{
			delete[]pTemp;
			CloseHandle(hSnapshot);
			return processinfo.th32ProcessID;
		}
		// ��Snapshot�������õĽ��̿��գ��õ���һ�����̼�¼��Ϣ;
		bStatus = Process32Next(hSnapshot, &processinfo);
	}

	delete[]pTemp;
	// �رս��̿��վ��;
	CloseHandle(hSnapshot);
	return   -1;
}

// ��ʾ�Ի���;
bool ShowBugReportDlg(HINSTANCE hInstance)
{
	CPaintManagerUI::SetInstance(hInstance);
#if 1
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skin\\"));
	CPaintManagerUI::SetResourceZip(_T("bugreport.zip"));
#else
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skin\\bugreport"));
#endif

	CBugReportDialog* pDialog = new CBugReportDialog();
	assert(pDialog);
	pDialog->Create(NULL, _T("���󱨸�"), UI_WNDSTYLE_FRAME, WS_EX_STATICEDGE | WS_EX_APPWINDOW, 0, 0, 0, 0);
	pDialog->CenterWindow();

	UINT uiRet = pDialog->ShowModal();
	if ((uiRet & E_SEND) && (NULL != g_strDumpPath))
	{
		TString strZipPath = g_strDumpPath;
		StringReplace(strZipPath, _T(".dmp"), _T(".zip"));

		HZIP hZip = CreateZip(strZipPath.c_str(), 0);
		if (NULL == hZip)
		{
			return false;
		}
		ZipAdd(hZip, _T("EasyLive.dmp"), g_strDumpPath);
		CloseZip(hZip);

		CCurlEx urlEx;
		urlEx.UpLoadFile(APP_SERVER, strZipPath.c_str());
	}
	if (uiRet & E_RESART)
	{
		int iProcessID = GetProcessIDFromName("KHB.exe");
		if (iProcessID > 0)
		{
			// �����ڣ���ɱ����������;
			KillProcess(iProcessID);
		}
		CDuiString strPath = CPaintManagerUI::GetInstancePath() + _T("KHB.exe");
		// ִ��������;
		WinExec(_T2A(strPath.GetData()).c_str(), SW_SHOWNORMAL);
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
	int numArgs = 0;
	LPWSTR *args = CommandLineToArgvW(GetCommandLineW(), &numArgs);

	bool bDisableMutex = false;
	for (int i = 1; i < numArgs; i++)
	{
		if (0 == wcscmp(args[i], _T("-dumppath")))
		{
			g_strDumpPath = args[++i];
		}
	}
	if (NULL == g_strDumpPath)
	{
		//return 0;
	}

	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr))
	{
		return 0;
	}

	ShowBugReportDlg(hInstance);

	::CoUninitialize();
	return 0;
}