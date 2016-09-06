#include<iostream>
#include<cassert> 
using namespace std;
 
long long Fib(long long  n)
{
	assert(n>=0);
	if(n == 1||n == 0)
	{
		return n;
	}
	return Fib(n-1)+Fib(n-2);
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
