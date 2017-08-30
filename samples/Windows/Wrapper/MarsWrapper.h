// Tencent is pleased to support the open source community by making Mars available.
// Copyright (C) 2017 THL A29 Limited, a Tencent company. All rights reserved.

// Licensed under the MIT License (the "License"); you may not use this file except in 
// compliance with the License. You may obtain a copy of the License at
// http://opensource.org/licenses/MIT

// Unless required by applicable law or agreed to in writing, software distributed under the License is
// distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
// either express or implied. See the License for the specific language governing permissions and
// limitations under the License.

/*
*  MarsWrapper.h
*
*  Created on: 2017-7-7
*      Author: chenzihao
*/

#ifndef _MARS_WRAPPER_H_
#define _MARS_WRAPPER_H_

#include "NetworkObserver.h"
#include "NetworkService.h"
#include "task/Login_Task.h"
#include "task/NoBody_Task.h"
#include "task/Msg_Task.h"
#include "task/OffMsg_Task.h"
#include "task/CreateGroup_Task.h"
#include "task/DeleteGroup_Task.h"
#include "task/AddGroupUser_Task.h"

class AppInfo
{
public:
	std::string strAppID;
	std::string strToken;
	std::string strUserID;
};

class MessagePush
{
public:
	// ��������;
	virtual void OnKickOut(const PSKickOutResp& response) = 0;

	// ������Ϣ;
	virtual void OnRecvMessage(const PSMessageItem& response) = 0;

	// ����������Ϣ����;
	virtual void OnRecvOffMsgNotice(const PSOffMsgInfoNotice& response) = 0;
};

// ҵ���װ��;
class MarsWrapper: public PushObserver
{
public:
	// ���� ���̰߳�ȫ;
	static MarsWrapper& GetInstance();
	// ����;
	void Start();
	// ����;
	void Exit();

	// ���ý�����Ϣ�Ļص���;
	void SetMsgPushObserver(MessagePush* pMsgPush);

	// �ͻ�������;
	// ��¼
	void MsgLogin(OUT const char* strAppID, 
		IN const char* strAppToken,
		IN const char* strUserID,
		IN const char* strUserName,
		IN const int iDeviceType,
		IN const char* strDeviceToken,
		IN Login_Callback* pCallback);

	// ע��
	void MsgLogout();

	void CreateGroup(IN const PSGroupInfo& groupInfo, IN CreateGroup_Callback* pCallback);
	void DeleteGroup(IN const char* strGroupID, IN DeleteGroup_Callback* pCallback);

	//// ��ȡȺ��Ϣ;
	//virtual void GetGroupInfo(const char* strGroupID);

	//// ��ȡȺ��Ա;
	//virtual void GetGroupUsers(const char* strGroupID, const int iPageNum, const int iPageSize);
	// ���Ⱥ��Ա;
	virtual void AddGroupUsers(IN const char* strGroupID, IN const PSUserInfo* userInfo, IN const int iAddCount, IN AddGroupUser_Callback* pCallback);
	// �Ƴ�Ⱥ��Ա;
	virtual void RemoveGroupUsers(IN const char* strGroupID, IN const PSUserInfo* userInfo, IN const int iRemoveCount);

	//// ����Ⱥ��Ա��ɫ
	//virtual void SetGroupUserRole(const char* strGroupID);

	//// ����
	//virtual void Shutup(const char* strGroupID);
	//// ���
	//virtual void UnShutup(const char* strGroupID);
	//// ��ȡ�����б�
	//virtual void GetShutupList(const char* strGroupID);

	//// ����Ⱥ��Ա
	//virtual void InviteGroupUsers(const char* strGroupID);

	// �����ı���Ϣ
	void SendTextMessage(OUT int& iReqID,
		IN const PS_SendMode& eSendMode,
		IN const char* strFrom,
		IN const char* strTo,
		IN const char* strContent,
		IN const int& iContentLen,
		IN const char* strPushInfo,
		IN Msg_Callback* pCallback);

	// ��ȡ������Ϣ
	void GetOfflineMsgs(OUT std::vector<PSOffMsgDesc>& vecMsgDesc,
		IN OffMsg_Callback* pCallback);

	// ��Ϣ����
	//virtual void RevokeMsg();

protected:
	virtual void OnPush(uint64_t _channel_id, uint32_t _cmdid, uint32_t _taskid, const AutoBuffer& _body, const AutoBuffer& _extend);

	// ��������;
	virtual void OnKickOut(const AutoBuffer& _body);
	// ������Ϣ;
	virtual void OnRecvMessage(const AutoBuffer& _body);
	// ����������Ϣ֪ͨ;
	virtual void OnGetOffMsgInfoNotice(const AutoBuffer& _body);

private:
	MarsWrapper();

	MessagePush*	m_pMsgPush;
	AppInfo			m_appInfo;
};

#endif