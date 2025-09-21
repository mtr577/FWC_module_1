#include<stdio.h>
void swap(int (*a)[5],int (*b)[5])
{
	for(int i=0;i<5;i++)
	{
		int temp = (*a)[i];
		(*a)[i] = (*b)[i];
		(*b)[i] = temp;
	}
}
