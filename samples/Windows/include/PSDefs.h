#pragma once
#include <stdint.h>
#include <memory.h>

#ifndef IN
#define IN			// �������;
#endif
#ifndef OUT
#define OUT			// ��������;
#endif

typedef long long	int64_ps;
typedef int			int32_ps;

// �豸����;
enum PS_DeviceType
{
	PS_DeviceType_Ios				= 1,	// ios
	PS_DeviceType_Android			= 2,	// android
	PS_DeviceType_Windows			= 3,	// windows
	PS_DeviceType_Other				= 6		// 
};

// ����ģʽ;
enum PS_SendMode
{
	PS_SendMode_P2P					= 0,
	PS_SendMode_Group				= 1,
	PS_SendMode_P2PS				= 4,
	PS_SendMode_OneOfGroup			= 5,
	PS_SendMode_AppBroadcast		= 7,
	PS_SendMode_SystemBroadcast		= 8,
};

// ��������;
enum PS_SendOption
{
	PS_SendOption_OfflineSave		= 0x0004,
	PS_SendOption_IosPush			= 0x0008,
};

// ��Ϣ����;
enum PS_MessageType
{
	PS_MessageType_Text				= 1,
	PS_MessageType_Image			= 2,
	PS_MessageType_Audio			= 3,
	PS_MessageType_Video			= 4,
	PS_MessageType_File				= 5,
	PS_MessageType_Geo				= 6,
	PS_MessageType_Custom			= 7,
	PS_MessageType_Tip				= 8,
	PS_MessageType_Command			= 9,
	PS_MessageType_Operate			= 80,
	PS_MessageType_Other			= 120,
};

// ������Ϣ��Ϣ;
typedef struct PSOffMsgInfo
{
	char*	strFrom;
	char*	strTo;
	short	sSendMode;
	char*	strContent;
}PSOffMsgInfo;

// ��ȡ������Ϣ-������Ϣ;
typedef struct PSOffMsgDesc
{
	char*			strFrom;
	char*			strTo;
	PS_SendMode		iSendMode;
	int64_ps		iStartMsgID;
	int32_ps		iMsgCount;
}PSOffMsgDesc;

typedef struct PSBuffer
{
	char*	pBuff;
	int		iLen;
}PSBuffer;

// �ص���Ӧ����;
typedef struct PSResp
{
	int			iStatus;
	char*		strMessage;
}PSResp;

// ��¼-�ص���Ӧ;
typedef struct PSMsgLoginResp : public PSResp
{

}PSMsgLoginResp;

// ע��-�ص���Ӧ;
typedef struct PSMsgLogoutResp : public PSResp
{

}PSMsgLogoutResp;

// �����˳�-�ص���Ӧ;
typedef struct PSKickOutResp : public PSResp
{

}PSKickOutResp;

// ����Ⱥ��-�ص���Ӧ;
typedef struct PSCreateGroupResp: public PSResp
{

}PSCreateGroupResp;

// ɾ��Ⱥ��-�ص���Ӧ;
typedef struct PSDeleteGroupResp : public PSResp
{

}PSDeleteGroupResp;

// ���Ⱥ��Ա-�ص���Ӧ;
typedef struct PSAddGroupUsersResp : public PSResp
{

}PSAddGroupUsersResp;

// �Ƴ�Ⱥ��Ա-�ص���Ӧ;
typedef struct PSRemoveGroupUsersResp : public PSResp
{

}PSRemoveGroupUsersResp;

// �����Ⱥ-�ص���Ӧ;
typedef struct PSAddGroupChildsResp : public PSResp
{

}PSAddGroupChildsResp;

// �Ƴ���Ⱥ-�ص���Ӧ;
typedef struct PSRemoveGroupChildsResp : public PSResp
{

}PSRemoveGroupChildsResp;

typedef struct PSMessageItem
{
	int64_t		iMsgId;
	char*		strFrom;
	char*		strTo;
	int16_t		iSendMode;
	int16_t		iType;
	int8_t		iPriority;
	int16_t		iHandleOption;
	char*		strPushInfo;
	int32_t		iTimestamp;
	int32_t		iExpireTime;
	PSBuffer	psBuff;
}PSMessageItem;

// ������Ϣ�����Ӧ;
typedef struct PSMsgResp
{
public:
	int32_t		iSeqId;
	int32_t		iCode;
	char*		strInfo;
	int32_t		iTimestamp;
}PSMsgResp;

// �û���Ϣ;
typedef struct PSUserInfo
{
	PSUserInfo()
	{
		memset(this, 0, sizeof(PSUserInfo));
	}

	char* strUserID;
	char* strUserName;

}PSUserInfo;

// Ⱥ��Ϣ;
typedef struct PSGroupInfo
{
	PSGroupInfo()
	{
		memset(this, 0, sizeof(PSGroupInfo));
	}

	char* strGroupID;
	char* strGroupName;
	char* strGroupOwner;
	char* strGroupDesc;
	bool bPublic;
	int iMaxUsers;

	PSUserInfo* pAdmins;
	int	iAdminCount;
	PSUserInfo* pMembers;
	int	iMemberCount;

}PSGroupInfo;