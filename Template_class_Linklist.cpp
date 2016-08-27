#include<iostream>
#include<cassert>
using namespace std;

template<typename T>
struct Node
{
	Node(const T& data)
		:_next(NULL)
		,_prev(NULL)
		,_data(data)

	{}
	T _data;
	Node *_next;
	Node *_prev;
};

template<typename T>
class Linklist
{
public:
	Linklist()
		:_head(NULL)
		,_tail(NULL)
		,_sz(0)
	{}
	Linklist(const Linklist& l)
		:_head(NULL)
		,_tail(NULL)
	{
		if(l._head != NULL)
		{
			Node<T> *cur = l._head;
			while(cur)
			{
				PushBack(cur->_data);
				cur = cur->_next;
			}
		}
	}
	~Linklist()
	{
		if(_head != NULL)
		{
			Node<T> *cur = _head;
			while(cur)
			{
				Node<T>* del = cur;
				cur = cur->_next;
				delete del;
			}
		}
	}
	Linklist& operator=(Linklist l)
	{
		std::swap(_head,l._head);
		std::swap(_tail,l._tail);
		return *this;
	}
	void PushBack(const T& t);
	void PushFront(const T& t);
	void PopBack();
	void PopFront();
	void Remove(const T& t);
	void RemoveAll();
	void Sort();
	bool compare(const T& t1,const T& t2);
	void Insert(int pos,const T& t);
	void my_unique();
	void my_merge( Linklist& l);
	void my_reverse();
	void my_swap(Linklist &l);
	void Display();

private:
	Node<T>* _head;
	Node<T>* _tail;
	int _sz;
};

template<typename T>
void Linklist<T>::PushBack(const T& t)
{
	Node<T> *tmp = new Node<T>(t);
	if(_head != NULL)
	{
		_tail->_next = tmp;;
		tmp->_prev = _tail;
		_tail = tmp;
	}
	else
	{
		_head = tmp;
		_tail = tmp;
	}
	_sz++;
}
template<typename T>
void Linklist<T>::PushFront(const T& t)
{
	Node<T> *tmp = new Node<T>(t);
	if(_head != NULL)
	{
		tmp->_next = _head;
		_head->_prev = tmp;
		_head = tmp;
	}
	else
	{
		_head = tmp;
		_tail = tmp;
	}
	_sz++;
}
template<typename T>
void Linklist<T>::PopBack()
{
	if(_head==NULL)
	{
	}
	else if(_head->_next == NULL)
	{
		delete _head;
		_head = NULL;
		_tail = NULL;
	}
	else
	{
		Node<T> *tmp = _tail;
		_tail = _tail->_prev;
		_tail->_next = NULL;
		delete tmp;
	}
	_sz--;
}
template<typename T>
void Linklist<T>::PopFront()
{
	if(_head == NULL)
	{
	}
	else if(_head->_next == NULL)
	{
		delete _head;
		_head = NULL;
		_tail = NULL;
	}
	else
	{
		Node<T> *tmp = _head;
		_head = _head->_next;
		_head->_prev = NULL;
		delete tmp;
	}
	_sz--;
}
template<typename T>
void Linklist<T>::Display()
{
	if(_head!=NULL)
	{
		Node<T>* cur = _head;
		while(cur)
		{
			cout<<cur->_data<<" ";
			cur = cur->_next;
		}
		cout<<endl;
	}
}
template<typename T>
void Linklist<T>::Remove(const T& t)
{
	if(_head != NULL)
	{
		Node<T> *cur = _head;
		while(cur)
		{
			if(cur->_data == t)
			{
				if(cur == _head)
				{
					cur = cur->_next;
					PopFront();
				}
				else if(cur == _tail)
				{
					cur = cur->_next;
					PopBack();
				}
				else
				{
					Node<T> *del = cur;
					Node<T> *front = cur->_prev;
					Node<T> *back = cur->_next;
					cur = cur->_next;
					front->_next = back;
					back->_prev = front;
					delete del;
				}
				_sz--;
			}
			else
			{
				cur = cur->_next;
			}
		}
	}
}
template<typename T>
void Linklist<T>::RemoveAll()
{
	if(_head != NULL)
	{
		Node<T> *cur = _head;
		while(cur)
		{
			Node<T> *del = cur;
			cur = cur->_next;
			delete del;
		}
		_head = NULL;
		_tail = NULL;
		_sz = 0;
	}
}
template<typename T>
bool Linklist<T>::compare(const T& t1,const T& t2)
{
	return t1>t2;
}
template<typename T>
void Linklist<T>::Sort()
{
	if(_head != NULL)
	{
		Node<T> *cur = _head;
		Node<T> *tmp = NULL;
		Node<T> *flag = NULL;
		while(cur->_next != flag)
		{
			tmp = cur;
			while(tmp->_next != flag)
			{
				if(compare(tmp->_data,tmp->_next->_data))
				{
					T temp = tmp->_data;
					tmp->_data = tmp->_next->_data;
					tmp->_next->_data = temp;
				}
				tmp = tmp->_next;
			}
			flag = tmp;	
		}
	}
}
template<typename T>
void Linklist<T>::Insert(int pos,const T& t)//在第pos个后面插入
{
	assert(pos<=_sz);

	if(_head != NULL)
	{
		if(pos == 0)
		{
			PushFront(t);
		}
		else if(pos == _sz)
		{
			PushBack(t);
		}
		else
		{
			int i = 1;
			Node<T> *cur = _head;
			Node<T> *tmp = new Node<T>(t);
			while(i<pos)
			{
				cur = cur->_next;
				i++;
			}
			tmp->_next = cur->_next;
			cur->_next->_prev = tmp;
			cur->_next = tmp;
			tmp->_prev = cur;
			_sz++;
		}
	}
}
template<typename T>
void Linklist<T>::my_unique()
{
	if(_head != NULL)
	{
		Sort();
		Node<T> *cur = _head;
		while(cur->_next)
		{
			if(cur->_data == cur->_next->_data)
			{
				Node<T> *del = cur->_next;
				cur->_next = cur->_next->_next;
				cur->_next->_prev = cur;
				delete del;
				_sz--;
			}
			else
			{
				cur = cur->_next;
			}
		}
	}
}
template<typename T>
void Linklist<T>::my_merge(Linklist& l)
{
	Sort();
	l.Sort();
	Node<T> *cur1 = _head;
	Node<T> *cur2 = l._head;
	int pos = 1;
	while(cur2)
	{
		pos = 1;
		cur1 = _head;
		while(cur1)
		{
			if(cur2->_data<=cur1->_data)
			{
				if(cur1 == _head)
				{
					PushFront(cur2->_data);
				}
				else
				{
					Insert(pos-1,cur2->_data);
				}
				break;
			}
			pos++;
			if(pos > _sz)
			{
				PushBack(cur2->_data);
				break;
			}
			cur1 = cur1->_next;
		}
		cur2 = cur2->_next;
	}
	l.RemoveAll();
	
}
template<typename T>
void Linklist<T>::my_reverse()
{
	if(_head != NULL)
	{
		if(_head->_next == NULL)
		{
		}
		else
		{
			/*
			Method 1
			*/
			Node<T> *start = _head;
			Node<T> *end = _tail;
			while(end->_next != start&&start!=end)
			{
				T tmp = start->_data;
				start->_data = end->_data;
				end->_data = tmp;
				start = start->_next;
				end = end->_prev;
			}

			/*
			Method 2
			*/
			//Node<T>* cur = _head;
			//while(cur)
			//{
			//	Node<T> *tmp = cur;
			//	cur = cur->_next;
			//	tmp->_next = tmp->_prev;
			//	tmp->_prev = cur;
			//}
			//Node<T> *tmp = _head;
			//_head = _tail;
			//_tail = tmp;

			/*
			Method 3
			*/
			//Linklist<T>l2;
			//Node<T> *cur = _tail;
			//while(cur)
			//{
			//	l2.PushBack(cur->_data);
			//	cur = cur->_prev;
			//}
			//*this = l2;
		}

	}
}
template<typename T>
void Linklist<T>::my_swap(Linklist& l)
{
	if(_head == NULL && l._head==NULL)
	{
	}
	else
	{
		Node<T> *tmp = _head;
		_head = l._head;
		l._head = tmp;
		tmp = _tail;
		_tail = l._tail;
		l._tail = tmp;
	}
}

