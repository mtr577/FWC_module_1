//5)Declare 3 pointer variables of integer type, and an integer variable. Assign the address of integer variable to the 3 pointers. Print the variable value using indirection on each pointer variable. Change the variable value directly and check the values of each of the pointers using indirection. Change the variable value , using each pointer and print the variable value and indirected values of all pointers every time you change
#include<stdio.h>
int main()
{
	int n,*p1,*p2,*p3;
	printf("Enter a integer value n: ");
	scanf("%d",&n);
	p1=p2=p3=&n;
	printf("value of n:%d\n",n);
	printf("value of n using *p1:%d\n",*p1);
	printf("value of n using *p2:%d\n",*p2);
	printf("value of n using *p3:%d\n",*p3);
	printf("Changing n value \n");
	n=n+10;
	printf("value of n:%d\n",n);
	printf("value of n using *p1:%d\n",*p1);
        printf("value of n using *p2:%d\n",*p2);
        printf("value of n using *p3:%d\n",*p3);
	printf("changing *p1 value\n");
	*p1=100;
	printf("value of n:%d\n",n);
        printf("value of n using *p1:%d\n",*p1);
        printf("value of n using *p2:%d\n",*p2);
        printf("value of n using *p3:%d\n",*p3);
	printf("changing *p2 value\n");
        *p2=0;
	printf("value of n:%d\n",n);
        printf("value of n using *p1:%d\n",*p1);
        printf("value of n using *p2:%d\n",*p2);
        printf("value of n using *p3:%d\n",*p3);
	printf("changing *p3 value\n");
	*p3=1;
	printf("value of n:%d\n",n);
        printf("value of n using *p1:%d\n",*p1);
        printf("value of n using *p2:%d\n",*p2);
        printf("value of n using *p3:%d\n",*p3);
	return 0;
}
