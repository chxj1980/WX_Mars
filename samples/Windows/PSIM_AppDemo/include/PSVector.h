#ifndef _PS_VERTOR_H
#define _PS_VERTOR_H

template<typename T>
class PSVector
{
public:

	//���캯�������ƹ��캯���Լ���������  
	PSVector(int size = 0) :theSize(size), theCapacity(0 + SPACE_CAPACITY)
	{
		objects = new T[theCapacity];
	}
	PSVector(const PSVector& rhs) : objects(NULL)
	{
		operator=(rhs);
	}
	~PSVector()
	{
		delete[] objects;
	}

	// ����=�Ų�����  
	const PSVector& operator=(const PSVector& rhs)
	{
		theCapacity = rhs.theCapacity;
		theSize = rhs.theSize;
		objects = new T[this->theCapacity];
		for (int i = 0; i < this->theSize; i++)
		{
			objects[i] = rhs.objects[i];
		}
		return *this;
	}

	//����size  
	void resize(int newSize)
	{
		if (newSize > theCapacity)
			reserve(newSize * 2 + 1);
		theSize = newSize;
	}

	// ����Ԥ���Ŀռ䣬Ҳ����ʵ����������ڴ�Ĵ�С;
	void reserve(int newCapacity)
	{
		if (newCapacity < theSize)
		{
			return;
		}

		T* oldObject = objects;
		objects = new T[newCapacity];
		theCapacity = newCapacity;
		for (int i = 0; i < theSize; i++)
		{
			objects[i] = oldObject[i];
		}
		delete []oldObject;
	}

	//����[]������  
	T& operator[](int index)
	{
		return *(objects + index);
	}
	const T& operator[](int index)const
	{
		return *(objects + index);
	}

	//����get��������Ϊconst��Ա����֤const����Ҳ�ܵ���  
	bool isEmpty() const
	{
		return getSize() == 0;
	}
	int capacity() const
	{
		return theCapacity;
	}
	int size() const
	{
		return theSize;
	}

	// push��pop����;
	void push_back(T t)
	{
		if (theSize == theCapacity)
		{
			reserve(theCapacity * 2 + 1);
		}
		objects[theSize++] = t;
	}
	void pop_back()
	{
		theSize--;
	}
	T& back()
	{
		return objects[theSize - 1];
	}
	const T& back()const
	{
		return objects[theSize - 1];
	}

	// ������  
	typedef T* iterater;
	typedef const T* const_iterater;

	//begin end �Ȳ���  
	iterater begin()
	{
		return objects;
	}
	const_iterater begin() const
	{
		return objects;
	}
	iterater end()
	{
		return (objects + theSize);
	}
	const_iterater end() const
	{
		return (objects + theSize);
	}
	enum { SPACE_CAPACITY = 16 };

private:
	T* objects;
	int theSize;
	int theCapacity;
};

#endif // _PS_VERTOR_H