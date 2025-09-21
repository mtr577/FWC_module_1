//4)write a function that can take an integer as input and return 1, if the number is prime number and 0 if it is not prime and print appropriate output message.
//return type is integer.
//IsPrime - returns int (0,1)


#include<stdio.h>
int prime(int a)
{
	int i;
	for(i=2;i<=a/2;i++)
	{
		if(a%i == 0)
			break;
	}
	if(i>a/2)
		return 1;
	else
		return 0;
}
int main()
{
	int n;
	printf("Enter a number: \n");
	scanf("%d",&n);
	int isprime = prime(n);
	if(isprime)
		printf("Prime number\n");
	else 
		printf("Not prime number\n");
	return 0;
}
