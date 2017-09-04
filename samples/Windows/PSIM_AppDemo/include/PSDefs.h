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

typedef char			PSInt8;
typedef unsigned char	PSUInt8;
typedef int				PSInt32;
typedef unsigned int	PSUInt32;
typedef long long		PSInt64;

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
typedef enum PS_DeviceType
{
	PS_DeviceType_Ios				= 1,	// ios
	PS_DeviceType_Android			= 2,	// android
	PS_DeviceType_Windows			= 3,	// windows
	PS_DeviceType_Other				= 6		// 
}PSDeviceType;

// ����ģʽ;
typedef enum PS_SendMode
{
	PS_SendMode_P2P					= 0,
	PS_SendMode_Group				= 1,
	PS_SendMode_P2PS				= 4,
	PS_SendMode_OneOfGroup			= 5,
	PS_SendMode_AppBroadcast		= 7,
	PS_SendMode_SystemBroadcast		= 8,
}PSSendMode;

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
typedef struct PSOffMsgDescInfo
{
	PSString		strFrom;
	PSString		strTo;
	PS_SendMode		iSendMode;
	PSInt64			iStartMsgID;
	PSInt64			iEndMsgID;
}PSOffMsgDescInfo;

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

typedef struct PSOffMsgDescItem
{
	PSOffMsgDescInfo offmsgDesc;			// ������Ϣ����;

	PSVector<PSMessageItem> vecMessage;	// �������ʷ��Ϣ����;

}PSOffMsgDescItem;

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

// ��ѯȺ��-�ص���Ӧ;
typedef struct PSGetGroupInfoResp : public PSResp
{
	PSGroupInfo groupInfo;

}PSGetGroupInfoResp;

// ��ѯȺ�Ӽ�-�ص���Ӧ;
typedef struct PSGetGroupChildrensResp : public PSResp
{
	PSVector<PSString> vecMember;	// Ⱥ��Ա;
	PSVector<PSString> vecGroup;	// ��Ⱥ;

}PSGetGroupChildrensResp;

// ��ȡ��������������Ϣ����;
typedef struct PSOffMsgDescResp : public PSResp
{
	PSVector<PSOffMsgDescItem> vecOffMsgNotice;

}PSOffMsgDescResp;

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
	int64_t		iMsgId;
	int64_t		iTimestamp;

}PSSendMsgResp;

// ��ȡ��������������Ϣ;
typedef struct PSMsgResp : public PSResp
{
public:
	PSVector<PSMessageItem> vecMessage;

}PSMsgResp;
