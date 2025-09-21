#include<stdio.h>
int main()
{
	int n=5,i,j;
	//int k=5;
	for(i=5;i>0;i--)
	{
		for(j=5;j>=i;j--)
		{
			printf("%d ",i);
		}
		printf("\n");
		//k--;
	}
	return 0;
}
