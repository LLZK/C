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

//��ʼ��
void InitLinklist(pLinkList pList);
//�˵�
void menu();
//��������
void Destroylist(pLinkList pList);
//β��
void PushBack(pLinkList pList,Datatype x);
//βɾ
void Popback(pLinkList pList);
//ͷ��
void Pushfront(pLinkList pList,Datatype x);
//ͷɾ
void Popfront(pLinkList pList);
//��ӡ����
void Printlist(pLinkList pList);
// ����ָ��Ԫ�ص�λ��
pListNode FindNode(pLinkList pList,Datatype x);
//ָ��λ��ǰ����
void Insert(pLinkList pList,pListNode pos,Datatype x);
//ɾ��ָ��Ԫ��
void Remove(pLinkList pList,Datatype x);
//ɾ��ȫ��
void RemoveALL(pLinkList pList);
//����ָ��λ��
void Erase(pLinkList pList,pListNode pos);
//ð������
void BubbleSort(pLinkList pList);
//ʵ����������
void Reverselist(pLinkList pList);
//��û��ͷ�������£���ָ��λ��ǰ����һ��Ԫ��
void InsertFrontNode(pListNode pos,Datatype x);
//�����м���
pListNode FindMid(pLinkList pList);
//ɾ��������k����㣬k>1&&k<=size
void Delbackn(pLinkList pList);


void menu()
{
 printf("1:βɾ\n");
 printf("2:ͷɾ\n");
 printf("3:β��\n");
 printf("4:ͷ��\n");
 printf("5:ָ��λ��ǰ�����\n");
 printf("6:ɾ��ָ��\n");
 printf("7:ɾ��ȫ��\n");
 printf("8:��ӡ\n");
 printf("9:����ָ��λ��\n");
 printf("10:ð������\n");
 printf("11:����\n");
 printf("12:����\n");
 printf("13��(��û�и���ͷ��������)\n  ��ָ��λ��ǰ����\n");
 printf("14:�����м�׶ε�\n");
 printf("15:ɾ��������k�����\n");
 printf("0:�˳�\n");
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
	  printf("�����ѿգ�\n");
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
	  printf("�����ѿգ�\n");
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
   printf("�����ѿգ�\n");
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

void Insert(pLinkList pList,pListNode pos,Datatype x)//ָ��λ��pos�ĺ���
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
printf("�����ѿգ��޷����룡\n");
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
  printf("������û�и�λ�ã�");
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
    printf("�����ѿգ�\n");
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
	  printf("�����ѿ� ��\n");
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
   printf("�����ѿգ�\n");
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
  printf("������û�и�λ�ã�\n");
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
   printf("�����ѿգ�\n");
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
 //�����½��
newnode = (pListNode)malloc(sizeof(ListNode));
if(NULL == newnode)
{
	printf("out of memory");
	exit(EXIT_FAILURE);
}
newnode->data = x;
newnode->next=NULL;
//����
newnode->next = pos->next;
pos->next = newnode;
//��������
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
	  printf("������ѡ�\n");
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
		printf("������Ҫ��������ݣ�\n");
		scanf("%d",&x);
		PushBack(&mylist,x);
		break;
	case PUSF:
		printf("������Ҫ��������ݣ�\n");
		scanf("%d",&x);
		Pushfront(&mylist,x);
		break;
	case INSE:
		printf("������Ҫ��������ݣ�\n");
		scanf("%d",&x);
		printf("������Ҫ�����λ�ã��ĸ�����֮ǰ��:\n");
		scanf("%d",&pos);
		Insert(&mylist,FindNode(&mylist,pos),x);
		break;
	case REMO:
		printf("������Ҫɾ�������ݣ�\n");
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
		printf("������Ҫ������λ�ã���һ�����֣���\n");
		scanf("%d",&pos);
		Erase(&mylist,FindNode(&mylist,pos));
		break;
	case BUBBL:
		BubbleSort(&mylist);
		break;
	case FIND:
		printf("������Ҫ���ҵ����֣�");
		scanf("%d",&pos);
		FindNode(&mylist,pos);
		printf("%p",FindNode(&mylist,pos));
	case REVERSE:
		Reverselist(&mylist);
		break;
	case INSEF:
		printf("������Ҫ��������ݣ�\n");
		scanf("%d",&x);
		printf("������Ҫ�����λ�ã��ĸ�����֮ǰ��:\n");
		scanf("%d",&pos);
		InsertFrontNode(FindNode(&mylist,pos),x);
		break;
	case FINDM:
		ret = FindMid(&mylist);
		printf("�м���Ϊ %d\n",ret->data);
		break;
	case DELB:
		printf("������k��ֵ��");
		scanf("%d",&k);
		Delbackn(&mylist,k);
		break;
	case EXIT:
		return 0;
		break;
	default:
		printf("�������\n");
		break;
	}
  }
  system("pause");
  return 0;
}
