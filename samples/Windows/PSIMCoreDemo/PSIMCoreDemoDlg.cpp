
// PSIMCoreDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSIMCoreDemo.h"
#include "PSIMCoreDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

HWND	g_hwndMain;
#define SENDMESSGAE_RESP		(WM_USER+102)
#define RECVMESSGAE_RESP		(WM_USER+103)
#define RECVOFFMSGNOTICE_RESP	(WM_USER+104)
#define CREATEGROUP_RESP		(WM_USER+105)
#define ADDGROUPUSER_RESP		(WM_USER+106)
#define KICKOUT_RESP			(WM_USER+107)
#define GETOFFMSG_RESP			(WM_USER+108)


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPSIMCoreDemoDlg �Ի���
CPSIMCoreDemoDlg::CPSIMCoreDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PSIMCOREDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPSIMCoreDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_FROM_USERID, m_edtFromUser);
	DDX_Control(pDX, IDC_EDIT_TO_USERID, m_edtToUser);
	DDX_Control(pDX, IDC_EDIT_SINGLE_CONTENT, m_edtContent);
	DDX_Control(pDX, IDC_RICHEDIT_INFO, m_edtInfo);
	DDX_Control(pDX, IDC_EDIT_GROUP_ID, m_edtGroup);
	DDX_Control(pDX, IDC_EDIT_GROUP_MEMBER_ID, m_edtGroupMember);
	DDX_Control(pDX, IDC_EDIT_FROM_GUSERID, m_edtFromGUser);
	DDX_Control(pDX, IDC_EDIT_TO_GROUPID, m_edtToGroup);
	DDX_Control(pDX, IDC_EDIT_GROUP_CONTENT, m_edtGroupContent);
}

BEGIN_MESSAGE_MAP(CPSIMCoreDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CPSIMCoreDemoDlg::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDC_BUTTON_CREATEGROUP, &CPSIMCoreDemoDlg::OnBnClickedButtonCreategroup)
	ON_BN_CLICKED(IDC_BUTTON_DELETEGROUP, &CPSIMCoreDemoDlg::OnBnClickedButtonDeletegroup)
	ON_BN_CLICKED(IDC_BUTTON_GROUP_MEMBER_ADD, &CPSIMCoreDemoDlg::OnBnClickedButtonGroupMemberAdd)
	ON_BN_CLICKED(IDC_BUTTON_GROUP_MEMBER_REMOVE, &CPSIMCoreDemoDlg::OnBnClickedButtonGroupMemberRemove)
	ON_BN_CLICKED(IDC_BUTTON_GROUP_SEND, &CPSIMCoreDemoDlg::OnBnClickedButtonGroupSend)
END_MESSAGE_MAP()


// CPSIMCoreDemoDlg ��Ϣ�������
BOOL CPSIMCoreDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	g_hwndMain = m_hWnd;

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	m_edtFromUser.SetWindowText(CA2CT(theApp.m_strUserID));
	m_edtFromGUser.SetWindowText(CA2CT(theApp.m_strUserID));

	return TRUE;
}

