#include<stdio.h>
#define MAX(a,b) a>b
int main()
{
	int arr[]={12,12,23,1,4,};
	int n=sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(MAX(arr[j],arr[j+1]))
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("The sorted array is: \n");
	for(int k=0;k<n;k++)
		printf("%d ",arr[k]);
	printf("\n");
	return 0;
}
