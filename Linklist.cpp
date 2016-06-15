#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int Datatype;

enum 
{
  EXIT,
  POPB,
  POPF,
  PUSB,
  PUSF,
  INSE,
  REMO,
  REMOA,
  PRINT,
  ERASE,
  BUBBL,
  FIND,
  REVERSE,
  INSEF,
  FINDM,
  DELB
};

typedef struct ListNode
{
  Datatype data;
  struct ListNode *next;
}ListNode,*pListNode;

typedef struct LinkList
{
	ListNode *phead;
}LinkList,*pLinkList;

//初始化
void InitLinklist(pLinkList pList);
//菜单
void menu();
//销毁链表
void Destroylist(pLinkList pList);
//尾插
void PushBack(pLinkList pList,Datatype x);
//尾删
void Popback(pLinkList pList);
//头插
void Pushfront(pLinkList pList,Datatype x);
//头删
void Popfront(pLinkList pList);
//打印链表
void Printlist(pLinkList pList);
// 查找指定元素的位置
pListNode FindNode(pLinkList pList,Datatype x);
//指定位置前插入
void Insert(pLinkList pList,pListNode pos,Datatype x);
//删除指定元素
void Remove(pLinkList pList,Datatype x);
//删除全部
void RemoveALL(pLinkList pList);
//擦除指定位置
void Erase(pLinkList pList,pListNode pos);
//冒泡排序
void BubbleSort(pLinkList pList);
//实现链表逆序
void Reverselist(pLinkList pList);
//在没有头结点情况下，在指定位置前插入一个元素
void InsertFrontNode(pListNode pos,Datatype x);
//查找中间结点
pListNode FindMid(pLinkList pList);
//删除倒数第k个结点，k>1&&k<=size
void Delbackn(pLinkList pList);


void menu()
{
 printf("1:尾删\n");
 printf("2:头删\n");
 printf("3:尾插\n");
 printf("4:头插\n");
 printf("5:指定位置前面插入\n");
 printf("6:删除指定\n");
 printf("7:删除全部\n");
 printf("8:打印\n");
 printf("9:擦除指定位置\n");
 printf("10:冒泡排序\n");
 printf("11:查找\n");
 printf("12:逆序\n");
 printf("13：(在没有给出头结点情况下)\n  在指定位置前插入\n");
 printf("14:查找中间阶段的\n");
 printf("15:删除倒数第k个结点\n");
 printf("0:退出\n");
}

