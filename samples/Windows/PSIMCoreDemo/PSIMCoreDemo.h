
// PSIMCoreDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

#include "PSIMDemoCallBack.h"

// CPSIMCoreDemoApp: 
// �йش����ʵ�֣������ PSIMCoreDemo.cpp
//

class CPSIMCoreDemoApp : public CWinApp
{
public:
	CPSIMCoreDemoApp();

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()

public:
	CStringA	m_strAppID;
	CStringA	m_strUserID;
private:
	CPSIMDemoCallBack* m_pCallBack;
};

extern CPSIMCoreDemoApp theApp;