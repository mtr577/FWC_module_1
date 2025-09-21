//7)Write a function that takes two numbers, a and n as input arguments and returns the value of a to the power of n

#include<stdio.h>
int power(int a, int n)
{
	int i,r=1;
	for(i=1;i<=n;i++)
	{
		r=r*a;
	}
	return r;
}
int main()
{
	int a,n;
	printf("Enter a, n to get a^n value\n");
	scanf("%d %d",&a,&n);
	int res=power(a,n);
	printf("%d^%d = %d\n",a,n,res);
	return 0;
}
