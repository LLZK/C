#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char *my_strchr(const char*str,char c)
 {
 	assert(str);
 	int flag=0;
 	const char *ch=&c;
 	while(str)
 	  {
 	   if(*str==*ch)
		 {
		 	flag++;
		   break;	
		 }	
	   str++;
	  }
	if(flag=1)
	 {
	 	return (char*)str;
	 }
	else
	 {
	 	return 0;
	 }
 }
 int main()
   {
   	char *tmp=my_strchr("dcfcccas",'c');
   	printf("%s",tmp);
  	return 0;
   } 
