#ifndef _CREATEGROUPIN_CGI_TASK_H_
#define _CREATEGROUPIN_CGI_TASK_H_

#include "task/CGITask.h"
#include "mars/boost/weak_ptr.hpp"
#include "json/CreateGroupResp_Json.h"

class CreateGroup_Task;

// CreateGroup����ص�;
class CreateGroup_Callback
{
public:
	virtual void OnResponse(CreateGroup_Task* task, CreateGroupResp_Json& response) = 0;
};

// CreateGroup����;
class CreateGroup_Task : public CGITask 
{
public:
	virtual bool Req2Buf(uint32_t _taskid, void* const _user_context, AutoBuffer& _outbuffer, AutoBuffer& _extend, int& _error_code, const int _channel_select);
	virtual int Buf2Resp(uint32_t _taskid, void* const _user_context, const AutoBuffer& _inbuffer, const AutoBuffer& _extend, int& _error_code, const int _channel_select);

	std::string		m_strGroupID;				// Ⱥ��Ψһ����;
	std::string		m_strGroupName;				// Ⱥ�����ƣ�������Ϊ�����;
	std::string		m_strGroupDesc;				// Ⱥ��������������Ϊ�����;
	bool			m_bPublic;					// �Ƿ��ǹ���Ⱥ ������Ϊ�����;
	int				m_iMaxUsers;				// Ⱥ���Ա�����������Ⱥ���� ֵΪ��ֵ���ͣ�Ĭ��ֵ200��������Ϊ��ѡ��;
	std::string		m_strOwner;					// Ⱥ��Ĺ���Ա��������Ϊ�����;
	std::vector<std::string>	m_vecAdmins;	// ����Ա;
	std::vector<std::string>	m_vecMembers;	// ��ͨ��Ա��������Ϊ��ѡ��;

	CreateGroup_Callback* pCallback;
};

#endif