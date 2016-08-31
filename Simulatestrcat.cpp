#include<stdio.h>
#include<assert.h> 
 char *my_strcat( char *dest, char *src)
   {
   	assert(*dest!=NULL);
   	assert(*src!=NULL);
   	char*tmp=dest;
   	while(*dest)
   	 {
   	 	dest++;
	 }
	while(*dest++=*src++)
	 {
	  ;
	 }
	return tmp;
   }
 int main()
  {
  	char arr[20]="Hello";
  	char arr2[]="bit";
  	char *tmp=my_strcat(arr,arr2);
  	printf("%s",tmp);
  	return 0;
  }
