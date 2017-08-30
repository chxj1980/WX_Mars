#include "stdafx.h"
#include "PSIMDemoCallBack.h"
#include <stdio.h>

CPSIMDemoCallBack::CPSIMDemoCallBack()
{
}

CPSIMDemoCallBack::~CPSIMDemoCallBack()
{
}

// ɾ��Ⱥ-�ص�����;
void CPSIMDemoCallBack::OnDeleteGroupResponse(const PSDeleteGroupResp& resp)
{
	printf("CPSIMDemoCallBack::OnDeleteGroupResponse: iCode(%d), strInfo(%s) \n", resp.iStatus, resp.strMessage.GetString());
}

// �Ƴ�Ⱥ��Ա-�ص�����;
void CPSIMDemoCallBack::OnRemoveGroupUsersResponse(const PSRemoveGroupUsersResp& resp)
{
	printf("CPSIMDemoCallBack::OnRemoveGroupUsersResponse: iCode(%d), strInfo(%s) \n", resp.iStatus, resp.strMessage.GetString());
}

// �����Ⱥ-�ص�����;
void CPSIMDemoCallBack::OnAddGroupChildsResponse(const PSAddGroupChildsResp& resp)
{
	printf("CPSIMDemoCallBack::OnAddGroupChildsResponse: iCode(%d), strInfo(%s) \n", resp.iStatus, resp.strMessage.GetString());
}

// �Ƴ���Ⱥ-�ص�����;
void CPSIMDemoCallBack::OnRemoveGroupChildsResponse(const PSRemoveGroupChildsResp& resp)
{
	printf("CPSIMDemoCallBack::OnRemoveGroupChildsResponse: iCode(%d), strInfo(%s) \n", resp.iStatus, resp.strMessage.GetString());
}