/*
Debug code
Write yourself!
*/
void test1()
{
	Linklist<int> l1;
	l1.PushBack(5);
	l1.PushBack(2);
	l1.PushBack(7);
	l1.PushBack(0);
	Linklist<int> l2;
	l2.PushBack(1);
	l2.PushBack(1);
	l2.PushBack(1);
	l1.Display();
	l2.Display();
	l1.my_reverse();
	l1.Display();
	l2.Display();
	//l1.PushBack(3)
	//l1.Sort();
	//l1.Display();
	//l1.my_unique();
	//l1.Display();
	//Linklist<int> l2(l1);
	//l2.Display();
	//l1.my_merge(l2);
	//l1.Display();
	//l1.my_reverse();
	//l1.Display();
	//l1.PopBack();
	//l1.PopFront();
	//l1.RemoveAll();
	//Linklist<int> l2(l1);
	//Linklist<int> l3;
	//l3 = l2;
	//l1.Display();
	//l2.Display();
	//l3.Display();
	//Linklist<string> l1;
	//l1.PushBack("asdsa");
	//l1.PushBack("gfdg");
	//l1.PushBack("ytuyt");
	//l1.PushBack("qq");
	//l1.PushBack("lllllllllllllllllllllllllllllllllllllllllllllllllllll");
	//l1.PushBack("ffff");
	//l1.PushFront("ppppppppppppppppp");
	//l1.Display();
	//l1.Sort();
	//l1.Insert(1,"lzk");

	////l1.PopBack();
	////l1.PopFront();
	////l1.RemoveAll();
	//Linklist<string> l2(l1);
	//Linklist<string> l3;
	//l2.PopBack();
	//l2.PopFront();
	//l3 = l2;
	//l1.Display();
	//l2.Display();
	//l3.Display();
}

int main()
{
	test1();
	system("pause");
	return 0;
}
