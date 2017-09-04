#pragma once
#include "curl/curl.h"
#include "TstringTool.h"

class CCurlEx
{
public:
	CCurlEx();
	~CCurlEx();

public:
	// ��������;
	bool PostData(OUT std::string& strResult, IN TString strUrl);
	// �ļ�����;
	bool DownLoadFile(IN TString strUrl, IN TString strLocalPath);

	TString GetErrorInfo();

protected:
	static size_t HttpCallback(void *pStr, size_t iSize, size_t iCount, void *pOutStr);

	TString			m_strError;					// ��������;
};