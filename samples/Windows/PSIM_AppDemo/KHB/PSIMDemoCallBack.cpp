#include "PSIMDemoCallBack.h"

CPSIMDemoCallBack::CPSIMDemoCallBack()
{
}

CPSIMDemoCallBack::~CPSIMDemoCallBack()
{
}

// �����Ⱥ-�ص�����;
void CPSIMDemoCallBack::OnAddGroupChildsResponse(const PSResp& resp)
{
	printf("CPSIMDemoCallBack::OnAddGroupChildsResponse: iCode(%d), strInfo(%s) \n", resp.iStatus, resp.strMessage.GetString());
}

// �Ƴ���Ⱥ-�ص�����;
void CPSIMDemoCallBack::OnRemoveGroupChildsResponse(const PSResp& resp)
{
	printf("CPSIMDemoCallBack::OnRemoveGroupChildsResponse: iCode(%d), strInfo(%s) \n", resp.iStatus, resp.strMessage.GetString());
}