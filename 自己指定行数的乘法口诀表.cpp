//�Լ�ָ�������ĳ˷��ھ��� 
#include<stdio.h>
 int main()
   {
   	int i=1;
   	int j=1;
   	int n; 
   	printf("������������");
   	scanf("%d",&n);
   	for(j=1;j<=n;j++)
   	 {
   	for(i=1;i<=j;i++)
   	  { 
   	  printf("%d*%d=%d ",i,j,i*j);
      } 
      printf("\n");
    }
    return 0;
   }
