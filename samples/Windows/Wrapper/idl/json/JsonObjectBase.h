#pragma once
#include <string>
#include <vector>
#include <list>
#include "json/json/json.h"

#pragma warning(disable:4267)  
typedef int				INT;
typedef unsigned int	UINT;

#define DoArrayDeSerialize_Wrapper(listType, type)	\
DoArrayDeSerialize<##listType<##type>, ##type>

#define Type_Wrapper(listType, type)	\
(##listType<##type>*)

#define DoArraySerialize_Wrapper(listType, type)	\
DoArraySerialize(Type_Wrapper(listType, type)addr);

#define DoObjArrayDeSerialize_Wrapper(listType, type)	\
DoObjArrayDeSerialize<##listType<type>>

typedef void* (*GenerateJsonObjForDeSerializeFromOutSide)(const std::string& propertyName);

class CJsonObjectBase
{
protected:
	enum CEnumJsonTypeMap
	{
		asBool = 1,
		asInt,
		asUInt,
		asString,
		asDouble,
		asJsonObj,
		asSpecialArray,
		asVectorArray,
		asListArray,
	};

public:
	CJsonObjectBase();
	virtual ~CJsonObjectBase();

	// ���л�
	std::string Serialize();
	// �����л�;
	bool DeSerialize(const char* str);

protected:
	Json::Value DoSerialize();
	bool DoDeSerialize(Json::Value& root);

	void SetProperty(std::string name, CEnumJsonTypeMap type, void* addr, CEnumJsonTypeMap listParamType = asInt);

	virtual void SetPropertys() = 0;
	//�����������Ҫ���л�ʱ�������ش˺���
	virtual Json::Value DoSpecialArraySerialize(const std::string& propertyName);

	//�ڷ����л�ʱ�����������Ƕ�����б������б������ɵ������������������ʱ����Ҫ���ش˺�����new�������Ķ���  
	virtual CJsonObjectBase* GenerateJsonObjForDeSerialize(const std::string& propertyName);

	bool DoArrayDeSerialize(const std::string& propertyName, void* addr, Json::Value& root, CEnumJsonTypeMap listType, CEnumJsonTypeMap paramType);

	//��������б�ķ����л�  
	template<typename T1>
	bool DoObjArrayDeSerialize(const std::string& propertyName, void* addr, Json::Value& node)
	{
		if (!node.isArray())
		{
			return false;
		}
		T1* pList = (T1*)addr;
		int size = node.size();
		for (int i = 0; i < size; ++i)
		{
			CJsonObjectBase* pNode = GenerateJsonObjForDeSerialize(propertyName);
			pNode->DoDeSerialize(node[i]);
			pList->push_back(pNode);
		}
		return true;
	}

public:
	//���������б�ķ����л�   
	template <typename T1, typename T2>
	static bool DoArrayDeSerialize(void* addr, Json::Value& node)
	{
		if (!node.isArray())
		{
			return false;
		}
		T1* pList = (T1*)addr;
		int size = node.size();
		for (int i = 0; i < size; ++i)
			pList->push_back(DeSerialize<T2>(node[i]));
		return true;
	}

	//��������б�ķ����л�  
	template<typename T1>
	static bool DoObjArrayDeSerialize(const std::string& propertyName, void* addr, Json::Value& node, GenerateJsonObjForDeSerializeFromOutSide funGenerate)
	{
		if (!node.isArray())
		{
			return false;
		}
		T1* pList = (T1*)addr;
		int size = node.size();
		for (int i = 0; i < size; ++i)
		{
			CJsonObjectBase* pNode = (CJsonObjectBase*)funGenerate(propertyName);
			pNode->DoDeSerialize(node[i]);
			pList->push_back(pNode);
		}
		return true;
	}
protected:
	Json::Value DoArraySerialize(void* addr, CEnumJsonTypeMap listType, CEnumJsonTypeMap paramType)
	{
		if (listType == asVectorArray)
		{
			switch (paramType)
			{
			case asBool:
				return "";
			case asJsonObj:
				return DoArraySerialize_Wrapper(std::vector, CJsonObjectBase*);
			case asInt:
				return DoArraySerialize_Wrapper(std::vector, INT);
			case asUInt:
				return DoArraySerialize_Wrapper(std::vector, UINT);
			case asDouble:
				return DoArraySerialize_Wrapper(std::vector, double);
			case asString:
				return DoArraySerialize_Wrapper(std::vector, std::string);
			}
		}
		else
		{
			switch (paramType)
			{
			case asBool:
				return DoArraySerialize_Wrapper(std::list, bool);
			case asJsonObj:
				return DoArraySerialize_Wrapper(std::list, CJsonObjectBase*);
			case asInt:
				return DoArraySerialize_Wrapper(std::list, INT);
			case asUInt:
				return DoArraySerialize_Wrapper(std::list, UINT);
			case asDouble:
				return DoArraySerialize_Wrapper(std::list, double);
			case asString:
				return DoArraySerialize_Wrapper(std::list, std::string);
			}
		}
		return "";
	}

public:
	template <typename T1>
	static Json::Value DoArraySerialize(T1* pList)
	{
		Json::Value arrayValue;
		for (T1::iterator it = pList->begin(); it != pList->end(); ++it)
		{
			arrayValue.append(*it);
		}
		return arrayValue;
	}

	template <>
	static Json::Value DoArraySerialize(std::vector<CJsonObjectBase*>* pList)
	{
		Json::Value arrayValue;
		for (std::vector<CJsonObjectBase*>::iterator it = pList->begin(); it != pList->end(); ++it)
		{
			arrayValue.append((*it)->DoSerialize());
		}
		return arrayValue;
	}

	template <>
	static Json::Value DoArraySerialize(std::list<CJsonObjectBase*>* pList)
	{
		Json::Value arrayValue;
		for (std::list<CJsonObjectBase*>::iterator it = pList->begin(); it != pList->end(); ++it)
		{
			arrayValue.append((*it)->DoSerialize());
		}
		return arrayValue;
	}
	static std::string JsonValueToString(Json::Value& tvalue)
	{
		Json::FastWriter writer;
		return writer.write(tvalue);
	}

private:
	template <typename T>
	Json::Value Serialize(void* addr)
	{
		return (*(T*)addr);
	}

	template <typename T>
	static T DeSerialize(Json::Value& root)
	{
		return GetData<T>(root);
	}

	template <typename T>
	static T GetData(Json::Value& root)
	{
		T temp;
		return temp;
	}

	template <>
	static bool GetData(Json::Value& root)
	{
		return root.asBool();
	}

	template <>
	static INT GetData(Json::Value& root)
	{
		return root.asInt();
	}

	template <>
	static UINT GetData(Json::Value& root)
	{
		return root.asUInt();
	}

	template <>
	static double GetData(Json::Value& root)
	{
		return root.asDouble();
	}

	template <>
	static std::string GetData(Json::Value& root)
	{
		return root.asString();
	}

private:
	std::vector<std::string>			m_vectorName;
	std::vector<void*>					m_vectorPropertyAddr;
	std::vector<CEnumJsonTypeMap>		m_vectorType;
	std::vector<CEnumJsonTypeMap>		m_vectorListParamType;
};