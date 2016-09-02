#include<stdio.h>
#include<string.h>
 char *my_strrchr(const char*str,char c)
   {
   	 const char *ch=&c;
   	 const char *key=NULL;
   	 const char *tmp=NULL;
   	 while(tmp=strchr(str,c))
   	 {
   	  	key=tmp;
   	  	str=tmp+1;
	 }
	 return (char*)key;
   }
 int main()
  {
    char *tmp=my_strrchr("dcfcccas",'c');
   	printf("%s",tmp);
  	return 0;
  }
