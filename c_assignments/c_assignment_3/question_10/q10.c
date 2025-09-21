//10)Write a function that accepts a month and year as input, and returns the number of days of the month as output. Print the number of days in a given month and year.

#include<stdio.h>
int days_of_month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
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
int days_in_month(int m, int y)
{
	if(check_leap(y))
	{
		if(m==2)
			return 29;
		else
			return days_of_month[m-1];
	}
	else
		return days_of_month[m-1];
}
int main()
{
	int m,y;
	printf("Enter the month and year\n");
	scanf("%d %d",&m,&y);
	int days=days_in_month(m,y);
	printf("No of days %d\n",days);
	return 0;
}
