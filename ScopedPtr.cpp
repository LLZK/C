#include<iostream>
using namespace std; 
template<typename T>
class ScopedPtr
{
public:
	ScopedPtr(T* ptr = NULL)
		:_ptr(ptr)
	{
	}
	~ScopedPtr()
	{
		delete _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	ScopedPtr(const ScopedPtr& sp);
	ScopedPtr<T>& operator=(const ScopedPtr& sp);
private:
	T* _ptr;
};


