#pragma once
#include "LiveBaseWindow.h"
#include "IniConfig.h"
#include "CmdInfo.h"

// CLoginWnd �Ի���
class CLoginWnd : public CLiveBaseWindow
{
public:
	CLoginWnd(bool bLoginOut);
	~CLoginWnd();

protected:
	LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFile();

	virtual void Init();
	virtual void OnFinalMessage(HWND hWnd);

	// ������Ӧ;
	virtual LRESULT ResponseDefaultKeyEvent(WPARAM wParam);

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

	virtual LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnLoginTrayIcon(UINT uMsg, WPARAM wParam, LPARAM lParam);

	void Notify(TNotifyUI& msg);

	void OnNameChanged();	// �˺ű��;
	void OnRegistAccount();	// ע���˺�;
	void OnRecoverPwd();	// �һ�����;
	void OnRememberPwd();	// ��ס����;
	void OnAutoLogin();		// �Զ���¼;
	void OnLogin();			// ��½��Ӧ;

	void ShowUserHeader(CDuiString strUserName);

	void OnCloseClicked();

	static void Login_CallBack(CmdInfo& cmdInfo);

private:

	NOTIFYICONDATA	m_nid;			// ϵͳ�������;
	CIniConfig		m_iniConfig;	// �ļ�����;
	bool			m_bLoginOut;	// �Ƿ�ע��;
};