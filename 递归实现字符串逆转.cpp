#include<stdio.h>
 int countlen(char *string)
  {
  	int count;
  	while(*string++)
  	 {
  	 	count++;
	   }
	return count;
  }
 void reverse_string(char *string)
  {
  	int len=countlen(string);
    if(len>1)
	 {
	    char tmp=string[0];
	    string[0]=string[len-1];
	    string[len-1]='\0';
	    reverse_string(string+1);
	    string[len-1]=tmp;
	 }  
	
  }
 int main()
  {
  	char arr[30]="abcdef";
  	reverse_string(arr);
  	printf("%s",arr);
  	return 0;
  }
