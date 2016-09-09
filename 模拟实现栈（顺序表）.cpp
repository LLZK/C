#include<iostream>
using namespace std;

template<typename T>
class Stack
{
public:
	Stack()
		:_data(NULL)
		,_sz(0)
		,_capacity(0)
	{}
	~Stack()
	{
		if(_data != NULL)
		{
			delete[] _data;
			_sz = 0;
			_capacity = 0;
		}
	}
	void Push(const T& t)
	{
		CheckCapacity();
		_data[_sz] = t;
		_sz++;
	}
	void Pop()
	{  
		if(_sz!=0)
		{
			_sz--;
		}
	}
	bool Empty()
	{
		return _sz==0;
	}
	T& Top()
	{
		return _data[_sz-1]; 
	}
	size_t Getsize()
	{
		return _sz;
	}
	void Display()
	{
		while(_sz != 0)
		{
			cout<<Top()<<" ";
			Pop();
		}
		cout<<endl;
	}
protected:
	void CheckCapacity()
	{
		if(_sz == _capacity)
		{
			size_t Newcapacity = _capacity*2+3;
			T* tmp = new T[Newcapacity];
			for(size_t i = 0;i<_sz;i++)
			{
				tmp[i] = _data[i];
			}
			T* del = _data;
			_data = tmp;
			delete del;
			del = NULL;
			_capacity = Newcapacity;
		}
	}
private:
	T *_data;
	size_t _sz;
	size_t _capacity;
};

void TestStack()
{
	Stack<int> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);
	s1.Display();
	cout<<s1.Getsize()<<endl;
}

int main()
{
	TestStack();
	system("pause");
	return 0;
} 
