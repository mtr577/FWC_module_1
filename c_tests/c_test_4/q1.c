#include<stdio.h>
#define MAX(x,y) x>y?x:y
int main()
{
	int a,b;
	printf("Enter the 2 number: ");
	scanf("%d %d",&a,&b);
	printf("The biggest of %d and %d is %d\n",a,b,MAX(a,b));
}
