//2) return a structure with addition, subtraction, multiplication, quotient and reminder of 2 integers, sent to a function as arguments. Quotient should be a floating point result. All the results to be printed in main function.

#include<stdio.h>
struct math
{
	int add;
	int sub;
	int mul;
	float quetioent;
	int remainder;
};
struct math cal(int a, int b)
{
	struct math m;
	m.add=a+b;
	m.sub=a-b;
	m.mul=a*b;
	m.quetioent=a/b;
	m.remainder=a%b;
	return m;
}
int main()
{
	int a,b;
	printf("Enter 2 integer values\n");
	scanf("%d%d",&a,&b);
	struct math m;
	m=cal(a,b);
	printf("Addition: %d\n",m.add);
	printf("subtraction: %d\n",m.sub);
	printf("Multiplication: %d\n",m.mul);
	printf("Quetioent: %f\n",m.quetioent);
	printf("Remainder: %d\n",m.remainder);
	return 0;
}