LRESULT CPSIMCoreDemoDlg::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case SENDMESSGAE_RESP:
		{
			PSSendMsgResp* pMsgResp = (PSSendMsgResp*)wParam;
			assert(pMsgResp);

			CString strInfo;
			strInfo.Format(_T(" seq(%d) has resp: Code(%d), Info(%s), \n"), pMsgResp->iSeqId, pMsgResp->iStatus, CA2CT(pMsgResp->strMessage.GetString()));
			AppendInfo(strInfo);
		}
		break;
	case KICKOUT_RESP:
		{
			PSKickOutResp* pKickOutResp = (PSKickOutResp*)wParam;
			assert(pKickOutResp);

			CString strInfo;
			strInfo.Format(_T(" kickout: satus(%d), message(%s) \n"), pKickOutResp->iStatus, CA2CT(pKickOutResp->strMessage.GetString()));
			MessageBox(strInfo);
			EndDialog(IDOK);
		}
		break;
	case RECVMESSGAE_RESP:
		{
			PSMessageItem* pMsgItem = (PSMessageItem*)wParam;
			assert(pMsgItem);

			CStringA strInfoA;
			strInfoA.Format("from: %s -> to: %s msgid: %d \n content: %s \n", pMsgItem->strFrom.GetString(), pMsgItem->strTo.GetString(), (int)(pMsgItem->iMsgId), pMsgItem->strContent.GetString());
			CString strInfo = CA2CT(strInfoA);
			AppendInfo(strInfo);
		}
		break;
	case RECVOFFMSGNOTICE_RESP:
		{
			PSOffMsgInfoNotice* pOffMsgNotice = (PSOffMsgInfoNotice*)wParam;
			assert(pOffMsgNotice);

			CStringA strInfoA;
			strInfoA.Format("recvoffmsgnotice_resp: status(%d) message(%s) noticecount(%d) \n", pOffMsgNotice->iStatus, pOffMsgNotice->strMessage.GetString(), pOffMsgNotice->vecOffMsgNotice.size());
			CString strInfo = CA2CT(strInfoA);
			AppendInfo(strInfo);

			PSVector<PSOffMsgDesc> vecOffMsgDesc;
			for (int i = 0; i < pOffMsgNotice->vecOffMsgNotice.size(); i++)
			{
				PSOffMsgInfoNoticeItem& noticeItem = pOffMsgNotice->vecOffMsgNotice[i];
				strInfoA.Format("\nfrom: %s -> to: %s sendmode: %d startmsgid: %d endmsgid: %d \n", 
					noticeItem.offmsgDesc.strFrom.GetString(), noticeItem.offmsgDesc.strTo.GetString(), (int)(noticeItem.offmsgDesc.iSendMode), (int)(noticeItem.offmsgDesc.iStartMsgID), (int)(noticeItem.offmsgDesc.iEndMsgID));
				strInfo = CA2CT(strInfoA);
				AppendInfo(strInfo);
				if (0 == noticeItem.offmsgDesc.strFrom.GetLength())
				{
					noticeItem.offmsgDesc.strFrom = "3";
				}
				vecOffMsgDesc.push_back(noticeItem.offmsgDesc);

				AppendInfo(_T("Last Msg : \n"));
				for (int j = 0; j < noticeItem.vecMessage.size(); j++)
				{
					PSMessageItem& msgItem = noticeItem.vecMessage[j];
					strInfoA.Format("from: %s -> to: %s sendmode: %d msgid: %d content: %s \n", msgItem.strFrom.GetString(), msgItem.strTo.GetString(), (int)(msgItem.iSendMode), (int)(msgItem.iMsgId), msgItem.strContent.GetString());
					strInfo = CA2CT(strInfoA);
					AppendInfo(strInfo);
				}
			}

			// �յ�������Ϣ�������� ���ǿ���Ҫ���ȡ������Ϣ����;
			AfxGetPSIMCall()->GetOfflineMsgs(vecOffMsgDesc);
		}
		break;
	case GETOFFMSG_RESP:
		{
			PSOffMsgResp* resp = (PSOffMsgResp*)wParam;
			assert(resp);

			CStringA strInfoA;
			strInfoA.Format("\nget off msg :  status(%d) message(%s) \n", resp->iStatus, resp->strMessage.GetString());
			CString strInfo = CA2CT(strInfoA);
			AppendInfo(strInfo);

			for (int j = 0; j < resp->vecMessage.size(); j++)
			{
				PSMessageItem& msgItem = resp->vecMessage[j];
				strInfoA.Format("from: %s -> to: %s sendmode: %d msgid: %d content: %s \n", msgItem.strFrom.GetString(), msgItem.strTo.GetString(), (int)(msgItem.iSendMode), (int)(msgItem.iMsgId), msgItem.strContent.GetString());
				strInfo = CA2CT(strInfoA);
				AppendInfo(strInfo);
			}
		}
		break;
	case CREATEGROUP_RESP:
		{
			PSCreateGroupResp* resp = (PSCreateGroupResp*)wParam;
			assert(resp);

			CStringA strInfoA;
			strInfoA.Format("creategroup :  status(%d) message(%s) \n", resp->iStatus, resp->strMessage.GetString());
			CString strInfo = CA2CT(strInfoA);
			AppendInfo(strInfo);
		}
		break;
	case ADDGROUPUSER_RESP :
		{
			PSAddGroupUsersResp* resp = (PSAddGroupUsersResp*)wParam;
			assert(resp);

			CStringA strInfoA;
			strInfoA.Format("addgroupuser :  status(%d) message(%s) \n", resp->iStatus, resp->strMessage.GetString());
			CString strInfo = CA2CT(strInfoA);
			AppendInfo(strInfo);
		}
		break;
	default:
		break;
	}

	return CDialogEx::DefWindowProc(message, wParam, lParam);
}

void CPSIMCoreDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CPSIMCoreDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CPSIMCoreDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPSIMCoreDemoDlg::OnBnClickedButtonSend()
{
	CString strFrom, strTo, strContent;
	m_edtFromUser.GetWindowText(strFrom);
	m_edtToUser.GetWindowText(strTo);
	m_edtContent.GetWindowText(strContent);

	int iSeqID = 0;
	//for (int i = 0; i < 1000; i++)
	{
		PSString strBuff = CT2CA(strContent);
		AfxGetPSIMCall()->SendTextMessage(iSeqID, PS_SendMode_P2P, CT2CA(strFrom), CT2CA(strTo), strBuff, "");
		if (iSeqID > 0)
		{
			CString strInfo;
			strInfo.Format(_T("from: %s -> to: %s seqid: %d \n content: %s \n"), strFrom, strTo, iSeqID, strContent);
			AppendInfo(strInfo);
		}
	}
}

void CPSIMCoreDemoDlg::AppendInfo(CString strInfo)
{
	// ������ֵĳ���;
	int nTextLength = m_edtInfo.GetWindowTextLength();
	// ���������ı���ĩ;
	m_edtInfo.SetSel(nTextLength, nTextLength);
	// д���ı�;
	m_edtInfo.ReplaceSel(strInfo);

	//m_edtInfo.LineScroll(m_edtInfo.GetLineCount());
}


void CPSIMCoreDemoDlg::OnBnClickedButtonCreategroup()
{
	CString strGroupID;
	m_edtGroup.GetWindowText(strGroupID);
	CStringA strGroupIDA;
	strGroupIDA = CT2CA(strGroupID);
	if (strGroupID.IsEmpty())
	{
		MessageBox(_T("groupid ����Ϊ�գ�"));
		return;
	}

	PSGroupInfo groupInfo;
	groupInfo.strGroupID = (char*)strGroupIDA.GetString();
	AfxGetPSIMCall()->CreateGroup(groupInfo);
}

void CPSIMCoreDemoDlg::OnBnClickedButtonDeletegroup()
{
	CString strGroupID;
	m_edtGroup.GetWindowText(strGroupID);
	CStringA strGroupIDA = CT2CA(strGroupID);

	AfxGetPSIMCall()->DeleteGroup(strGroupIDA);
}

void CPSIMCoreDemoDlg::OnBnClickedButtonGroupMemberAdd()
{
	CString strGroupID;
	m_edtGroup.GetWindowText(strGroupID);
	CStringA strGroupIDA;
	strGroupIDA = CT2CA(strGroupID);
	if (strGroupID.IsEmpty())
	{
		MessageBox(_T("groupid ����Ϊ�գ�"));
		return;
	}

	CString strMemberID;
	m_edtGroupMember.GetWindowText(strMemberID);
	CStringA strMemberIDA;
	strMemberIDA = CT2CA(strMemberID);
	if (strMemberID.IsEmpty())
	{
		MessageBox(_T("Group Member ����Ϊ�գ�"));
		return;
	}

	const int iCount = 1;
	PSUserInfo* pUser = new PSUserInfo[iCount];
	pUser[0].strUserID = (char*)strMemberID.GetString();
	AfxGetPSIMCall()->AddGroupUsers(strGroupIDA.GetString(), pUser, iCount);
	delete []pUser;
	pUser = NULL;
}


