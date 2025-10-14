//2)Write a program to add two variables using thier pointers
#include <stdio.h>
int main()
{
	int n1,n2,*ptr1,*ptr2;
	printf("Enter the n1 and n2: ");
	scanf("%d %d",&n1,&n2);
	ptr1=&n1;
	ptr2=&n2;
	printf("Sum of %d and %d is %d\n",n1,n2,*ptr1+ *ptr2);
}
