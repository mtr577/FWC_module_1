//1)Write a program to print the address of a variable , its value ,its size, try different executions and note the address printed. Assign the address of the variable to a pointer variable.Print the size of pointer and its indirected value (apply * operator).
#include <stdio.h>
int main()
{
	int a,*ptr;
	printf("Enter the value of a: ");
	scanf("%d",&a);
	printf("value of a:%d\naddress of a: %u\nsize of a: %ld\n",a,&a,sizeof(a));
	ptr=&a;
	printf("size of ptr: %ld\nvalue of ptr: %d\n",sizeof(ptr),*ptr);
	return 0;
}
