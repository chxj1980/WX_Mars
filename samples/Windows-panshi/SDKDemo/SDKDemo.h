
// SDKDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSDKDemoApp: 
// �йش����ʵ�֣������ SDKDemo.cpp
//

class CSDKDemoApp : public CWinApp
{
public:
	CSDKDemoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSDKDemoApp theApp;