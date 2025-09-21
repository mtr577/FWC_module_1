//6. Write two source files, main.c and swap.c. The main function initializes a two-element array of ints, and then calls the swap function to swap the pair.

#include<stdio.h>
extern void swap(int (*a)[5],int (*b)[5]);
int main()
{
	int a[5]={1,2,3,4,5};
	int b[5]={6,7,8,9,0};
	printf("Before swap 2 arryas are: ");
	for(int i=0;i<5;i++)
        {
                printf("%d,",*(a+i));
        }
        printf("\n");
        for(int j=0;j<5;j++)
        {
                printf("%d,",*(b+j));
        }
        printf("\n");
	swap(&a,&b);
	printf("After swap 2 arrays are: ");
	for(int i=0;i<5;i++)
	{
		printf("%d,",*(a+i));
	}
	printf("\n");
	for(int j=0;j<5;j++)
	{
		printf("%d,",*(b+j));
	}
	printf("\n");
	return 0;
}
