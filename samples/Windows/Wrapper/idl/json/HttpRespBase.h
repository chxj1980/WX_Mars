#pragma once
#include "JsonObjectBase.h"

class CHttpRespBase: public CJsonObjectBase
{
public:
	CHttpRespBase();

	// ������Ҫʵ�ִ˺��������ҽ���Ӧ��ӳ���ϵ��������;   
	virtual void SetPropertys();

	void DisplayPropertys();

public:
	int				m_iStatus;
	std::string		m_strMessage;
};