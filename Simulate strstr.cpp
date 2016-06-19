//Ä£ÄâÊµÏÖstrstr 
#include<stdio.h>
#include<assert.h>
 char* my_strstr(const char *sub,const char *substr)
  {
     
  	  assert(sub!=NULL);
      assert(substr!=NULL);
  	  const char* pa=sub;
      const char* pb=substr;
      const char *start=NULL;
  	  while(*pa)
  	  {
  	  	 start=pa;
  	  	 while(*pa&&*pb&&*pa==*pb)
  	  	   {
  	  	           pa++;
  	  	           pb++;
			}
		 if(*pb=='\0')
		  {
	   return (char*)start;
		 
		  }
	   pa=start+1;
	   pb=substr;
		
      }
   return NULL;
  }
 int main()
  {
   	char arr1[]="abbbcdef";
  	char arr2[]="bbc";
  	
  	if(my_strstr(arr1,arr2)!=NULL)
  	  {
  	  	printf("yes");
	  }
    else 
    {
     printf("NO");
   }
  	return 0;
   } 
