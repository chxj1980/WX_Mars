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
*  CGITask.h
*
*  Created on: 2017-7-7
*      Author: chenzihao
*/

#ifndef _CGI_TASK_H_
#define _CGI_TASK_H_

#include <map>
#include <string>
#include "mars/comm/autobuffer.h"
#include "PSDefs.h"

#define NO_APP_SERVER		// ��ʱû��ҵ�������;

// ͨ������;
enum ChannelType 
{
	ChannelType_ShortConn				= 1,		// ������ http;
	ChannelType_LongConn				= 2,		// ������ tcp;
	ChannelType_All						= 3			// ��������ȫ֧��;
};

// ��������;
enum MsgCmd
{
	MSGCMD_BOTH_INVALID					= -2,		// ��Ч;
	MSGCMD_BOTH_UNKNOWN					= -1,		// δ֪;
	MSGCMD_BOTH_PING					= 0,		// ���ӱ���

	MSGCMD_C2S_LOGIN_REQ				= 1,		// �ͻ��˵�¼
	MSGCMD_S2C_LOGIN_RESP				= 2,		// ���������ص�¼��Ӧ
	MSGCMD_BOTH_LOGIN					= 3,		// �ͻ��˻��߷������˳�

	MSGCMD_C2S_CREATE_GROUP_REQ			= 6,		// ���󴴽�һ��Ⱥ
	MSGCMD_S2C_CREATE_GROUP_RESP		= 7,		// ����Ⱥ����Ӧ
	MSGCMD_C2S_DELETE_GROUP_REQ			= 8,		// ����ɾ��һ��Ⱥ
	MSGCMD_S2C_DELETE_GROUP_RESP		= 9,		// ɾ��Ⱥ����Ӧ

	MSGCMD_C2S_ADD_GROUPUSER_REQ		= 10,		// ��group������û�������
	MSGCMD_S2C_ADD_GROUPUSER_RESP		= 11,		// ��group������û�����Ӧ
	MSGCMD_C2S_REMOVE_GROUPUSER_REQ		= 12,		// ��group���Ƴ��û�������
	MSGCMD_S2C_REMOVE_GROUPUSER_RESP	= 13,		// ��group���Ƴ��û�����Ӧ

	MSGCMD_C2S_ADD_SUBGROUP_REQ			= 14,		// ��Ⱥ�������Ⱥ����
	MSGCMD_S2C_ADD_SUBGROUP_RESP		= 15,		// ��Ⱥ�������Ⱥ��Ӧ
	MSGCMD_C2S_REMOVE_SUBGROUP_REQ		= 16,		// �Ƴ�Ⱥ����Ⱥ����
	MSGCMD_S2C_REMOVE_SUBGROUP_RESP		= 17,		// �Ƴ�Ⱥ����Ⱥ��Ӧ

	MSGCMD_C2S_SEND_MESSAGE_REP			= 18,		// �ͻ����������������Ϣ������
	MSGCMD_S2C_SEND_MESSAGE_RESP		= 19,		// �ͻ����������������Ϣ����Ӧ
	MSGCMD_S2C_RECV_MESSAGE_REP			= 20,		// ����������Ϣת�����ͻ���

	MSGCMD_S2C_HISTORY_INFO				= 23,		// ��������֪�ͻ�����ʷ��Ϣ���
	MSGCMD_C2S_HISTORY_REQ				= 24,		// ��ȡ��ʷ��Ϣ
	MSGCMD_S2C_HISTORY_RESP				= 25,		// ������������ʷ��Ϣ��Ӧ

	MSGCMD_C2S_WITHDRAW_REQ				= 34,		// �ջ���Ϣ����
	MSGCMD_S2C_WITHDRAW_RESP			= 35,		// �����������ջ���Ϣ��Ӧ
	MSGCMD_S2C_WITHDRAW					= 36,		// �����������ջ���Ϣ֪ͨ

	MSGCMD_C2S_NODISTURB_REQ			= 38,		// �������������
	MSGCMD_S2C_NODISTURB_RESP			= 39,		// �����������Ӧ

	MSGCMD_BOTH_RECEIPT					= 50,		// �Ѷ���ִ
	MSGCMD_C2S_PRESENCE_REQ				= 70,		// �û�����״̬��ѯ
	MSGCMD_S2C_PRESENCE_RESP			= 71,		// �û�����״̬��ѯ��Ӧ

	MSGCMD_BOTH_HANDSHAKE				= 10000,	// ����;
	MSGCMD_S2C_PUSH						= 10001		// ���������͸��ͻ���;
};

// �������;
class CGITask
{
public:
	CGITask() {};
	virtual ~CGITask() {};
	
	// ��������->buff;
	virtual bool Req2Buf(IN uint32_t _taskid, IN void* const _user_context, OUT AutoBuffer& _outbuffer, OUT AutoBuffer& _extend, OUT int& _error_code, IN const int _channel_select) = 0;
	// buff->��Ӧ����;
	virtual int Buf2Resp(IN uint32_t _taskid, IN void* const _user_context, IN const AutoBuffer& _inbuffer, IN const AutoBuffer& _extend, IN int& _error_code, IN const int _channel_select) = 0;

	uint32_t		taskid_;
	ChannelType		channel_select_;
	uint32_t		cmdid_;
	std::string		cgi_;
	std::string		host_;
};

#endif