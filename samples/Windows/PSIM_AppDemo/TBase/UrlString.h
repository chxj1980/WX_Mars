#pragma once
#include "format.h"
#include "TString/TStringTool.h"
#include "TBaseExport.h"

class TBASE_API CUrlString
{
public:
	CUrlString();
	~CUrlString();

	TString GetUrlString(bool bHasPara = false);
	TString GetParaString();

	void SetUrl(TString strUrl);

	void AddPara(TString strKey, int iValue);
	// ���ͳһ�ߴ˽ӿ���װ;
	void AddPara(TString strKey, TString strValue);

private:
	TString		m_strUrl;
	TString		m_strPara;
	int			m_iParaCount;
};