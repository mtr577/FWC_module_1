//7)Write a program to find the biggest of three numbers using pointers that point to those numbers
#include<stdio.h>
int main()
{
	int a,b,c,*p1,*p2,*p3,temp;
	printf("Enter the 3 integer numbers: ");
	scanf("%d %d %d",&a,&b,&c);
	p1=&a,p2=&b,p3=&c;
	if(*p1>*p2)
	{
		if(*p1>*p3)
			temp=*p1;
		else
			temp=*p3;
	}
	else if(*p2>*p3)
	{
		if(*p2>*p1)
			temp=*p2;
		else
			temp=*p1;
	}
	else
	{
		if(*p3>*p2)
			temp=*p3;
		else
			temp=*p2;
	}
	printf("The biggest is %d\n",temp);
	return 0;
}
