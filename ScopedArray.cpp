#include<iostream>
using namespace std;
 
template<typename T>
class ScopedArray
{
public:
	ScopedArray(T *ptr = NULL)
		:_ptr(ptr)
	{
	}
	~ScopedArray()
	{
		delete[] _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	T& operator[](int index)
	{
		return _ptr[index];
	}
private:
	ScopedArray(const ScopedArray& sa);
	ScopedArray<T>& operator=(const ScopedArray& sa);
private:
	T* _ptr;
};
void test1()
{
	ScopedArray<int> a1(new int[10]);
	for(int i = 0;i < 10; i++)
	{
		a1[i] = i;
	}
	for(int i = 0;i < 10; i++)
	{
		cout<<a1[i]<<endl;
	}
}
int main()
{
	test1();
	return 0;
}
