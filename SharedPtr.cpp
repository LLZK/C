#include<iostream>
using namespace std;

template<typename T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = NULL)
		:_ptr(ptr)
		,_pCount(new int(1))
	{
		cout<<"SharedPtr(T* ptr = NULL)"<<endl;
	}
	~SharedPtr()
	{
		if((*_pCount)-- == 0)
		{
			delete _ptr;
			delete _pCount;
			_ptr = NULL;
			_pCount = NULL;
		}
		cout<<"~SharedPtr()"<<endl;
	}
	SharedPtr(const SharedPtr& sp)
		:_ptr(sp._ptr)
		,_pCount(sp._pCount)
	{
		(*_pCount)++;
		cout<<"SharedPtr(const SharedPtr& sp)"<<endl;
	}
	SharedPtr<T>& operator=(const SharedPtr& sp)
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

void test2()
{
	SharedPtr<int> sp1(new int(1));
	cout<<*sp1<<endl;
	SharedPtr<int> sp2(sp1);
	cout<<*sp2<<endl;
	SharedPtr<int> sp3;
	sp3 = sp2;
	cout<<*sp3<<endl;
	cout<<sp1.UseCount()<<endl;
} 
int main()
{
	test2();
	return 0;
}
