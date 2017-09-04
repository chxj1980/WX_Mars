#pragma once
#include "DuiBaseWindow.h"

// CUpdateDialog �Ի���
class CUpdateDialog : public CDuiBaseWindow
{
public:
	CUpdateDialog();
	~CUpdateDialog();

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
};