#include<iostream>
#include<cassert>
using namespace std;
 
long long Fib(long long  n)
{
	assert(n >= 0);
	if(n==0||n==1)
	{
		return n;
	}
	long long *p = new long long[n+1];
	p[0] = 0;
	p[1] = 1;
	for(int i = 2;i < n+1; i++)
	{
		p[i] = p[i-1]+p[i-2];
	}
	return p[n];
}
 int main()
{
	cout<<Fib(3)<<endl;
	cout<<Fib(4)<<endl;
	cout<<Fib(5)<<endl;
	cout<<Fib(6)<<endl;
	cout<<Fib(7)<<endl;
	system("pause");
	return 0;
}
