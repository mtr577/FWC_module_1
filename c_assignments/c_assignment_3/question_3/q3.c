//3)Write a function ,that can take two integers, swap their values and print their new values in function itself. function return type should be void.

#include<stdio.h>
void swap(int a, int b)
{
	int temp;
	temp = a;
	a=b;
	b=temp;
	printf("swapped vales are %d, %d\n",a,b);
}
int main()
{
	int a,b;
	printf("Enter the 2 integer number: \n");
	scanf("%d%d",&a,&b);
	printf("Before swap values are %d, %d\n",a,b);
	swap(a,b);
}
