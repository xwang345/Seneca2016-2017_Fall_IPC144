#include<stdio.h>
#include<stdlib.h>

#define MAX_ITEMS 10

struct Item{
	int sku_;
	float price_;
	int quantity_;
};

int main(void)
{
        int optionsnum, sku, quantity;
        int i;
        struct Item item[MAX_ITEMS];
        int size = 0;
	int found = 0;

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
                printf("Invalid input, try again: Please select from the following options:\n");
                printf("1) Display the inventory.\n");
                printf("2) Add to shop.\n");
		printf("0) Exit.\n");
                printf("Select:");
                scanf("%d", &optionsnum);
        }
//==============================================================================================
                if(optionsnum == 0)
                {
                        printf("Good bye!\n");
                        return 0;
                }
//===============================================================================================
                else if(optionsnum == 1)
                {
                printf("\n\n");
                printf("Inventory\n");
              	printf("=========================================\n");
			if(size == MAX_ITEMS)
			{
			printf("The inventory is full.\n");
			}

                printf("Sku         Price       Quanity\n");
                	for(i = 0; i < size; i++)
               		{
                        printf("%d        %0.2f       %-10d\n", item[i].sku_, item[i].price_, item[i].quantity_);
			}
			printf("=========================================\n");

			
       		}
//================================================================================================
                else if(optionsnum == 2)
                {
                
			printf("Please input a SKU number:");
                       	scanf("%d",&sku);

			found = 0;

			for(i=0; i < size; i++)
			{                 
				if(sku == item[i].sku_){
					found = 1;
					printf("Quantity:");
					scanf("%d", &quantity);
					item[i].quantity_ = item[i].quantity_ + quantity;
					printf("The item exists in the repository, quanity is updated.\n");
				}
		       		
			}
			
			
			if(found == 0){
				if(size == MAX_ITEMS)
				{
				printf("The inventory is full.\n");
				}else{
				item[size].sku_ = sku;
		       		printf("Quantity:");
                        	scanf("%d", &item[size].quantity_);
                        	printf("Price:");
                        	scanf("%f",&item[size].price_);
                        	printf("The item is successfully added to the inventory.\n");
				size = size + 1;
				}
			}


                }
	
//===============================================================================================
}while(1);
return 0;
}
