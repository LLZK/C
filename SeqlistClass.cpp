#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

typedef int DataType;

class SeqList
{
	friend ostream& operator<<(ostream &os,SeqList& seq);
public:
	SeqList()
		:_pdata(NULL)
	    ,_capacity(0)
		,_sz(0)
	{
	}
	SeqList(SeqList & s)
		:_pdata(new DataType[s._capacity])
		,_sz(s._sz)
		,_capacity(s._capacity)
	{
		memcpy(_pdata,s._pdata,_sz*sizeof(DataType));
	}
	~SeqList()
	{
		if(_pdata != NULL)
		{
			delete[] _pdata;
			_pdata = NULL;
			_sz = 0;
			_capacity = 0;
		}
	}
	SeqList& Pushback(DataType x)
	{
		CheckCapacity();
		_pdata[_sz] = x;
		_sz++;
		return *this;
	}
	SeqList& PushFront(DataType x)
	{
		CheckCapacity();
		int tmp = _sz;
		while(tmp)
		{
			_pdata[tmp] = _pdata[tmp - 1];
			tmp--;
		}
		_pdata[0] = x;
		_sz++;
		return *this;
	}
	SeqList& Popback()
	{
		if(_sz != 0)
		{
			_sz--;
		}
		else
		{
			cout<<"顺序表已空！"<<endl;
		}
		return *this;
	}
	SeqList& PopFront()
	{
		if(_sz != 0)
		{
			int tmp = 0;
		    while(tmp<_sz)
		    {
			    _pdata[tmp] = _pdata[tmp+1];
				tmp++;
		    }
		    _sz--;
		}
		else
		{
			cout<<"顺序表已空！"<<endl;
		}
		return *this;
	}
	int Find(DataType pos)
	{
		int tmp = 0;
		while(tmp<_sz)
		{
			if(_pdata[tmp] == pos)
			{
				return tmp+1;
			}
			tmp++;
		}
		return -1;
	}
	SeqList& Insret(DataType pos,DataType x)//在元素pos后插入
	{
		CheckCapacity();
		int ret = Find(pos);
		if(ret != -1)
		{
			if(ret == _sz)
			{
				Pushback(x);
			}
			else
			{
				int tmp = _sz;
				while(tmp>ret)
				{
					_pdata[tmp] = _pdata[tmp-1];
					tmp--;
				}
				_pdata[ret] = x;
			}
		}
		else
		{
			cout<<"没有该位置"<<endl;
		}
        return *this;
	}
	SeqList& Remove(DataType x)
	{
		int pos = Find(x);
		if(pos != -1)
		{
			pos = pos-1;
			if(pos == 0)
			{
				PopFront();
			}
			else if(pos == _sz-1)
			{
				Popback();
			}
			else
			{
				while(pos < _sz-1)
				{
					_pdata[pos] = _pdata[pos+1];
					pos++;
				}
				_sz--;
			}
		}
		else
		{
			cout<<"不存在该元素"<<endl;
		}
		return *this;
	}
	void RemoveAll()
	{
		if(_sz > 0)
		{
			delete[] _pdata;
			_pdata = NULL;
			_sz = 0;
		    _capacity = 0;
		}
	}
    void BubbleSort()
	{
		int i = 0;
		int j = 0;
        int flag = 0;
		int k = _sz-1;
		int m = 0;
		for(i = 0;i < _sz-1;i++)
		{
			flag = 0;
			for(j = 0;j< k;j++)
			{
				if(_pdata[j]>_pdata[j+1])
				{
					DataType tmp = _pdata[j];
					_pdata[j] = _pdata[j+1];
					_pdata[j+1] = tmp;
					flag = 1;
					m = j;
				}
			}
			if(flag == 0)
			{
				break;
			}
			k = m;
		}
	}
	void InsertionSort()
	{
		int i = 0;
		int j = 0;
		for(i = 1;i<_sz;i++)
		{
			j = i-1;
			DataType tmp = _pdata[i];
			while(j>=0&&_pdata[j]>tmp)
			{
				_pdata[j+1] = _pdata[j];
				j--;
			}
			_pdata[j+1] = tmp;
		}
	}
	void SelectSort()
	{
		int i = 0;
		int j = 0;
		int min = 0;
		for(i = 0;i < _sz-1;i++)
		{
			min = i;
			for(j=i;j<_sz;j++)
			{
				if(_pdata[min]>_pdata[j])
				{
					min = j;
				}
			}
			if(min!=i)
			{
				DataType tmp = _pdata[min];
				_pdata[min] = _pdata[i];
				_pdata[i] = tmp;
			}
		}
	}
private:
	void CheckCapacity()
	{
		if(_sz == _capacity)
		{
			int NewCapacity = _capacity+10;
			DataType *tmp = new DataType[NewCapacity];
			memcpy(tmp,_pdata,_sz);
			delete[] _pdata;
			_pdata = tmp;
			_capacity = NewCapacity;
		}
	}
private:
    int _capacity;
	int _sz;
	DataType* _pdata;
};
ostream& operator<<(ostream &os,SeqList &seq)
{
	int tmp = 0;
	while(tmp < seq._sz)
	{
	   os<<seq._pdata[tmp]<<" ";
	   tmp++;
	}
	return os;
}

void menu()
{
	cout<<"1.尾部插入"<<endl;
    cout<<"2.头部插入"<<endl;
	cout<<"3.尾部删除"<<endl;
	cout<<"4.头部删除"<<endl;
	cout<<"5.指定位置后插入"<<endl;
	cout<<"6.查找位置"<<endl;
	cout<<"7.删除某个元素"<<endl;
	cout<<"8.删除全部"<<endl;
	cout<<"9.冒泡排序"<<endl;
	cout<<"10.插入排序"<<endl;
	cout<<"11.选择排序"<<endl;
	cout<<"12.Display"<<endl;
	cout<<"0.退出"<<endl;
}
int main()
{

	SeqList seq;
	menu();
	DataType data;
	DataType pos;
	int ret = 0;
	int start = -1;
	while(start)
	{
		cout<<"请输入选项："<<endl;
		cin>>start;
		switch(start)
		{
		case 1:
			cout<<"请输入要插入的元素"<<endl;
			cin>>data;
			seq.Pushback(data);
			break;
		case 2:
			cout<<"请输入要插入的元素"<<endl;
			cin>>data;
			seq.PushFront(data);
			break;
		case 3:
			seq.Popback();
			break;
		case 4:
			seq.PopFront();
			break;
		case 5:
			cout<<"在指定位置pos后插入\n请输入元素pos："<<endl;
			cin>>pos;
			cout<<"请输入要插入的元素"<<endl;
			cin>>data;
			seq.Insret(pos,data);
			break;
		case 6:
			cout<<"请输入要查找的元素"<<endl;
			cin>>data;
			 ret = seq.Find(data);
			if(ret != -1)
			{
				cout<<"第"<<ret<<"个"<<endl;
			}
			else
			{
				cout<<"不存在该元素"<<endl;
			}
			break;
		case 7:
			cout<<"请输入要删除的元素"<<endl;
			cin>>data;
			seq.Remove(data);
			break;
		case 8:
			seq.RemoveAll();
			break;
		case 9:
			seq.BubbleSort();
			break;
		case 10:
			seq.InsertionSort();
			break;
		case 11:
			seq.SelectSort();
			break;
		case 0:
			return 0;
		case 12:
			cout<<seq<<endl;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
