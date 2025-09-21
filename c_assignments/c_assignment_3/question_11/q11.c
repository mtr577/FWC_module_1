//11)Write a function to accept a date and return 1 if the date is valid, 0 if it is not valid.

#include<stdio.h>
int date_check(int d[3])
{
	if(d[2]%100==0)
	{
		if(d[2]%4==0)
		{
			if(d[1]>12)
				return 0;
			else if((d[1]==1 || d[1]==3 || d[1]==5 || d[1]==7 || d[1]==8 || d[1]==10 || d[1]==12) && (d[0]>31 || d[0]<1))
				return 0;
			else if((d[1]==4 || d[1]==6||d[1]==9 || d[1]==11) && (d[0]>30 || d[0]<1))
				return 0;
			else if(d[1]==2 && (d[0]>29 ||d[0]<1))
				return 0;
			else
				return 1;
		}
	}
	else if(d[2]%4==0)
	{
		 if(d[1]>12)                                                                         return 0;                                                           else if((d[1]==1 || d[1]==3 || d[1]==5 || d[1]==7 || d[1]==8 || d[1]==10 || d[1]==12) && (d[0]>31 || d[0]<1))                                                   return 0;                                                           else if((d[1]==4 || d[1]==6||d[1]==9 || d[1]==11) && (d[0]>30 || d[0]<1))                                                                                       return 0;                                                           else if(d[1]==2 && (d[0]>29 ||d[0]<1))                                              return 0;                                                           else                                                                                return 1;                                         

	}
	else
	{
		 if(d[1]>12)                                                                         return 0;                                                           else if((d[1]==1 || d[1]==3 || d[1]==5 || d[1]==7 || d[1]==8 || d[1]==10 || d[1]==12) && (d[0]>31 || d[0]<1))                                                   return 0;                                                           else if((d[1]==4 || d[1]==6||d[1]==9 || d[1]==11) && (d[0]>30 || d[0]<1))                                                                                       return 0;                                                           else if(d[1]==2 && (d[0]>28 ||d[0]<1))                                              return 0;                                                           else                                                                                return 1;                                          

	}
}
int main()
{
	int d[3];
	printf("Entert the date: ");
	for(int i=0;i<3;i++)
		scanf("%d",&d[i]);
	if(date_check(d))
		printf("valid\n");
	else
		printf("not valid\n");
	return 0;

}
