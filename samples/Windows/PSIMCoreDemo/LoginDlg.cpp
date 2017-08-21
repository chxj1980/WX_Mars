// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSIMCoreDemo.h"
#include "LoginDlg.h"
#include "afxdialogex.h"

#define LOGIN_RESP	(WM_USER + 100)

HWND g_hwndLogin;

// CLoginDlg �Ի���
IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_LOGIN, pParent)
{
}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_APPNAME, m_edtAppName);
	DDX_Control(pDX, IDC_EDIT_APPTOKEN, m_edtAppToken);
	DDX_Control(pDX, IDC_EDIT_USERID, m_edtUserID);
	DDX_Control(pDX, IDC_EDIT_USERNAME, m_edtUserName);
	DDX_Control(pDX, IDC_EDIT_DEVICETOKEN, m_edtDeviceToken);
}

BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	g_hwndLogin = m_hWnd;

	m_edtAppName.SetWindowText(_T("xes"));
	m_edtAppToken.SetWindowText(_T("token"));
	m_edtUserID.SetWindowText(_T("3"));
	m_edtUserName.SetWindowText(_T("zhang"));
	m_edtDeviceToken.SetWindowText(_T("windowstoken"));

	return 0;
}

BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CLoginDlg::OnBnClickedLogin)
END_MESSAGE_MAP()

// CLoginDlg ��Ϣ�������
void CLoginDlg::OnBnClickedLogin()
{
	CString strAppName, strAppToken, strUserID, strUserName, strDeviceToken;
	m_edtAppName.GetWindowText(strAppName);
	m_edtAppToken.GetWindowText(strAppToken);
	m_edtUserID.GetWindowText(strUserID);
	m_edtUserName.GetWindowText(strUserName);
	m_edtDeviceToken.GetWindowText(strDeviceToken);

	theApp.m_strAppID = CT2CA(strAppName);
	theApp.m_strUserID = CT2CA(strUserID);
	AfxGetPSIMCall()->MsgLogin(CT2CA(strAppName), CT2CA(strAppToken), CT2CA(strUserID), CT2CA(strUserName), CT2CA(strDeviceToken));
}

LRESULT CLoginDlg::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case LOGIN_RESP:
		{
			int* pCode = (int*)wParam;
			char* pInfo = (char*)lParam;
			if ( 0 == *pCode)
			{
				EndDialog(IDOK);
			}
			else
			{
				CString strInfo = CA2CT(pInfo);
				MessageBox(strInfo, _T("��ʾ"), MB_OK);
			}
		}
		break;
	default:
		break;
	}
	return CDialogEx::DefWindowProc(message, wParam, lParam);
}

void CPSIMDemoCallBack::OnLoginResponse(const int& iCode, const char* strInfo)
{
	printf("CPSIMDemoCallBack::OnLoginResponse: iCode(%d), strInfo(%s) \n", iCode, strInfo);

	::SendMessage(g_hwndLogin, LOGIN_RESP, (WPARAM)&iCode, (LPARAM)strInfo);
}