void InitLinklist(pLinkList pList)
{
	assert(pList);
	pList->phead = NULL;
}
void PushBack(pLinkList pList,Datatype x)
{
	pListNode cur = pList->phead;
    pListNode newnode = NULL;
	assert(pList);
	newnode = (pListNode)malloc(sizeof(ListNode));
	if(NULL == newnode)
	{
	   printf("out of memory");
	   exit(EXIT_FAILURE);
	}
	newnode->data = x;
	newnode->next=NULL;
	if(pList->phead == NULL)
	{
	  pList->phead = newnode;
	}
	else
	{
		while(cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}

void Popback(pLinkList pList)
{
	pListNode cur = pList->phead;
	pListNode tmp = NULL;
	assert(pList);
	if(pList->phead == NULL)
	{
	  printf("链表已空！\n");
      return;
	}
	else if(pList->phead->next == NULL)
	{
	  free(pList->phead);
	  pList->phead = NULL;
	}
	else
	{
		while(cur->next->next != NULL)
		{
		  cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void Pushfront(pLinkList pList,Datatype x)
{
    pListNode cur = pList->phead;
    pListNode newnode = NULL;
	assert(pList);
	newnode = (pListNode)malloc(sizeof(ListNode));
	if(NULL == newnode)
	{
	   printf("out of memory");
	   exit(EXIT_FAILURE);
	}
	newnode->data = x;
	newnode->next=NULL;
	if(pList->phead == NULL)
	{
		pList->phead = newnode;
	}
	else
	{
		newnode->next = pList->phead;
		pList->phead = newnode;
	}
}

void Popfront(pLinkList pList)
{
	pListNode cur = NULL;
    assert(pList);
	if(pList->phead == NULL )
	{
	  printf("链表已空！\n");
	  return;
	}
	else
	{
		cur = pList->phead->next;
		free(pList->phead);
		pList->phead = cur;
	}
}
pListNode FindNode(pLinkList pList,Datatype x)
{
  pListNode cur = NULL;
  assert(pList);
  cur = pList->phead;
  if(pList->phead == NULL)
  {
   printf("链表已空！\n");
   return 0;
  }
  else
  {
    while(cur !=NULL)
	{
		if(cur->data == x)
		{
		  return cur;
		}
		cur = cur->next;
	}
  }
  return NULL;
}

void Insert(pLinkList pList,pListNode pos,Datatype x)//指定位置pos的后面
{
pListNode cur = pList->phead;
pListNode prev = NULL;
pListNode newnode = NULL;
assert(pList);
newnode = (pListNode)malloc(sizeof(ListNode));
if(NULL == newnode)
{
	printf("out of memory");
	exit(EXIT_FAILURE);
}
newnode->data = x;
newnode->next=NULL;
if(pList->phead == NULL)
{
printf("链表已空，无法插入！\n");
return;
}
else if(pList->phead == pos)
{
	newnode->next = cur;
	pList->phead = newnode;
}
else
{
  while(cur)
  {
    if(cur == pos)
	{
		newnode->next = cur;
		prev->next = newnode;
		return;;
	}
	prev=cur;
	cur=cur->next;
  }
  printf("链表中没有该位置！");
}

}
  
void Remove(pLinkList pList,Datatype x)
{
  pListNode prve = NULL;
  pListNode cur = pList->phead;
  pListNode tmp = NULL;
  assert(pList);
  if(pList->phead == NULL)
  {
    printf("链表已空！\n");
    return;
  }
  else
  {
    while(cur != NULL)
	{
		
		if(cur->data == x)
		{
			if(cur == pList->phead)
			{
			  Popfront(pList);
			  return ;
			}
			else if(cur->next == NULL)
			{
			  Popback(pList);
			  return;
			}
			else
			{
				prve->next = cur->next;
				free(cur);
				cur =NULL;
				return;
			}
		}
		prve = cur;
		cur = cur->next;
	}
  }
}

void RemoveALL(pLinkList pList)
{
	if(pList->phead == NULL)
	{
	  printf("链表已空 ！\n");
	  return ;
	}
	while(pList->phead != NULL)
	{
	  Popback(pList);
	}
}
void Erase(pLinkList pList,pListNode pos)
{
  pListNode prev = NULL;
  pListNode cur = pList->phead;
  pListNode del = NULL;
  assert(pList);
  if(pList->phead == NULL)
  {
   printf("链表已空！\n");
   return;
  }
  while(cur)
  {
    if(cur == pos)
	{
		if(cur == pList->phead)
		{
		  del = cur;
		  pList->phead = cur->next;
		  free(del);
		  del = NULL;
		  return;
		}
		else
		{
		  del = cur;
		  prev->next = cur->next;
		  free(del);
		  del = NULL;
		  return;
		}
	}
	prev = cur;
	cur = cur->next;
  }
  printf("链表中没有该位置！\n");
  return;
}

void BubbleSort(pLinkList pList)
{
	pListNode cur = pList->phead;
	pListNode tmp = NULL;
	pListNode tail = NULL; 
    Datatype temp = 0;
	assert(pList);
	while(cur!=tail)
	{
		while(tmp ->next != tail)
		{
			if(tmp->data > tmp->next->data)
			{
				temp = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = temp;
			}
			tmp= tmp->next;
		}
		tail = tmp;
	}
}
void Printlist(pLinkList pList)
{
   pListNode cur = pList->phead;
   assert(pList);
   if(pList->phead == NULL)
  {
   printf("链表已空！\n");
   return;
  }
   while(cur != NULL)
   {
	   printf("%d ",cur->data);
	   cur = cur->next;
   }
   printf("\n");
}
void Reverselist(pLinkList pList)
{
	pListNode cur = pList->phead;
  pListNode newhead = NULL;
  pListNode tmp = NULL;
  assert(pList);
  while(cur)
  {
    tmp = cur;
	cur = cur->next;
	tmp->next = newhead;
	newhead = tmp;
  }
  pList->phead = newhead;
}
void InsertFrontNode(pListNode pos ,Datatype x)
{
Datatype tmp = 0;
pListNode newnode = NULL;
 assert(pos);
 //创建新结点
newnode = (pListNode)malloc(sizeof(ListNode));
if(NULL == newnode)
{
	printf("out of memory");
	exit(EXIT_FAILURE);
}
newnode->data = x;
newnode->next=NULL;
//插入
newnode->next = pos->next;
pos->next = newnode;
//交换数据
tmp = pos->data;
pos->data = newnode->data;
newnode->data = tmp;

}

pListNode FindMid(pLinkList pList)
{
	pListNode fast = pList->phead;
	pListNode slow = pList->phead;
	while(fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

void Delbackn(pLinkList pList,int k)
{
	pListNode front = pList->phead;
	pListNode back = pList->phead;
    pListNode del = NULL;
	assert(pList);
	while(front)
	{
	  k--;
	  if(k<0)
	  {
		  back = back ->next;
	  }
	  front = front->next;
	}
	if(k<=0)
	{
		back->data = back->next->data;
		del = back->next;
		back->next=back->next->next;
		free(del);
		del = NULL;
	}
}

int main()
{
  int input = -1;
  int x = 0;
  int pos = 0;
  int k = 0;
  LinkList mylist;
  pListNode tmp = NULL;
  	pListNode ret = NULL;
  InitLinklist(&mylist);
  menu();
  while(1)
  {
	  printf("请输入选项：\n");
	scanf("%d",&input);
    switch(input)
	{
	case POPB:
		Popback(&mylist);
		break;
	case POPF:
		Popfront(&mylist);
		break;
	case PUSB:
		printf("请输入要插入的数据：\n");
		scanf("%d",&x);
		PushBack(&mylist,x);
		break;
	case PUSF:
		printf("请输入要插入的数据：\n");
		scanf("%d",&x);
		Pushfront(&mylist,x);
		break;
	case INSE:
		printf("请输入要插入的数据：\n");
		scanf("%d",&x);
		printf("请输入要插入的位置（哪个数据之前）:\n");
		scanf("%d",&pos);
		Insert(&mylist,FindNode(&mylist,pos),x);
		break;
	case REMO:
		printf("请输入要删除的数据：\n");
		scanf("%d",&x);
		Remove(&mylist,x);
		break;
	case REMOA:
		RemoveALL(&mylist);
		break;
	case PRINT:
		Printlist(&mylist);
		break;
	case ERASE:
		printf("请输入要擦除的位置（哪一个数字）：\n");
		scanf("%d",&pos);
		Erase(&mylist,FindNode(&mylist,pos));
		break;
	case BUBBL:
		BubbleSort(&mylist);
		break;
	case FIND:
		printf("请输入要查找的数字：");
		scanf("%d",&pos);
		FindNode(&mylist,pos);
		printf("%p",FindNode(&mylist,pos));
	case REVERSE:
		Reverselist(&mylist);
		break;
	case INSEF:
		printf("请输入要插入的数据：\n");
		scanf("%d",&x);
		printf("请输入要插入的位置（哪个数据之前）:\n");
		scanf("%d",&pos);
		InsertFrontNode(FindNode(&mylist,pos),x);
		break;
	case FINDM:
		ret = FindMid(&mylist);
		printf("中间结点为 %d\n",ret->data);
		break;
	case DELB:
		printf("请输入k的值：");
		scanf("%d",&k);
		Delbackn(&mylist,k);
		break;
	case EXIT:
		return 0;
		break;
	default:
		printf("输入错误！\n");
		break;
	}
  }
  system("pause");
  return 0;
}
