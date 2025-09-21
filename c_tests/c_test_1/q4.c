#include <stdio.h>
int main()
{
	printf(" \" && \" represents the logical AND in C \n");
	int a = 10;
	int b = 0;
	int c = a&&b; //it should give 0 as output
	printf("%d\n",c);
}
