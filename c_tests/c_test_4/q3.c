#include<stdio.h>
#include"q3.h"
int main()
{
	int a,b,c,res;
	while(1)
	{
		printf("Enter 2 numbers: ");
                scanf("%d %d",&a,&b);
		printf("1 for Addittion\n2 for subtraction\n3 for mutliplication\n4 for division\n5 for exit\n");
		printf("Enter your choise: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				res=ADD(a,b);
				printf("Resutl is %d\n",res);
				break;
			case 2:
                                res=SUB(a,b);
				printf("Resutl is %d\n",res);
                                break;
			case 3:
                                res=MUL(a,b);
				printf("Resutl is %d\n",res);
                                break;
			case 4:
                                res=DIV(a,b);
				printf("Resutl is %d\n",res);
                                break;
			case 5:
				return 0;
			default:
				printf("Enter correct choice\n");
		}

	}
	return 0;
}
