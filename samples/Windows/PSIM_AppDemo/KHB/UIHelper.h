#pragma once
#include <wtypes.h>
#include "TSingleton.h"
#include "KHBDefs.h"
#include "LoginWnd.h"
#include "MainWnd.h"

class CUIHelper : public TSingleton<CUIHelper>
{
public:
	CUIHelper();
	~CUIHelper();

	// ��¼;
	UINT ShowLoginWnd(bool bLoginOut = false);
	HWND GetLoginHWND();

	// ������;
	UINT ShowMainWnd();
	HWND GetMainHWND();

	// ����;
	UINT ShowAboutWnd();

public:
	CLoginWnd*			m_pLoginWnd;
	CMainWnd*			m_pMainWnd;
};

#define AflGetUIHelper		CUIHelper::GetInstance