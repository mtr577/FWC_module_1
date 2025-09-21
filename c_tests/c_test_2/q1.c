#include<stdio.h>
int main()
{
	int i,j,n=5;
	//int x=0, y=1;
	for(i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			for(j=1;j<=i;j++)
			{
				if(j%2==1)
					printf("0 ");
				else
					printf("1 ");
			}
			printf("\n");
		}
		else
		{
			for(j=1;j<=i;j++)
			{
				if(j%2==1)
					printf("1 ");
				else
					printf("0 ");
			}
			printf("\n");
		}
	}
	return 0;
}
