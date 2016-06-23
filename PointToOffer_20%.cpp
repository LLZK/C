#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
void change_space(char *str)  
{  
  int i = 0;  
  int n = 0;  
  int len = strlen(str);// strlen 字符串操作函数，求取字符串长度  
  int nlength = 0;  
 while(len)  
 {  
   if(*str == ' ')  
   {  
     n++;  
   }  
   len--;  
   str++;  
 }  
   nlength = len + n*2;  
  while(len!=nlength)  
  {  
       
      if(str[len] == ' ')  
      {  
            str[nlength--] = '0';  
        str[nlength--] = '2';  
        str[nlength--] = '%';  
        len--;  
      }  
      else  
      {  
      str[nlength--] = str[len--];  
      }  
  }  
}  
  int main()  
  {  
    char p[50]="i am a student";  
    change_space(p);  
    printf("%s",p);  
    system("pause");  
    return 0;  
  }  







