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
	long long first = 0;
	long long second = 1;
	long long ret = 0;
	for(int i = 2;i<=n;i++)
	{
		ret = first+second;
		first = second;
		second = ret;
	}
	return ret;
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
