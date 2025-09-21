//1.Write a program to swap two numbers using Call by Value and Call by Reference.

#include<stdio.h>
void swap_call_by_value(int a, int b)
{
	int temp;
	temp =a;
	a=b;
	b=temp;
	printf("a and b after swaping : %d,%d\n",a,b);
}
void swap_call_by_ref(int *a, int *b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}
int main()
{
	int a,b;
	printf("Enter 2 numbers\n");
	scanf("%d%d",&a,&b);
	printf("a and b before swapping : %d,%d\n",a,b);
	swap_call_by_value(a,b);
	printf("a and b before swap: %d,%d\n",a,b);
	swap_call_by_ref(&a,&b);
	printf("a and ,b after swap: %d,%d\n",a,b);
}
