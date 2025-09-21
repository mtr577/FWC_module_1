//1)Write a function that takes principle, rate of interest and time in months as input arguments, and returns the total amount to be repayed, after calculation of simple interest.

#include<stdio.h>
float total_amount(int p, int r, int t)
{
	float i= (p*r*t)/(100*12);
	float sum=p+i;
	return sum;
}
int main()
{
	int p,r,t;
	printf("Enter The principle amount: \n");
	scanf("%d",&p);
	printf("Enter The rate of interrest per year: \n");
        scanf("%d",&r);
	printf("Enter The time period in months: \n");
        scanf("%d",&t);
	float total = total_amount(p,r,t);
	printf("Total Amount with interest is %f\n",total);
}
