//13)Write a function to return the product of two numbers without using * operator.

#include<stdio.h>
int mul(int a,int b)
{
	int i, product=0;
	for(i=1;i<=b;i++)
		product=product+a;
	return product;

}
int main()
{
	int a,b;
	printf("Enter a,b: ");
	scanf("%d %d",&a,&b);
	printf("Product of %d and %d is %d\n",a,b,mul(a,b));
	return 0;
}
