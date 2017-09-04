#ifndef _PS_STRING_H
#define _PS_STRING_H
#include <string.h>

// �Զ���PSString��
class PSString
{
public:
	// Ĭ�Ϲ��캯��,���ڴ������ַ���;
	PSString()
	{
		m_iLen = 0;
		m_pStr = new char[1];
		m_pStr[0] = '\0';
	}
	// ��������;
	~PSString()
	{
		delete[]m_pStr;
		m_iLen = 0;
	}

	// ���캯��,��һ������������ʼ���ַ���;
	PSString(const char* const pStr)
	{
		if (pStr == NULL)
		{
			m_iLen = 0;
			m_pStr = new char[1];
			memset(m_pStr, 0, m_iLen + 1);
			if (m_pStr == NULL)
			{
				return;
			}
		}
		else
		{
			m_iLen = strlen(pStr);
			m_pStr = new char[m_iLen + 1];
			memset(m_pStr, 0, m_iLen + 1);
			if (m_pStr == NULL)
			{
				return;
			}
			strncpy(m_pStr, pStr, m_iLen);
		}
	}

	// ���캯��,��һ������������ʼ���ַ���;
	PSString(const char ch)
	{
		m_iLen = 1;
		m_pStr = new char[m_iLen+1];
		memset(m_pStr, 0, m_iLen + 1);
		strncpy(m_pStr, &ch, m_iLen);
	}

	// ���ƹ��캯��,Ĭ����ǳ�㸴��,������;
	PSString(const PSString &rs)
	{
		m_iLen = rs.GetLength();
		m_pStr = new char[m_iLen + 1];
		for (unsigned int i = 0; i < m_iLen; i++)
		{
			m_pStr[i] = rs.m_pStr[i];
		}
		m_pStr[m_iLen] = '\0';
	}
	
	// �����±������[];
	char& operator[](unsigned int length)
	{
		if (length > m_iLen)
		{
			return m_pStr[m_iLen - 1];
		}
		return m_pStr[length];
	}

	// �����±������[](const�汾);
	char operator[](unsigned int length)const
	{
		if (length > m_iLen)
		{
			return m_pStr[m_iLen - 1];
		}
		return m_pStr[length];
	}
	
	// ���ظ��������=�����������ַ���֮��ĸ�ֵ;
	PSString &operator=(const PSString &rs)
	{
		if (this == &rs)
		{
			return *this;
		}

		delete[]m_pStr;
		m_iLen = rs.GetLength();
		m_pStr = new char[m_iLen + 1];
		for (unsigned int i = 0; i < m_iLen; i++)
		{
			m_pStr[i] = rs[i];     //�����±������[]�ſ�ʹ�� 
		}
		m_pStr[m_iLen] = '\0';
		return *this;
	}
 
	// ���ؼӷ������+;
	PSString operator+(const PSString &rs)
	{
		unsigned int iTotal = m_iLen + rs.GetLength();
		char* pNewStr = new char[iTotal + 1];
		unsigned int i, j;
		for (i = 0; i < m_iLen; i++)
		{
			pNewStr[i] = m_pStr[i];
		}
		for (j = 0; j < rs.GetLength(); j++, i++)
		{
			pNewStr[i] = rs[j];
		}
		pNewStr[iTotal] = '\0';
		delete[]m_pStr;
		m_pStr = pNewStr;
		m_iLen = iTotal;
		return *this;
	}

	// ������������+=;
	PSString operator+=(const PSString &rs)
	{
		int iTotal = m_iLen + rs.GetLength();
		char* pNewStr = new char[iTotal + 1];
		unsigned int i, j;
		for (i = 0; i < m_iLen; i++)
		{
			pNewStr[i] = m_pStr[i];
		}
		for (j = 0; j < rs.GetLength(); j++, i++)
		{
			pNewStr[i] = rs[j];
		}
		pNewStr[iTotal] = '\0';
		delete []m_pStr;
		m_pStr = pNewStr;
		m_iLen = iTotal;
		return *this;
	}

	// ����С�������<;
	friend bool operator< (const PSString&str1, const PSString &str2)
	{
		if (strcmp(str1.m_pStr, str2.m_pStr) < 0) return 1;
		else return 0;
	}
	// ���ش��������>;
	friend bool operator> (const PSString&str1, const PSString &str2)
	{
		if (strcmp(str1.m_pStr, str2.m_pStr) > 0) return 1;
		else return 0;
	}
	// ���ص��������==;
	friend bool operator== (const PSString&str1, const PSString &str2)
	{
		if (strcmp(str1.m_pStr, str2.m_pStr) == 0) return 1;
		else return 0;
	}

	// ��ȡ�ַ�������;
	unsigned int PSString::GetLength()const
	{
		return m_iLen;
	}

	// ��ȡ�ַ���;
	const char*PSString::GetString()const
	{
		return m_pStr;
	}

	// �Ƿ�Ϊnull;
	bool IsNull() const
	{
		return (NULL == m_pStr);
	}

	// �Ƿ�Ϊ�մ�;
	bool IsEmpty() const
	{
		return 0 == GetLength();
	}

private:
	unsigned int	m_iLen;
	char*			m_pStr;
};

#endif // _PS_STRING_H