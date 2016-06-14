/*
1
1 1
1 2 1
1 3 3 1
*/
#include<stdio.h>
  int main()
    {
    	int i=0;
    	int j=0;
    	int n;
    	printf("Please input the line number£º"); 
    	scanf("%d",&n);
    	int arr[n][n];

    	for(i=0;i<n;i++)
    	  {
    	  	arr[i][0]=1; 
    	  	arr[i][i]=1;
    	  }
    	for(i=2;i<n;i++)
    	for(j=1;j<i;j++)
    	  	   {
    	  	   	arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
    	  	    //printf("%d ",arr[i][j]);
			   }
   		  
	for(i=0;i<n;i++)
	{
	for(j=0;j<=i;j++)
	  {
	  	printf("%d ",arr[i][j]); 	
	  }
	  printf("\n");
    }
		
        return 0;   	
	}
