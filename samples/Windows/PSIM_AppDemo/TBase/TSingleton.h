#pragma once

/*
*	brief ����ģ����;
*/
template<class T>
class TSingleton
{
public:
	// ģ��Ļ� ����,������Ҫpublic;
	TSingleton(){}
	virtual ~TSingleton(){}

private:
	// ��ֹ����,��ֵ;
	TSingleton(const TSingleton&);
	TSingleton& operator = (const TSingleton&);

public:

	static T* GetInstance()
	{
		static T t;
		return &t;
	}
};