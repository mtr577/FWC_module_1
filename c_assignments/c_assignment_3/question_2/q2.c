/*
2)Modify the calculator program - with functions ,Add(),Sub(),Mul(),Div(),Mod(). Each function should take the inputs as parameters and return the result as output.
Hint: int add(int , int);
int sub (int, int);
*/

#include<stdio.h>
int add(int a, int b)
{
	return a+b;
}
int sub(int a, int b)
{
        return a-b;
}
int mul(int a, int b)
{
        return a*b;
}int div(int a, int b)
{
        return a/b;
}
int mod(int a, int b)
{
        return a%b;
}
int main()
{
	int a,b,result, choice;
	while(1)
	{
		printf("Enter 2 integer values: \n");
        	scanf("%d%d",&a,&b);
		printf("press 1 to add\n");
		printf("press 2 to sub\n");
		printf("press 3 to mul\n");
		printf("press 4 to div\n");
		printf("press 5 to mod\n");
		printf("press 7 to exit\n");
		printf("Enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				result=add(a,b);
				printf("Result is %d\n",result);
				break;
			case 2:
                                result=sub(a,b);
				printf("Result is %d\n",result);
                                break;
			case 3:
                                result=mul(a,b);
				printf("Result is %d\n",result);
                                break;
			case 4:
                                result=div(a,b);
				printf("Result is %d\n",result);
                                break;
			case 5:
                                result=mod(a,b);
				printf("Result is %d\n",result);
                                break;
			case 7:
                                return 0;
			default:
				printf("Enter the corretc choice\n");

		}
	}
	return 0;
}
