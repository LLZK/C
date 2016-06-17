#include<stdio.h>  
#include<stdlib.h>  
#include<assert.h>  
  
void *my_memmove(void *dest,const void *src,int n)  
{  
/*��Ϊchar����Ϊ1�ֽڣ����Խ�����ת��Ϊchar* 
���в�������������Ϊ�����Ķ������ַ���*/  
char* pdest=(char *)dest;   
const char* psrc=(const char *)src;  
assert(dest);  
assert(src);  
if(pdest <= psrc&&pdest >=psrc+n)//��������´�ǰ��󿽱�  
{  
    while(n--)  
    {  
        *pdest = *psrc;  
    }  
}  
else //�������ڴ渲��ʱ�Ӻ���ǰ����  
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
    printf("�ڴ渲�������%s\n",arr+2);  
    printf("���������%s\n",arr1);  
    system("pause");  
    return 0;  
}  
