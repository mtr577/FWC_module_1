//14)Write a function to take a number and return its square, without using * operator.

#include<stdio.h>
int square(int a)
{
        int i, product=0;
        for(i=1;i<=a;i++)
                product=product+a;
        return product;

}
int main()
{
        int a;
        printf("Enter a number: ");
        scanf("%d",&a);
        printf("Square of %d is %d\n",a,square(a));
        return 0;
}
