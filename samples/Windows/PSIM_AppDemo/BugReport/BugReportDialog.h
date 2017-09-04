#pragma once
#include "DuiBaseWindow.h"

enum 
{
	E_NONE	= 0x0000,
	E_SEND	= 0x0001,
	E_RESART = 0x0002
};

// CBugReportDialog �Ի���
class CBugReportDialog : public CDuiBaseWindow
{
public:
	CBugReportDialog();
	~CBugReportDialog();

protected:

	LPCTSTR GetWindowClassName() const;

	virtual CDuiString GetSkinFile();

	virtual void Init();
	virtual void OnFinalMessage(HWND hWnd);

	// ������Ӧ;
	virtual LRESULT ResponseDefaultKeyEvent(WPARAM wParam);

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

	// Caption˫���¼�;
	virtual LRESULT OnNcLButtonDbClick(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

protected:

	void Notify(TNotifyUI& msg);

	void OnOK();
};