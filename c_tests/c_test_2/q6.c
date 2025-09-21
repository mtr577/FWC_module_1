#include<stdio.h>
int main()
{
	int n=5,i,j,x=n,y=n;
	for(i=1;i<n*2;i++)
	{
		
		if(i<=n)
		{
			for(j=1;j<n*2;j++)
			{
				if(j>=x&&j<=y)
					printf("*");
				else
					printf(" ");
			}
			x--;
			y++;
			printf("\n");
		}
		if(i>n)
		{
			x++;
			y--;
			for(j=1;j<n*2;j++)
			{
				if(j>x&&j<y)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
