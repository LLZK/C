#include<iostream>
using namespace std;

template<typename T>
class AutoPtr
{
public:
	AutoPtr(T* ptr = NULL)
		:_ptr(ptr)
	{
		cout<<"AutoPtr()"<<endl;
	}
	AutoPtr(AutoPtr& ap)
	{   
		_ptr = ap._ptr; 
		delete ap._ptr;
		ap._ptr = NULL;
	}
	AutoPtr<T>& operator=(AutoPtr& ap)
	{
		if(_ptr != ap._ptr)
		{
			delete _ptr;
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}
	T* operator->()
	{
		return _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
	~AutoPtr()
	{
		cout<<"~AutoPtr()"<<endl;
		delete _ptr;
	}
private:
	T* _ptr;
};
void test()
{
	AutoPtr<int> a(new int(1));
	cout<<*a<<endl;
	
	AutoPtr<int> b;
	b = a;
	cout<<*b<<endl;
}
int main()
{
	test();
	return 0;
 } 
