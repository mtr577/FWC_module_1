#include<stdio.h>
#include<string.h>
extern int no_of_sales,total_quantity_sold;
extern int no_of_purchases,total_quantity_purchased;
extern void sell(int quantity,char stock_name[]);
extern void purchase(int quantity,char stock_name[]);
extern int check_stock(char stock_name[]);
extern void print_stock();
void report();
int customer = 0;
int main()
{
	int choice,quantity;
	char stock_name[20];
	while(1)
	{
		printf("\n1. Check Availabe Stock\n");
		printf("2. Purchase new stock\n");
		printf("3. Sell items\n");
		printf("4. Quit\n");
		printf("Enter your option: ");
		if(scanf("%d", &choice) == 1)
		{
            		int c;
            		while ((c = getchar()) != '\n' && c != EOF);
			switch(choice)
			{
				case 1:
					printf("Enter the stock name to check\n");
					scanf(" %[^\n]",stock_name);
					int current_stock=check_stock(stock_name);
					if(current_stock==-1)
						break;
					printf("The %s has %d stock\n",stock_name,current_stock);
					break;
				case 2:
					printf("Enter the stock name to purchase\n");
					scanf(" %[^\n]",stock_name);
					printf("Enter no_of_stocks to purchase: ");
					scanf("%d",&quantity);
					purchase(quantity,stock_name);
					break;
				case 3:
					printf("Enter the stock name to sell\n");
                                	scanf(" %[^\n]",stock_name);
                                	printf("Enter no_of_stocks to sell: ");
                                	scanf("%d",&quantity);
                                	sell(quantity,stock_name);
					customer++;
                                	break;
				case 4:
					printf("Todays report\n");
					report();
					return 0;
				default:
					printf("Choose correct choice\n");
					break;
			}
		}
		else
		{
            		printf("Invalid input. Please enter a number.\n");
            		int c;
            		while ((c = getchar()) != '\n' && c != EOF);
		}
	}
}
void report()
{
	printf("Closing stock\n");
	print_stock();
	printf("\nNo of sales\n%d\n",no_of_sales);
	printf("No of items sold\n%d\n",total_quantity_sold);
	printf("No of purchases\n%d\n",no_of_purchases);
	printf("No of items purchased\n%d\n",total_quantity_purchased);
	printf("No of customers visited\n%d\n",customer);

}
