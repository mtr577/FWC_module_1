//3) Write a function that can rotate the values of three variables. print the results in main function.

#include<stdio.h>
void rotate(int *a,int *b,int *c)
{
	int temp=*a;
	*a=*b;
	*b=*c;
	*c=temp;
}
int main()
{
	int a,b,c;
	printf("Enter 3 numbers\n");
	scanf("%d%d%d",&a,&b,&c);
	printf("before rotate %d,%d,%d\n",a,b,c);
	rotate(&a,&b,&c);
	printf("roteted values %d,%d,%d\n",a,b,c);
}
