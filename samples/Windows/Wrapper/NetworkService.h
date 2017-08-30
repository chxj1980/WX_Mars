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
*  NetworkService.h
*
*  Created on: 2017-7-7
*      Author: chenzihao
*/

#ifndef _MARS_SERVICE_PROXY_H_
#define _MARS_SERVICE_PROXY_H_
#include <queue>
#include <map>
#include <string>

#include "mars/comm/thread/thread.h"
#include "mars/comm/autobuffer.h"
#include "task/CGITask.h"
#include "NetworkObserver.h"

typedef std::map<uint32_t, CGITask*> MapTasks;
typedef std::map<uint32_t, PushObserver*> MapPushObservers;

class NetworkService
{
public:
	// �����࣬���̰߳�ȫ;
	static NetworkService& GetInstance();
	// ����;
	void Start();
	// ����;
	void Exit();

	// ������: ��ʼ->����->����->����
	// ����ʼ;
	int StartTask(CGITask* task);
	// ������ ����תbuff
	bool Req2Buf(uint32_t _taskid, void* const _user_context, AutoBuffer& _outbuffer, AutoBuffer& _extend, int& _error_code, const int _channel_select);
	// ����Ӧ�� buffת��Ӧ
	int Buf2Resp(uint32_t _taskid, void* const _user_context, const AutoBuffer& _inbuffer, const AutoBuffer& _extend, int& _error_code, const int _channel_select);
	// �������
	int OnTaskEnd(uint32_t _taskid, void* const _user_context, int _error_type, int _error_code);
	
	// ���������Ϣ;
	void setClientVersion(uint32_t _client_version);
	void SetHeartInterval(uint32_t _heart_interval);
	void setShortLinkDebugIP(const std::string& _ip, unsigned short _port);
	void setShortLinkPort(unsigned short _port);
	void setLongLinkAddress(const std::string& _ip, unsigned short _port, const std::string& _debug_ip = "");

	// ���ûص���;
	void SetPushObserver(uint32_t iCmdID, PushObserver* pObserver);
	// �ص�����;
	void OnPush(uint64_t _channel_id, uint32_t _cmdid, uint32_t _taskid, const AutoBuffer& _body, const AutoBuffer& _extend);

protected:
	NetworkService();
	~NetworkService();

	void Init();

private:
	MapTasks			m_mapTasks;
	MapPushObservers	m_mapObservers;
};

#endif