#include<stdio.h>
#define CHECK_CHAR(ch) ((ch>=48 && ch<=57) || (ch>64 && ch<91) || (ch>96 && ch<123))
int main()
{
	char ch;
	printf("Enter the char: ");
	scanf("%c",&ch);
	if(CHECK_CHAR(ch))
		printf("Alphanumeric character\n");
	else
		printf("Not alphanumeric charcter\n");
	return 0;
}
