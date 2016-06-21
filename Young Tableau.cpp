#include<stdio.h>  
#include<stdlib.h>  
  int find_num(int arr[][4],int num)  
  {  
    int i = 0;  
    int j = 3;  
    while(i<=3&&j>=0)  
    {  
      if(num > arr[i][j])         
      {  
        i++;  
      }  
      else if(num < arr[i][j])  
      {  
        j--;  
      }  
      else  
      {  
        return 1;  
      }  
    }  
    return 0;  
  }  
  int main()  
  {  
      int arr[4][4] ={1,2,8,9,  
                      2,4,9,12,  
                      4,7,10,13,  
                      6,8,11,15};  
      int flag = 10;//这个是随意初始化的值，只要不是0或1 就好  
      int num = 0;  
      scanf("%d",&num);  
      flag = find_num(arr,num);  
      if(flag == 0)  
      {  
        printf("There is no number like %d \n",num);  
      }  
      else if (flag == 1)  
      {  
       printf("true!\n");  
      }  
      system("pause");  
      return 0;  
  } 
