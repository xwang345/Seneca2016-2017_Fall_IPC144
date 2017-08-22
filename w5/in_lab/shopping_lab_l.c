#include<stdio.h>
#include<stdlib.h>

#define MAX_ITEMS 10

struct Item {
	int sku_;
	float price_;
	int quantity_;
};

int main(void)
{
	int optionsnum;
	int i;
	struct Item item[MAX_ITEMS];
	int size = 0;

	printf("Welcome to the Shop\n");
	printf("===================\n");
	do{
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add to shop.\n");
	printf("0) Exit.\n");
	printf("Select:");
	scanf("%d", &optionsnum);

	while (optionsnum<0 || optionsnum>2)
	{
		printf("Invaild input, try again: Please select from the following options:\n");
		printf("1) Display the inventory.\n");
		printf("2) Add to shop.\n");
		printf("Select:");
		scanf("%d", &optionsnum);
	}
//==============================================================================================	
		if(optionsnum == 1)
		{
		printf("\n");
		printf("\n");
		printf("Inventory\n");
		printf("=========================================\n");

		printf("Sku         Price       Quanity\n");
		for(i = 0; i < size; i++)
		{	
			printf("%d        %0.2f       %d\n", item[i].sku_, item[i].price_, item[i].quantity_);
		}
	}
//================================================================================================
		else if(optionsnum == 2)
		{
			printf("Please input a SKU number:");
			scanf("%d",&item[i].sku_);
			printf("Quantity:");
			scanf("%d", &item[i].quantity_);
			printf("Price:");
			scanf("%f",&item[i].price_);
			printf("The item is successfully added to the inventory.\n");
		}
		else if(optionsnum == 0)
	{
		printf("Good bye!\n");
		return 0;
	}
		size = size + 1;
	}while(1)
		;return 0;
}




/*
Welcome to the Shop
===================
Please select from the following options:
1) Display the inventory.
2) Add to shop.
0) Exit.
Select:8
Invalid input, try again: Please select from the following options:
1) Display the inventory.
2) Add to shop.
0) Exit.
Select:2
Please input a SKU number:2341
Quantity:3
Price:12.78
The item is successfully added to the inventory.
Please select from the following options:
1) Display the inventory.
2) Add to shop.
0) Exit.
Select:2
Please input a SKU number:4567
Quantity:9
Price:98.2
The item is successfully added to the inventory.
Please select from the following options:
1) Display the inventory.
2) Add to shop.
0) Exit.
Select:1


Inventory
=========================================
Sku         Price       Quanity
2341        12.78       3
4567        98.20       9
=========================================
Please select from the following options:
1) Display the inventory.
2) Add to shop.
0) Exit.
Select:2
Please input a SKU number:2341
Quantity:5
The item exists in the repository, quanity is updated.
Please select from the following options:
1) Display the inventory.
2) Add to shop.
0) Exit.
Select:1


Inventory
=========================================
Sku         Price       Quanity
2341        12.78       8
4567        98.20       9
=========================================
Please select from the following options:
1) Display the inventory.
2) Add to shop.
0) Exit.
Select:0
Good bye!
*/
