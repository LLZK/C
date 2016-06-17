#include<stdio.h>  
#include<stdlib.h>  
#include<assert.h>  
  
void *my_memmove(void *dest,const void *src,int n)  
{  
/*因为char类型为1字节，所以将数据转化为char* 
进行操作。并不是因为操作的对象是字符串*/  
char* pdest=(char *)dest;   
const char* psrc=(const char *)src;  
assert(dest);  
assert(src);  
if(pdest <= psrc&&pdest >=psrc+n)//正常情况下从前向后拷贝  
{  
    while(n--)  
    {  
        *pdest = *psrc;  
    }  
}  
else //当出现内存覆盖时从后向前拷贝  
{  
    while(n--)  
    {  
        *(pdest+n)=*(psrc+n);  
    }  
}   
  return dest;  
}  
  
int main()  
{  
    char arr[10]="abcdefg";  
    char arr0[10]="abcdefg";  
    char arr1[10]={0};  
    my_memmove(arr+2,arr,4);  
    my_memmove(arr1,arr0,4);  
    printf("内存覆盖情况：%s\n",arr+2);  
    printf("正常情况：%s\n",arr1);  
    system("pause");  
    return 0;  
}  
