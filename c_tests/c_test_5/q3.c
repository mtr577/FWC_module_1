//3)Write a program to take input for two character variables using pointers and find out which character has higher ascii value.
#include<stdio.h>
int main()
{
	char ch1,ch2,*ptr1,*ptr2;
	ptr1=&ch1;
	ptr2=&ch2;
	printf("Enter the two characters: ");
	scanf("%c %c",ptr1,ptr2);
	if(ch1>ch2)
		printf("%c has higer ascii value\n",ch1);
	else
		printf("%c has higer ascii value\n",ch2);
	return 0;
}
