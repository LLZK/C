
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

template<typename T> 
struct DataDelete
{
	void operator()(T *ptr)
	{
		delete ptr;
	}
};
struct FileHandle
{
	void operator()(void *ptr)
	{
		fclose((FILE*) ptr);
	}
};
template<typename T>
struct Free
{
	void operator()(T *ptr)
	{
		free(ptr);
	}
};
template<typename T,typename D = DataDelete>
class SharedPtr
{
public:
	SharedPtr(T* ptr = NULL)
		:_ptr(ptr)
		,_pCount(new int(1))
		,_del(D())
	{
		cout<<"SharedPtr(T* ptr = NULL)"<<endl;
	}
	~SharedPtr()
	{
		if((*_pCount)-- == 0)
		{
			//delete _ptr;
			_del(_ptr);
			delete _pCount;
			_ptr = NULL;
			_pCount = NULL;
		}
		cout<<"~SharedPtr()"<<endl;
	}
	SharedPtr(const SharedPtr<T,D>& sp)
		:_ptr(sp._ptr)
		,_pCount(sp._pCount)
	{
		(*_pCount)++;
		cout<<"SharedPtr(const SharedPtr& sp)"<<endl;
	}
	SharedPtr<T,D>& operator=(const SharedPtr<T,D>& sp)
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
	D _del;
};

void test()
{
	SharedPtr<int,DataDelete<int> > sp1(new int(2));
	SharedPtr<FILE,FileHandle> sp2(fopen("test.txt","w"));
	SharedPtr<char,Free<char> > sp3((char*)malloc(sizeof(int)));
}
int main()
{
	test();
	system("pause");
	return 0;
}

