#include<iostream>
using namespace std;

template<typename T>
struct QueueNode
{
	QueueNode(const T& data)
		:_data(data)
		,_next(NULL)
		,_prev(NULL)
	{}
	T _data;
	QueueNode * _next;
	QueueNode * _prev;
};

template<typename T>
class Queue
{
public:
	Queue()
		:_head(NULL)
		,_tail(NULL)
		,_sz(0)
	{}
	~Queue()
	{
		QueueNode<T>* cur = _head;
		while(cur)
		{
			QueueNode<T>* del = cur;
			cur = cur->_next;
			delete del;
		}
		_head = NULL;
		_tail = NULL;
	}
	void Push(const T& t)
	{
		QueueNode<T> *tmp = new QueueNode<T>(t);
		if(_head == NULL)
		{
			_head = tmp;
			_tail = tmp;
		}
		else
		{
			_tail->_next = tmp;
			tmp->_prev = _tail;
			_tail = tmp;
		}
		_sz++;
	}
	void Pop()
	{
		if(_head != NULL)
		{
			if(_head->_next = NULL)
			{
				delete _head;
				_head = NULL;
				_tail = NULL;
			}
			else
			{
				QueueNode<T>* del = _head;
				_head = _head->_next;
				_head->_prev = NULL;
				delete del;
				del = NULL;
			}
			_sz--;
		}
	}
	bool Empty()
	{
		return _head != NULL;
	}
	T& Front()
	{
		return _head->_data;
	}
	T& back()
	{
		return _tail->_data;
	}
	void Display()
	{
		QueueNode<T>* cur = _head;
		while(cur)
		{
			cout<<cur->_data<<" ";
			cur = cur->_next;
		}		
	}

private:
	QueueNode<T> *_head;
	QueueNode<T> *_tail;
	int _sz;
};

void TestQueue()
{
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	cout<<q.Empty()<<endl;
	cout<<q.Front()<<endl;
	cout<<q.back()<<endl;
	q.Display();

}
int main()
{
	TestQueue();
	system("pause");
	return 0;
} 
