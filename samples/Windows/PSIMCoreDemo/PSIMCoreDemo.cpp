
// PSIMCoreDemo.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "PSIMCoreDemo.h"
#include "PSIMCoreDemoDlg.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPSIMCoreDemoApp

BEGIN_MESSAGE_MAP(CPSIMCoreDemoApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CPSIMCoreDemoApp ����

CPSIMCoreDemoApp::CPSIMCoreDemoApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	m_pCallBack = NULL;
}


// Ψһ��һ�� CPSIMCoreDemoApp ����

CPSIMCoreDemoApp theApp;


// CPSIMCoreDemoApp ��ʼ��

BOOL CPSIMCoreDemoApp::InitInstance()
{
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxInitRichEdit2();
	AfxEnableControlContainer();

	CShellManager *pShellManager = new CShellManager;
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	m_pCallBack = new CPSIMDemoCallBack();
	CPSIMCallFactory::CreateInstance(m_pCallBack);
	AfxGetPSIMCall()->Init();

	CLoginDlg dlgLogin;
	INT_PTR iRes = dlgLogin.DoModal();
	if (iRes == IDOK)
	{
		CPSIMCoreDemoDlg dlg;
		m_pMainWnd = &dlg;
		INT_PTR nResponse = dlg.DoModal();
		if (nResponse == IDOK)
		{
			// TODO: �ڴ˷��ô����ʱ��
			//  ��ȷ�������رնԻ���Ĵ���
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO: �ڴ˷��ô����ʱ��
			//  ��ȡ�������رնԻ���Ĵ���
		}
		else if (nResponse == -1)
		{
			TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
			TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
		}
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	return FALSE;
}

int CPSIMCoreDemoApp::ExitInstance()
{
	AfxGetPSIMCall()->UnInit();
	CPSIMCallFactory::ReleaseInstance();

	if (m_pCallBack)
	{
		delete m_pCallBack;
		m_pCallBack = NULL;
	}

	return CWinApp::ExitInstance();
}