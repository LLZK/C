//自己指定行数的乘法口诀表 
#include<stdio.h>
 int main()
   {
   	int i=1;
   	int j=1;
   	int n; 
   	printf("请输入行数：");
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
