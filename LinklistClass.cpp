#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class LinkList;
typedef int Datatype;
class Node
{
	friend LinkList;
	friend ostream& operator<<(ostream& os,const Node& x);
	friend ostream& operator<<(ostream& os,const LinkList& L);
public:
	Node(const Datatype data = 0)
		:_data(data)
		,_pnext(NULL)
	{
	}
private:
	Datatype _data;
	Node *_pnext;
};
ostream& operator<<(ostream& os,const Node& x)
{
	os<<x._data<<" ";
	return os;
}
class LinkList
{
	friend ostream& operator<<(ostream& os,const LinkList& L);
public:
	LinkList()
		:_phead(NULL)
		,_ptail(NULL)
	{
		cout<<"LinkList()"<<endl;
	}
    ~LinkList()
	{
		Node *cur = _phead; 
		while(cur)
		{
			Node* tmp = cur;
			cur = cur->_pnext;
			delete tmp;
		}
	}
	LinkList& Pushback(Datatype x)
	{
		Node *tmp = new Node(x);
	    if(_ptail != NULL)
		{
			_ptail->_pnext = tmp;
			_ptail = tmp;
		}
		else
		{
			_ptail = tmp;
			_phead = tmp;
		}
		return *this;
	}
	LinkList& PushFront(Datatype x)
	{
		Node *tmp = new Node(x);
		if(_phead != NULL)
		{
			tmp->_pnext = _phead;
			_phead = tmp;
		}
		else
		{
			_phead = tmp;
			_ptail = tmp;
		}
		return *this;
	}
	LinkList& Popback()
	{
		if(_ptail != NULL)
		{
			Node *tmp = _phead;
			while(tmp->_pnext != _ptail)
			{
				tmp = tmp->_pnext;
			}
			delete tmp->_pnext;
			tmp->_pnext = NULL;
			_ptail = tmp;
		}
		return *this;
	}
	LinkList& PopFront()
	{
		if(_phead != NULL)
		{
			Node* tmp = _phead;
			_phead = tmp->_pnext;
			delete tmp;
		}
		return *this;
	}
	Node* Find(Datatype x)//
	{
		if(_phead != NULL)
		{
			Node *cur = _phead;
			while(cur)
			{
				if(cur->_data == x)
				{
					break;
				}
				cur = cur->_pnext;
			}
			if(cur!= NULL)
			{
				return cur;
			}
			else
			{
				cout<<"Not found!"<<endl;
			}
		}
		else
		{
			cout<<"Not found!"<<endl;
		}
		return NULL;
	}
	LinkList& Insert(Datatype pos,Datatype x)//在指定位置后插入
	{
		Node *ret = Find(pos);
		Node *newnode = new Node(x);
		if(ret != NULL)
		{
			newnode->_pnext = ret->_pnext;
			ret->_pnext = newnode;
		}
		else
		{
			cout<<"没有该位置"<<endl;
		}
		return *this;
	}
	LinkList& Remove(Datatype x) //
	{
		if(_phead != NULL)
		{
			if(_phead->_data == x)
			{
				PopFront();
			}
			else if(_ptail->_data == x)
			{
				Popback();
			}
			else
			{
			    Node* cur = _phead;
				while(cur->_pnext)
				{
					if(cur->_pnext->_data == x)
					{
						break;
					}
					cur = cur->_pnext;
				}
				if(cur->_pnext != NULL)
				{
					Node *del = cur->_pnext;
					cur->_pnext = del->_pnext;
					delete del;
				}
				else
				{
					cout<<" 没有该元素"<<endl;
				}
			}
		}
		else
		{
			cout<<" 没有该元素"<<endl;
		}
		return *this;
	}
	void RemoveALL()
	{
		if(_phead != NULL)
		{
			Node* cur = _phead;
			while(cur)
			{
				Node* tmp = cur;
                cur = cur->_pnext;
				delete tmp;
			}
		}
		_phead = NULL;
		_ptail = NULL;
	}
	void BubbleSort()
	{
		Node *cur = _phead;
		Node *tmp = NULL;
		Node *tail = NULL;
		Datatype temp = 0;
		while(cur->_pnext!=tail)
		{
			tmp = cur;
			while(tmp->_pnext!=tail)
			{
				if((tmp->_data) > (tmp->_pnext->_data))
				{
					temp = tmp->_data;
					tmp->_data = tmp->_pnext->_data;
					tmp->_pnext->_data = temp;
				}
				tmp = tmp->_pnext;
			}
			tail = tmp;
		}
	}
private:
	Node *_phead;
	Node *_ptail;
};
ostream& operator<<(ostream& os,const LinkList& L)
{
	if(L._phead != NULL)
	{
		Node *cur = L._phead; 
		while(cur)
		{
			os<<*cur;
			cur = cur->_pnext;
		}
	}
	return os;
}
void test()
{
	LinkList mylist;
	mylist.Pushback(5);
	mylist.Pushback(1);
	mylist.Pushback(10);
	mylist.Pushback(9);
	mylist.PushFront(0);
	mylist.BubbleSort();
	cout<<mylist<<endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}
