#include<stdio.h>
int main()
{
	printf("The data types in 16 bit compiler are\n signed int with range -32768 to 32767\n unsigned int with range is 0 to 65535 \n signed char with range of -128 to 127\n unsinged char with range of 0 to 255\n");
	printf("The following code represents the range in 16 bit compiler");
	short int a = 32768;
	unsigned short int b = 65536;
	char c = 128;
	unsigned char d = 256;
	printf("int val is %hd, unsigned int val is %hu, char val is %d, unsigned char val is %d \n",a,b,c,d);
	return 1;
}
