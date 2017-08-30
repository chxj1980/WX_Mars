#pragma once
#include <stdint.h>
#include <memory.h>
#include "PSVector.h"
#include "PSString.h"

#ifndef IN
#define IN			// �������;
#endif
#ifndef OUT
#define OUT			// ��������;
#endif

typedef long long	int64_ps;
typedef int			int32_ps;

enum PSResultCode
{
	PSResult_Success			= 0,
	PSResult_ParaError			= 1,
	MsgResultRepeat = 2,
	MsgResultRedisDBError = 5,
	MsgResultMysqlError = 6,
	MsgResultDBError = 7,
	MsgResultMemNotEnough = 8,
	MsgResultNoPrivilege = 9,
	MsgResultUserOffline = 10,
	MsgResultUserIdNull = 11,
	MsgResultUserIdOverLen = 12,
	MsgResultUserIdErr = 13,
	MsgResultUserNotInGroup = 17,
	MsgResultUserListEmpty = 18,
	MsgResultUserOnline = 19,
	MsgResultGroupIdNull = 20,
	MsgResultGroupIdOverLen = 21,
	MsgResultGroupEpmty = 22,
	MsgResultMsgEmpty = 34,
	MsgResultMsgTooShort = 35,
	MsgResultMsgInvalidFormat = 36,
	MsgResultNoReceiver = 37,
	MsgResultSendHimself = 38,
	MsgResultUnknowMessageType = 39,
	MsgResultTokenInvalid = 40,
	MsgResultTokenExpired = 41,
	MsgResultServiceUnavailable = 50,
	MsgResultBrokerPushErr = 51,
	MsgResultIOSPushErr = 52,
	MsgResultOffserverErr = 53,
	MsgResultAuthserverErr = 54,
	MsgResultExceedLimit = 60,
	MsgResultLoginFailed = 70,
	MsgResultUnlogined = 71,
	MsgResultOtherError = 99,
	MsgResultNotSupport = 200,
};

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
	PSString		strFrom;
	PSString		strTo;
	short			sSendMode;
	PSString		strContent;
}PSOffMsgInfo;

// ��ȡ������Ϣ-������Ϣ;
typedef struct PSOffMsgDesc
{
	PSString		strFrom;
	PSString		strTo;
	PS_SendMode		iSendMode;
	int64_ps		iStartMsgID;
	int64_ps		iEndMsgID;
}PSOffMsgDesc;

typedef struct PSMessageItem
{
	int64_t			iMsgId;
	PSString		strFrom;
	PSString		strTo;
	int16_t			iSendMode;
	int16_t			iType;
	int8_t			iPriority;
	int16_t			iHandleOption;
	PSString		strPushInfo;
	int32_t			iTimestamp;
	int32_t			iExpireTime;
	PSString		strContent;

}PSMessageItem;

typedef struct PSOffMsgInfoNoticeItem
{
	PSOffMsgDesc offmsgDesc;			// ������Ϣ����;

	PSVector<PSMessageItem> vecMessage;	// �������ʷ��Ϣ����;

}PSOffMsgInfoNoticeItem;

// �û���Ϣ;
typedef struct PSUserInfo
{
	PSString		strUserID;
	PSString		strUserName;

}PSUserInfo;

// Ⱥ��Ϣ;
typedef struct PSGroupInfo
{
	PSString		strGroupID;
	PSString		strGroupName;
	PSString		strGroupOwner;
	PSString		strGroupDesc;
	bool			bPublic;
	int				iMaxUsers;

	PSVector<PSUserInfo>	vecAdmin;
	PSVector<PSUserInfo>	vecMember;

}PSGroupInfo;


// �ص���Ӧ����;
typedef struct PSResp
{
	int				iStatus;
	PSString		strMessage;

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
typedef struct PSCreateGroupResp : public PSResp
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

// ��ȡ��������������Ϣ֪ͨ;
typedef struct PSOffMsgInfoNotice : public PSResp
{
	PSVector<PSOffMsgInfoNoticeItem> vecOffMsgNotice;

}PSOffMsgInfoNotice;

// ��ȡ������Ϣ��Ļص�;
typedef struct PSOffMsgResp : public PSResp
{
public:
	PSVector<PSMessageItem> vecMessage;

}PSOffMsgResp;

// ������Ϣ��Ļص�;
typedef struct PSSendMsgResp : public PSResp
{
public:
	int32_t		iSeqId;
	int32_t		iTimestamp;

}PSSendMsgResp;

// ��ȡ��������������Ϣ;
typedef struct PSMsgResp : public PSResp
{
public:
	PSVector<PSMessageItem> vecMessage;

}PSMsgResp;
