#pragma once

#define VERSION_COUNT	4

class CMyVersion
{
public:
	CMyVersion();
	CMyVersion(const char* strVesion);
	~CMyVersion();

	// ����·����ȡ�ļ��汾��Ϣ;
	static void GetFileDescriptionAndProductVersionA(LPCSTR lpstrFilename,
		LPSTR lpoutFileDescription, UINT cbDescSize,
		LPSTR lpoutProductVersion, UINT cbVerSize);

	// ��otherVer���бȽ�;
	// ���汾��С��otherVer �򷵻�-1;
	// ���汾�ŵ���otherVer �򷵻�0;
	// ���汾�Ŵ���otherVer �򷵻�1;
	int Compare(const CMyVersion& otherVer);

private:
	int		m_arrVer[VERSION_COUNT];
};

