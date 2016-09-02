//×óÐý×Ö·û´®µÄÇ°n¸ö×Ö·û
#include<stdio.h>
#include<string.h> 
 void left_rev_str(char *str,int n)
  {
  	int i=0;
  	int len=strlen(str);
    while(n-->0&&n<=len)	
  	{
  		char tmp=str[0];
     	for(i=0;i<len-1;i++)
         {
          str[i]=str[i+1];   	 	
         }
      str[len-1]=tmp;
    }
  }
 int main()
  {
  	char arr[]="abcdef";
  	int n;
  	scanf("%d",&n);
  	left_rev_str(arr,n);
  	printf("%s",arr);
	  return 0;
  }
