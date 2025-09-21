//5)Write a program with a function that takes two integer arguments, and prints all prime numbers between those numbers using the prime number function written above.return type should be void.
//PrintAllPrimes - return type is void. Should use IsPrime() function written in Q3 to identify if given number is prime or not.


#include<stdio.h>
int isprime(int a)
{                                                                                   int i;                                                                      for(i=2;i<=a/2;i++)                                                         {                                                                                   if(a%i == 0)                                                                        break;                                                      }                                                                           if(i>a/2)                                                                           return 1;                                                           else                                                                                return 0;                                                   }
void print(int a,int b)
{
	int i;
	printf("prime numbers in that range: \n");
	for(i=a;i<=b;i++)
	{
		if(isprime(i))
			printf("%d ",i);
	}
	printf("\n");
}
int main()
{
	int a,b;
	printf("Enter two numbers range: \n");
	scanf("%d %d",&a,&b);
	print(a,b);
	return 0;
}
