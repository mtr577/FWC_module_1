//6)Write a function to determine if a character is alphanumeric or not and print the result in main function.

#include<stdio.h>
int check_alph_num(char c)
{
	if((c>=48 && c<=57) || (c>=65 && c<=90) || (c>=97 && c<=122))
		return 1;
	else
		return 0;
}
int main()
{
	char ch;
	printf("Enter a character: \n");
	scanf("%c",&ch);
	if(check_alph_num(ch))
		printf("Alpha numeric\n");
	else
		printf("Not Aplha numeric\n");
	return 0;
}
