//Write a function that can take two integers as input, and gives 5 outputs : addition, subtraction, multiplication, quotient and reminder of those two numbers. Print the outputs in the main function.

#include<stdio.h>
void math(int a,int b,int *s,int *d,int *m,int *q, int *r)
{
	*s=a+b;
	*d=a-b;
	*m=a*b;
	*q=a/b;
	*r=a%b;
}
int main()
{
	int a,b,s,d,m,q,r;
	printf("Enter a and b \n");
	scanf("%d%d",&a,&b);
	printf("a and b: %d, %d\n",a,b);
	math(a,b,&s,&d,&m,&q,&r);
	printf("sum: %d\n",s);
	printf("difference: %d\n",d);
	printf("product: %d\n",m);
	printf("quetiont: %d\n",q);
	printf("remainder: %d\n",r);
	return 0;
}
