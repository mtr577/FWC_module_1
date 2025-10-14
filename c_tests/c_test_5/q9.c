//9)Declare an integer array of size 10 and initialize it to some values. Print the addresses of each element of the array using a pointer. using indirection operator , print the value stored in each element of the array.
#include<stdio.h>
int main()
{
	int a[10]={12,24,35,56,78,98,99,76,99,81};
	int *ptr;
	ptr=a;
	for(int i=0;i<10;i++)
	{	
		printf("Addres of a[%d] is :%u and value is :%d\n",i,ptr,*ptr);
		ptr++;
	}
	return 0;
}
