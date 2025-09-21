//12)Write a function to accept a character as input, return case reverse of the character.
//char CaseReverse(char );

#include<stdio.h>
char CaseReverse(char ch)
{
	if(ch>64 && ch<91)
		ch=ch+32;
	else if(ch>96 && ch<123)
		ch=ch-32;
	return ch;
}
int main()
{
	char ch;
	printf("Enter a alphaber: ");
	scanf(" %c",&ch);
	printf("Case reverse is %c\n",CaseReverse(ch));
	return 0;
}
