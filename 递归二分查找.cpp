#include<iostream>
using namespace std;
int Binsearch( int head,int end,int *arr,int a)
{
	int mid = (head&end)+((head^end)>>1);
	//(head-end)/2+end
	if(arr[mid] == a)
	{
		return mid;
	}
	else if(arr[mid]>a)
	{
		return Binsearch(head,mid,arr,a);
	}
	else
	{
		return Binsearch(mid,end,arr,a);
	}
}
 int main()
 {
	 int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	 int ret = Binsearch(0,9,arr,3);
	 cout<<ret<<endl;
	 system("pause");
	 return 0;
 }
