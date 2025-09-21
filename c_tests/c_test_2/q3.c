#include<stdio.h>
int main()
{
	int i,j,n=5;
	for(i=n;i>0;i--)
	{
		for(j=n;j>=i;j--)
			printf("%d ",j);
		printf("\n");
	}
	return 0;
}
