#include<stdio.h>
#include<stdlib.h>
   void Inboard(char ar[3][3])// ��ʼ������ 
    {
     char *p=&ar[0][0];
     int sz=sizeof(ar)/sizeof(ar[0][0]);
     int i=0;
     for(i=0;i<=sz;i++)
      {
      	*(p+i)=' ';
	  }
	}
	
   void print(char ar[3][3])//��ӡ 
    {
      printf("%c  | %c | %c",ar[0][0],ar[1][0],ar[2][0]);
	  printf("\n-----------");
	  printf("\n%c  | %c | %c",ar[0][1],ar[1][1],ar[2][1]);
	  printf("\n-----------");
	  printf("\n%c  | %c | %c",ar[0][2],ar[1][2],ar[2][2]);
	  printf("\n");
	}
  void human(char ar[3][3])// ���� 
    {
       int i,j;
       printf("�ˣ�\n");
       scanf("%d %d",&i,&j);
       if(ar[i][j]=='x'||ar[i][j]=='y')
       {
       	printf("\n���󣡣�����\n���������룺");
       	scanf("%d %d",&i,&j);
	   }
       ar[i][j]='x';
	}
  void computer(char ar[3][3])//������ 
   {
   	int i,j;
   	printf("\n\n���ԣ�"); 
   	i=rand()%3;
   	j=rand()%3;
   	while(ar[i][j]=='x'||ar[i][j]=='y')
   	{
   	  i=rand()%3;
   	  j=rand()%3;
	}
   	ar[i][j]='y';
	} 
  void judge(char ar[3][3],int *pn)
   {
   	int i=0;
   	int j=0;
   	for(i=0,j=0;i<=2;i++,j++)
   	  {
   	if(ar[i][0]==ar[i][1]&&ar[i][2]==ar[i][0])
   	   {
   	     if(ar[i][0]=='x')
   	     {
   	       printf("��ϲ���ʤ������"); 
   	      *pn--;
   	     }
		 else if(ar[i][0]=='y') 
		 {
		   printf("���ʤ�ԣ�������");
		    *pn--;
	     }
		 else 
		 {
		   
		    break;
		 }
		 
	   }
	else if(ar[0][j]==ar[1][j]&&ar[0][j]==ar[2][j])
	   {
		 if(ar[0][j]=='x')
   	     {
   	       printf("��ϲ���ʤ������"); 
   	        *pn--;
   	     }
		 else if(ar[0][j]=='y') 
		 {
		   printf("���ʤ�ԣ�������");
		    *pn--;
	     }
		 else 
		 {
		    break;
		 }
       }
    else if(ar[0][0]==ar[1][1]&&ar[0][0]==ar[2][2])
        {
    	 if(ar[0][0]=='x')
   	     {
   	       printf("��ϲ���ʤ������"); 
   	          *pn--;
   	     }
		 else if(ar[0][0]=='y') 
		 {
		   printf("���ʤ�ԣ�������");
		  *pn--;
	     }
		 else 
		 {
		    break;
		 }
	   }

	    
    else if(ar[0][2]==ar[1][1]&&ar[0][2]==ar[2][0])
        {
    	 if(ar[0][2]=='x')
   	     {
   	       printf("��ϲ���ʤ������"); 
   	      *pn--;
   	     }
		 else if(ar[0][2]=='y') 
		 {
		   printf("���ʤ�ԣ�������");
		     *pn--;
	     }
		 else 
		 {
		    break;
	 	 }
    	}

      }
 
    
 }

  int main()
   {
   	int i=0;
   	int n=1;
   	int tmp=0;
   	int *p=&n;
   	char ar[3][3];
   	printf("******��ӭ����������******\n");
   	printf("����Ϊ��\n");
   	printf("0 0   1 0   2 0\n");
   	printf("0 1   1 1   2 1\n");
   	printf("0 2   1 2   2 2\n");
   	printf("�ˣ� x\n���ԣ� y\n������\n"); 
   	printf("�����壺") ;
   	Inboard(ar);//��ʼ������ 
   	printf("\n");
   	print(ar);
   	for(i=0;i<=4;i++) 
   	{
   		human(ar);
		print(ar);
		computer(ar);
     	printf("\n");
     	print(ar);
     	judge(ar,p);
     	if(n==0)
     	 {
     	 return 0;
		 }
    }  
	} 
