//8)Take three input integers x,y and z. Write a program to rotate their values such that, x has the value of y, y has the value of z and z has the value of x. Do this using pointers that point to x,y and z
#include<stdio.h>
int main()
{
	int x,y,z,*p1,*p2,*p3;
	printf("Enter 3 integer values: ");
	scanf("%d %d %d",&x,&y,&z);
	printf("before rotating values: %d,%d,%d\n",x,y,z);
	p1=&x,p2=&y,p3=&z;
	int temp=*p1;
	*p1=*p2;
	*p2=*p3;
	*p3=temp;
	printf("Roteted values %d,%d,%d\n",x,y,z);
	return 0;
}
