#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter range of numbers: ");
	scanf("%d%d",&a,&b);
	printf("Prime numbers in range of %d and %d\n",a,b);
	for(int i=a;i<=b;i++)
	{
		if(check_prime(i))
			printf("%d ",i);
	}
	return 0;
}
