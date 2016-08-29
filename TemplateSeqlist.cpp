#include<iostream>
#include<string>
#include<cassert>
using namespace std;

template<typename T>
class Seqlist
{
	template<typename S>
	friend ostream& operator<<(ostream &os,const Seqlist<S>& s)
	{
		if(s._data!=NULL)
		{
			for(int i = 0;i<s._sz;i++)
			{
				os<<s._data[i]<<" ";
			}
		}
		return os;
	}
public:
	Seqlist();
	~Seqlist();
	Seqlist(const Seqlist& s);
	Seqlist& operator=(const Seqlist& s)
	{
		_sz = s._sz;
		_capacity = s._capacity;
		_data = new T[_capacity];
		for(int i =0;i< _sz;i++)
		{
			_data[i] = s._data[i];
		}
	}
	T& operator[](int pos)
	{
		assert(pos>=0);
		assert(pos<_sz);
		return _data[pos];
	}
	void DisPlay();
	void PushBack(const T &t);
	void PushFront(const T &t);
	void PopBack();
	void PopFront(); 
	void Insert(int pos,const T& t);
	void Remove(const T& t);
	void RemoveAll();
	void BubbleSort();
	void InsertSort();
	void SelectSort();
	int Equal(T &t1,T &t2);
	void Sort();
	int myreserve(int capacity);
private:
	void CheckCapacity()
	{
		if(_sz == _capacity)
		{
			int NewCapacity = 2*_capacity+3;
			T* tmp = new T[NewCapacity];
			for(int i = 0;i < _sz;i++)
			{
				tmp[i] = _data[i];
			}
			delete[] _data;
			_data = NULL;
			_data = tmp;
			_capacity = NewCapacity;
		}

	}
private:
	T* _data;
	int _sz;
	int _capacity;
};

