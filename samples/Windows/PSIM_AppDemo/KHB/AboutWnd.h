#pragma once
#include "LiveBaseWindow.h"

// CAboutWnd �Ի���
class CAboutWnd : public CLiveBaseWindow
{
public:
	CAboutWnd();
	~CAboutWnd();

	LPCTSTR GetWindowClassName() const;

	virtual CDuiString GetSkinFile();

	virtual CControlUI* CreateControl(LPCTSTR pstrClass);

	virtual void Init();
	virtual void OnFinalMessage(HWND hWnd);

	// ������Ӧ;
	virtual LRESULT ResponseDefaultKeyEvent(WPARAM wParam);

protected:

	void Notify(TNotifyUI& msg);
};