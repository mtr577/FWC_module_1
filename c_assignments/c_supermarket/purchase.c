#include<stdio.h>
#include<string.h>
#define MAX_STOCK 100;
extern void addstock(int quantity, char stock_name[]);
extern int check_stock(char stock_name[]);
int no_of_purchases=0,total_quantity_purchased=0;
void purchase(int quantity, char stock_name[])
{
        int available_stock=check_stock(stock_name);
	if(available_stock==-1)
		return;
        int choice,space=MAX_STOCK-available_stock;
	if(space<=0)
		printf("Maximum stock available\n");
        if(space<quantity && space > 0)
        {
                printf("Avialable space is: %d\n",space);
                printf("choice the following\n");
                printf("1. purchase the possible items for remaining space\n");
                printf("2. Cancel the purchase\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                printf("Stock purchase is successful\n");
                                addstock(space, stock_name);
				no_of_purchases++;
				total_quantity_purchased+=space;
                                break;
                        case 2:
                                printf("purchase is cancelled due to less space\n");
                                return;
                }

        }
	else
	{
		printf("Stock purchase is successful\n");
		addstock(quantity,stock_name);
		no_of_purchases++;
                total_quantity_purchased+=quantity;
	}
}
