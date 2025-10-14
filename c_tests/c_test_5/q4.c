//4)Declare 3 integer variables. Declare an integer pointer. Assign the address of each variable to the pointer in succession and print the value of the variable using indirection operator on the pointer.
#include<stdio.h>
int main()
{
	int a,b,c,*p;
	printf("Enter 3 integer values: ");
	scanf("%d %d %d",&a,&b,&c);
	p=&a;
	printf("1st integer values is %d\n",*p);
	p=&b;
        printf("2nd integer values is %d\n",*p);
	p=&c;
        printf("3rd integer values is %d\n",*p);
	return 0;
}
