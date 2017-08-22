#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 10

struct Item{
        int sku_;
        float price_;
        int quantity_;
};

int main(void){
        int optionsnum; int sku, quantity;
        int i;
        struct Item item[MAX_ITEMS];
        int found = 0;
	int size = 0;


        printf("Welcome to the Shop\n");
	printf("===================\n");

        do {
                printf("Please select from the following options:\n");
                printf("1) Display the inventory.\n");
                printf("2) Add to shop.\n");
                printf("3) Price check.\n");
                printf("0) Exit.\n");

                printf("Select:");
                scanf("%d",&optionsnum);


                while(optionsnum < 0 || optionsnum > 3){
                        printf("Invalid input, try again: Please select from the following options:\n");
                        printf("1) Display the inventory.\n");
                        printf("2) Add to shop.\n");
                        printf("3) Price check.\n");
                        printf("0) Exit.\n");

                        printf("Select:");
                        scanf("%d",&optionsnum);

                }

                if(optionsnum == 0){ //exit
                        printf("Good bye!\n");
                        return 0;
                } else if (optionsnum == 1) {     //print the result
                        printf("\n\nInventory\n");
                        printf("=========================================\n");
                        printf("Sku         Price       Quanity\n");

                        for(i=0; i< size; i++){
                                printf("%d        %.2f       %-10d\n", item[i].sku_, item[i].price_, item[i].quantity_);
                        }
                        printf("=========================================\n");
                } else if (optionsnum == 2) {     // get the value
                        printf("Please input a SKU number:");
                        scanf("%d",&sku);

                        found = 0;// set found value is 0 at the begainng, also "found = 0 repersent the sku number that you enter is not as same as others sku's number "

                        for(i=0; i<size; i++){ //
                                if(sku == item[i].sku_){
                                        found = 1;// found = 1 is repersent the sku's number is as same as other sku's number.

                                        printf("Quantity:");
                                        scanf("%d",&quantity);
                                        item[i].quantity_ = item[i].quantity_ + quantity;
                                        printf("The item exists in the repository, quanity is updated.\n");//finish update.
                                }
                        }

                        if(found == 0){ // this loop is going to add the new product.
                                if(size == MAX_ITEMS){
                                        printf("The inventory is full\n");// if size = MAX_ITEMS display "The inventory is full."
                                }else{
                                        item[size].sku_ = sku;

                                        printf("Quantity:");
                                        scanf("%d",&item[size].quantity_);
                                        printf("Price:");
                                        scanf("%f",&item[size].price_);
                                        printf("The item is successfully added to the inventory.\n");

                                        size++;
                                }
                        }

                }else if (optionsnum == 3) {
                        printf("Please input the sku number of the item:\n");
                        scanf("%d",&sku);

                        found = 0;

                        for(i=0; i<size; i++){
                                if(sku == item[i].sku_){
                                        found = 1;
                                        printf("Item %d costs $%.2f\n",item[i].sku_, item[i].price_);
                                }
                        }

                        if(found == 0){
                        printf("Item does not exist in the shop! Please try again.\n");

                        }
                }

        } while(1);

    return 0;
}

