//8)Write a function to accept a year as input and return 1 if the year is a leap year, otherwise 0

#include<stdio.h>
int check_leap(int y)
{
	if(y%100==0)
	{
		if(y%400==0)
			return 1;
		else
			return 0;
	}
	else
	{
		if(y%4==0)
			return 1;
		else
			return 0;
	}
}
int main()
{
	int y;
	printf("Enter the year: ");
	scanf("%d",&y);
	if(check_leap(y))
		printf("Leap Year\n");
	else
		printf("Not leap year\n");
	return 0;
}
