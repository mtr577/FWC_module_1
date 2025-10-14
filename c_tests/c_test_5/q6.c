//6)declare different pointers with different data types. Print the sizes of the pointer variables using sizeof operator. Why do u think all of them are giving same size irrespective of the data type?
#include<stdio.h>
int main()
{
	int *a;
	char *b;
	float *c;
	double *d;
	short int *e;
	long double *f;
	printf("size of int pointer:%ld\n",sizeof(a));
	printf("size of char pointer:%ld\n",sizeof(b));
	printf("size of float pointer:%ld\n",sizeof(c));
	printf("size of short int pointer:%ld\n",sizeof(d));
	printf("size of double pointer:%ld\n",sizeof(e));
	printf("size of long double pointer:%ld\n",sizeof(f));
	return 0;
	//NOTE: all print same value because size of pointer variable is 8 bytes it stores only address on another variable whether int or char or floatso it's size not depend on type of variable

}