void CPSIMCoreDemoDlg::OnBnClickedButtonGroupMemberRemove()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CPSIMCoreDemoDlg::OnBnClickedButtonGroupSend()
{
	CString strFromGUser, strToGroup, strGroupContent;
	m_edtFromGUser.GetWindowText(strFromGUser);
	m_edtToGroup.GetWindowText(strToGroup);
	m_edtGroupContent.GetWindowText(strGroupContent);

	int iSeqID = 0;
	//for (int i = 0; i < 1000; i++)
	{
		PSString strBuff = CT2CA(strGroupContent);
		AfxGetPSIMCall()->SendTextMessage(iSeqID, PS_SendMode_Group, CT2CA(strFromGUser), CT2CA(strToGroup), strBuff, "");
		if (iSeqID > 0)
		{
			CString strInfo;
			strInfo.Format(_T("from: %s -> to: %s seqid: %d \n content: %s \n"), strFromGUser, strToGroup, iSeqID, strGroupContent);
			AppendInfo(strInfo);
		}
	}
}

// ע��-�ص�����;
void CPSIMDemoCallBack::OnMsgLogoutResponse(const PSMsgLoginResp& resp)
{
	printf("CPSIMDemoCallBack::OnMsgLogoutResponse: status:(%d), message(%s) \n", resp.iStatus, resp.strMessage.GetString());

	//SendMessage(g_hwndMain, SENDMESSGAE_RESP, (WPARAM)&msgResp, NULL);
}

// �����߳�-�ص�����;
void CPSIMDemoCallBack::OnKickOutResponse(const PSKickOutResp& resp)
{
	printf("CPSIMDemoCallBack::OnSendMsgResponse: status:(%d), message(%s)\n", resp.iStatus, resp.strMessage.GetString());

	SendMessage(g_hwndMain, KICKOUT_RESP, (WPARAM)&resp, NULL);
}

// callback
void CPSIMDemoCallBack::OnSendMsgResponse(const PSSendMsgResp& resp)
{
	printf("CPSIMDemoCallBack::OnSendMsgResponse: iSeqID:(%d), iCode(%d), strInfo(%s) \n", resp.iSeqId, resp.iStatus, resp.strMessage.GetString());

	SendMessage(g_hwndMain, SENDMESSGAE_RESP, (WPARAM)&resp, NULL);
}

void CPSIMDemoCallBack::OnRecvMessageResponse(const PSMessageItem & msgItem)
{
	printf("CPSIMDemoCallBack::OnRecvMessage\n");

	SendMessage(g_hwndMain, RECVMESSGAE_RESP, (WPARAM)&msgItem, NULL);
}

void CPSIMDemoCallBack::OnRecvOffMsgNoticeResponse(const PSOffMsgInfoNotice& offmsgNotice)
{
	printf("CPSIMDemoCallBack::OnRecvOffMsgNotice");

	Sleep(2 * 1000);
	SendMessage(g_hwndMain, RECVOFFMSGNOTICE_RESP, (WPARAM)&offmsgNotice, NULL);
}

void CPSIMDemoCallBack::OnGetOffMsgResponse(const PSOffMsgResp& resp)
{
	printf("CPSIMDemoCallBack::OnGetOffMsgResponse: status(%d), message(%s) \n", resp.iStatus, resp.strMessage.GetString());

	SendMessage(g_hwndMain, GETOFFMSG_RESP, (WPARAM)&resp, NULL);
}

void CPSIMDemoCallBack::OnCreateGroupResponse(const PSCreateGroupResp & resp)
{
	printf("CPSIMDemoCallBack::OnCreateGroupResponse\n");

	SendMessage(g_hwndMain, CREATEGROUP_RESP, (WPARAM)&resp, NULL);
}

void CPSIMDemoCallBack::OnAddGroupUsersResponse(const PSAddGroupUsersResp& resp)
{
	printf("CPSIMDemoCallBack::OnAddGroupUserResponse\n");

	SendMessage(g_hwndMain, ADDGROUPUSER_RESP, (WPARAM)&resp, NULL);
}