template<typename T>
Seqlist<T>::Seqlist()
	:_sz(0)
	,_capacity(3)
	,_data(NULL)
{
	_data = new T[_capacity];
}
template<typename T>
Seqlist<T>::~Seqlist()
{
	if(_data != NULL)
	{
		delete[] _data;
		_data = NULL;
		_sz = 0;
		_capacity = 0;
	}
}
template<typename T>
Seqlist<T>::Seqlist(const Seqlist& s)
	:_sz(s._sz)
	,_capacity(s._capacity)
	,_data(new T[s._capacity])
{
	for(int i = 0;i<_sz;i++)
	{
		_data[i] = s._data[i];
	}
}
template<typename T>
void Seqlist<T>::PushFront(const T &t)
{
	CheckCapacity();
	if(_sz == 0 )
	{
		_data[0] = t;
		_sz++;
	}
	else
	{
		int tmp = _sz;
		for(int i = 0;i<_sz;i++)
		{
			_data[tmp] = _data[tmp-1];
			tmp--;
		}
		_data[0] = t;
		_sz++;
		
	}
}
template<typename T>
void Seqlist<T>::PushBack(const T &t)
{
	CheckCapacity();
    _data[_sz] = t;
	_sz++;
}
template<typename T>
void Seqlist<T>::PopBack()
{
	if(_data != NULL)
	{
		_sz--;
	}
	else
	{
		cout<<"顺序表已空！"<<endl;
	}
}
template<typename T>
void Seqlist<T>::PopFront()
{
	if(_data != NULL)
	{
		for(int i = 0;i < _sz-1;i++)
		{
			_data[i] = _data[i+1];
		}
		_sz--;
	}
	else
	{
		cout<<"顺序表已空！"<<endl;
	}
}
template<typename T>
void Seqlist<T>::Insert(int pos,const T &t)//在第pos个后插入
{
	CheckCapacity();
    if(pos == _sz)
	{
		PushBack(t);
	}
	else if(pos == 0)
	{
		PushFront(t);
	}
	else
	{
		int tmp = _sz;
		for(int i = 0;i <= (_sz-pos);i++ )
		{
			_data[tmp] = _data[tmp - 1];
			tmp--;
		}
		_data[pos] = t;
		_sz++;
	}
}
template<typename T>
void Seqlist<T>::DisPlay()
{
	if(_data!=NULL)
	{
		for(int i = 0;i< _sz;i++)
		{
			cout<<_data[i]<<" ";
		}
        cout<<endl;
	}
}
template<typename T>
void Seqlist<T>::Remove(const T& t)
{
	if(_data != NULL)
	{
		int i = 0;
		int j =0;
		while(i <_sz)
		{
			if(_data[i] == t)
			{
				int tmp = i;
				for(j = 0;j<(_sz-i-1);j++)
				{
					_data[tmp] = _data[tmp+1];
					tmp++;
				}
			    _sz--;
			}
			else
			{
			i++;
			}
		}
	}
}
template<typename T>
void Seqlist<T>::RemoveAll()
{
	if(_data != NULL)
	{
		delete[] _data;
		_data = NULL;
		_sz = 0;
		_capacity = 0;
	}
}
template<typename T>
void Seqlist<T>::BubbleSort()
{
	if(_data != NULL)
	{
		int i = 0;
		int j = 0;
		int k = _sz-1;
		int flag = 0;
		int m = 0;
		for(i = 0;i<_sz -1;i++)
		{
			for(j = 0;j<k;j++)
			{
				if(_data[j]>_data[j+1])
				{
					T tmp = _data[j];
					_data[j] = _data[j+1];
					_data[j+1] = tmp;
					flag = 1;
					m = j;
				}
			}
			if(flag == 0)
			{
				break;
			}
			k= m;
		}
	}
}
template<typename T>
void Seqlist<T>::InsertSort()
{
	int i = 0;
	int j = 0;
	for(i = 1;i<_sz;i++)
	{
		j = i - 1;
		T tmp = _data[i];
		while(j>=0&&_data[j]>tmp)
		{
			_data[j+1] = _data[j];
			j--;
		}
		_data[j+1] = tmp;
	}
}
template<typename T>
void Seqlist<T>::SelectSort()
{
	int i = 0;
	int j = 0;
	int min = 0;
	for(i = 0;i<_sz-1;i++)
	{
		min = i;
		for(j = i;j<_sz;j++)
		{
			if(_data[min]>_data[j])
			{
				min = j;
			}
		}
		if(min != i)
		{
			T tmp = _data[min];
			_data[min] = _data[i];
			_data[i] = tmp;
		}
	}
}
template<typename T>
int Seqlist<T>::Equal(T &t1,T &t2)
{
	return t1>t2;
}
template<typename T>
void Seqlist<T>::Sort()
{
	if(_data != NULL)
	{
		int i = 0;
		int j = 0;
		int k = _sz-1;
		int flag = 0;
		int m = 0;
		for(i = 0;i<_sz -1;i++)
		{
			for(j = 0;j<k;j++)
			{
				if(Equal(_data[j],_data[j+1])>0)
				{
					T tmp = _data[j];
					_data[j] = _data[j+1];
					_data[j+1] = tmp;
					flag = 1;
					m = j;
				}
			}
			if(flag == 0)
			{
				break;
			}
			k= m;
		}
	}
}
template<typename T>
int Seqlist<T>::myreserve(int capacity)
{
	    assert(capacity >= _sz);

		int NewCapacity = capacity; 
		T* tmp = new T[NewCapacity];
		for(int i = 0;i < _sz;i++)
		{
			tmp[i] = _data[i];
		}
		delete[] _data;
		_data = NULL;
		_data = tmp;
		_capacity = NewCapacity;
	    return _capacity;
}
//template<typename S>
//ostream& operator<<(ostream &os,const Seqlist<S>& s)
//{
//	if(s._data!=NULL)
//	{
//		for(int i = 0;i<s._sz;i++)
//		{
//			os<<s._data[i]<<" ";
//		}
//	}
//	return os;
//}
void test()
{
	Seqlist<string>mylist;
	mylist.PushBack("1");
	mylist.PushBack("2aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	mylist.PushBack("3asd");
	mylist.PushBack("4sdasd");
	mylist.PushBack("5");
	mylist.PushFront("6");
	mylist.Sort();
	Seqlist<string> s(mylist);
	//s.DisPlay();
	cout<<s<<endl;
	//mylist.DisPlay();
}
int main()
{
	test();
	system("pause");
    return 0;
}

