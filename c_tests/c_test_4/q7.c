#include<stdio.h>
#define MAX(a,b,c) a>b?a>c?a:c:b>c?b:c
int main()
{
	int a=100,b=19,c=9;
	int res=MAX(a,b,c);
	printf("%d\n",res);

	float x=12.3,y=13.4,z=25.6;
	printf("%f\n",MAX(x,y,z));
	
	double p=19.0,q=13.0,r=14.9;
	printf("%lf\n",MAX(p,q,r));
	
	char i='q',j='r',k='i';
	printf("%c\n",MAX(i,j,k));
	
	return 0;
}
