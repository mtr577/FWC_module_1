#include<stdio.h>
#include<string.h>
typedef struct
{
	int no_of_stocks;
	char stock_name[20];
}stock;
stock stocks[10]={20,"mysore sandal",20,"santoor",20,"pepsodent",20,"close up",20,"meera shampoo",20,"clinck plus",20,"biscuits",20,"chocolates",20,"drinks",20,"cakes"};
void print_stock()
{
	for(int i=0;i<10;i++)
	{
		printf("%s: %d\n",stocks[i].stock_name,stocks[i].no_of_stocks);
	}
}
void addstock(int quantity, char stock_name[])
{
	for(int i=0;i<10;i++)
	{
		if(strcmp(stocks[i].stock_name,stock_name)==0)
		{
			stocks[i].no_of_stocks+=quantity;
			return;
		}
	}
}
void deletestock(int quantity, char stock_name[])
{
	for(int i=0;i<10;i++)
        {
                if(strcmp(stocks[i].stock_name,stock_name)==0)
		{
			stocks[i].no_of_stocks-=quantity;
			return;
		}
	}
}
int check_stock(char stock_name[])
{
	int i,flag=0;
	for(i=0;i<10;i++)
        {
                if(strcmp(stocks[i].stock_name,stock_name)==0)
                {
                        flag=1;
			break;
                }
		else
			flag=0;
        }
	if(flag)
		return stocks[i].no_of_stocks;
	else
		printf("Stock not found\n");
		printf("Please add the new item to store\n");
		return -1;
}
