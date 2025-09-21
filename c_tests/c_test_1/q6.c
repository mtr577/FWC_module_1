 #include<stdio.h>
int main()
{
	int a;
	unsigned int b;
	printf("Enter the signed int and unsigned int\n");
	scanf("%d%u",&a,&b);
	if(a>0 && b)
		printf("Both are non Zero and sum is %u\n ", a+b);
	else
		printf("Sum is %d\n",a+b);
}
