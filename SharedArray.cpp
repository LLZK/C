#include<iostream>
using namespace std; 
template<typename T>
class SharedArray
{
public:
	SharedArray(T* ptr = NULL)
		:_ptr(ptr)
		,_pCount(new int(1))
	{
		cout<<"SharedArray(T* ptr = NULL)"<<endl;
	}
	~SharedArray()
	{
		if((*_pCount)-- == 0)
		{
			delete _ptr;
			delete _pCount;
			_ptr = NULL;
			_pCount = NULL;
		}
		cout<<"~SharedArray()"<<endl;
	}
	SharedArray(const SharedArray& sp)
		:_ptr(sp._ptr)
		,_pCount(sp._pCount)
	{
		(*_pCount)++;
		cout<<"SharedPtr(const SharedArray& sp)"<<endl;
	}
	SharedArray<T>& operator=(const SharedArray& sp)
	{
		if(_ptr != sp._ptr)
		{
			if(*_pCount == 1)
			{
				delete _ptr;
				delete _pCount;
			}
			_ptr = sp._ptr;
			_pCount = sp._pCount;
			(*_pCount)++;
		}
		return *this;
	}
	T& operator[](int index)
	{
		return _ptr[index];
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	int UseCount()
	{
		return *_pCount;
	}
private:
	T* _ptr;
	int *_pCount;
};

void test3()
{
	SharedArray<int> sp1(new int[10]);
	for(int i = 0;i< 10;i++)
	{
		sp1[i] = i;
	}
	SharedArray<int> sp2(sp1);
	cout<<*sp2<<endl;
	SharedArray<int> sp3;
	sp3 = sp2;
	for(int i = 0;i< 10;i++)
	{
		cout<<sp3[i]<<endl;
	}

	cout<<sp1.UseCount()<<endl;
}
int main()
{
	test3();
	system("pause");
	return 0;
}
