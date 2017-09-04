#pragma once
#include "LiveBaseWindow.h"

// CMainWnd �Ի���;
class CMainWnd : public CLiveBaseWindow
{
public:
	CMainWnd();
	~CMainWnd();

protected:
	LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFile();

	virtual void Init();
	virtual void OnFinalMessage(HWND hWnd);

	//virtual LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	virtual LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

	virtual LRESULT OnClickMenuItem(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	// ������Ӧ;
	//virtual LRESULT ResponseDefaultKeyEvent(WPARAM wParam);

	// ��ʾ�û���Ϣ;
	void ShowUserInfo();

	void OnCloseClicked();

	void Notify(TNotifyUI& msg);

	// �˵���Ӧ;
	void OnMenuMyInfo();		// �ҵ�����;
	void OnMenuUpdate();		// ������;
	void OnMenuInstructions();	// ʹ��˵��;
	void OnMenuFeedBack();		// �û�����;
	void OnMenuHome();			// ���ᱦ����;
	void OnMenuAbout();			// ���ڿ��ᱦ;
	void OnMenuChanged();		// �����˺�;
	void OnMenuLogout();		// ע��;
	void OnMenuExit();			// �˳�;

	void OnSetMenuClicked();	

private:
	LRESULT OnMainTrayIcon(UINT uMsg, WPARAM wParam, LPARAM lParam);

	NOTIFYICONDATA	m_iNotifyID;	// ϵͳ����;
	CMenuWnd*		m_pSetMenu;		// ���ò˵�;
};