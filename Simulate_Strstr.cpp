#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
char* my_strstr(const char*str1,const char*str2)
{
	const char* pstr1 = str1;
	const char* pstr2 = str2;
	const char* start = str1;;
	assert(str1);
	assert(str2);

	while(pstr1)
	{
		start = pstr1;
		while(*pstr1&&*pstr2&&*pstr1 == *pstr2)
		{
			pstr1++;
			pstr2++;
		}
		if(*pstr1 == '\0')
		{
			return NULL;
		}
		else if(*pstr2 == '\0')
		{
			return (char*)start;
		}
		pstr1 = start+1;
		pstr2 = str2;
	}
	return NULL;
}

int main()
{
	const char* str1 = "assaaabcsdwq";
	const char* str2 = "abc";
	char *ret = my_strstr(str1,str2);
	if(*ret != '\0')
	{
		printf("%s",ret);
	}
	else
	{
		printf("NOT FOUND");
	}
	system("pause");
	return 0;
}
