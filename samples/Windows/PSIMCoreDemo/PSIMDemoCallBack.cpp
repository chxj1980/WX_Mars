#include "stdafx.h"
#include "PSIMDemoCallBack.h"
#include <stdio.h>

CPSIMDemoCallBack::CPSIMDemoCallBack()
{
}

CPSIMDemoCallBack::~CPSIMDemoCallBack()
{
}

void CPSIMDemoCallBack::OnGetOffMsgResponse(const int & iCode, const char * strInfo)
{
	printf("CPSIMDemoCallBack::OnGetOffMsgResponse: iCode(%d), strInfo(%s) \n", iCode, strInfo);

	// todo
	return;
}

// ɾ��Ⱥ-�ص�����;
void CPSIMDemoCallBack::OnDeleteGroupResponse(const PSDeleteGroupResp& respDeleteeGroup)
{
	printf("CPSIMDemoCallBack::OnDeleteGroupResponse: iCode(%d), strInfo(%s) \n", respDeleteeGroup.iStatus, respDeleteeGroup.strMessage);
}

// �Ƴ�Ⱥ��Ա-�ص�����;
void CPSIMDemoCallBack::OnRemoveGroupUsersResponse(const PSRemoveGroupUsersResp& respRemoveGroupUsers)
{
	printf("CPSIMDemoCallBack::OnRemoveGroupUsersResponse: iCode(%d), strInfo(%s) \n", respRemoveGroupUsers.iStatus, respRemoveGroupUsers.strMessage);
}

// �����Ⱥ-�ص�����;
void CPSIMDemoCallBack::OnAddGroupChildsResponse(const PSAddGroupChildsResp& respAddGroupChilds)
{
	printf("CPSIMDemoCallBack::OnAddGroupChildsResponse: iCode(%d), strInfo(%s) \n", respAddGroupChilds.iStatus, respAddGroupChilds.strMessage);
}

// �Ƴ���Ⱥ-�ص�����;
void CPSIMDemoCallBack::OnRemoveGroupChildsResponse(const PSRemoveGroupChildsResp& respRemoveGroupChilds)
{
	printf("CPSIMDemoCallBack::OnRemoveGroupChildsResponse: iCode(%d), strInfo(%s) \n", respRemoveGroupChilds.iStatus, respRemoveGroupChilds.strMessage);
}