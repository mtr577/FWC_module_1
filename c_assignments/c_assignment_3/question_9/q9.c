//9)Write a function to accept two dates as input arguments, and return 1 if the first date is older, 0 if the second date is older.

#include<stdio.h>
int age_check(int d1[3], int d2[3])
{
	if(d1[2]<d2[2])
		return 1;
	else if(d1[2]==d2[2] && d1[1]<d2[1])
		return 1;
	else if(d1[2]==d2[2] && d1[1]==d2[1] && d1[0]<d2[0])
		return 1;
	else if(d1[2]==d2[2] && d1[1]==d2[1] && d1[0]==d2[0])
		return 2;
	else
		return 0;
}
int main()
{
	int d1[3],d2[3];
	printf("Enter date 1\n");
	for(int i=0;i<3;i++)
		scanf("%d",&d1[i]);
	printf("Enter date 2\n");
	for(int i=0;i<3;i++)
		scanf("%d",&d2[i]);
	if(age_check(d1,d2)==2)
		printf("both are equal\n");
	else if(age_check(d1,d2)==1)
		printf("date 1 is older\n");
	else
		printf("date 2 is older\n");
	return 0;
}
