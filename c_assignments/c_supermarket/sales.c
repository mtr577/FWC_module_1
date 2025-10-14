#include<stdio.h>
#include<string.h>
extern void deletestock(int quantiy, char stock_name[]);
extern int check_stock(char stock_name[]);
int no_of_sales=0,total_quantity_sold=0;
void sell(int quantity,char stock_name[])
{
	int available_stock=check_stock(stock_name);
	if(available_stock==-1)
		return;
	int choice;
	if(available_stock>=quantity)
	{
		printf("sales successfull\n");
		deletestock(quantity,stock_name);
		no_of_sales++;
		total_quantity_sold+=quantity;
		return;
	}
	else
	{
		printf("Avialable stock is: %d\n",available_stock);
		printf("choice the following\n");
		printf("1.Sell available stock\n");
		printf("2. Cancel the sales\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("sales successful\n");
				deletestock(available_stock,stock_name);
				no_of_sales++;
                                total_quantity_sold+=available_stock;
				break;
			case 2:
				printf("sales cancelled due to less stokc please purchase the %s stock\n",stock_name);
				return;
		}

	}
}
