#include<stdio.h>
int main()
{
	int a = -23;
	unsigned int b = 200;
	printf("The signed number is %d and the usigned number is %u \n",a,b);
	printf("In 32-bit compiler The range of signed int is -(2^-31) to (2^31)-1 and the range of unsigned int is 0 to (2^32)-1\n");
	return 1;
}
