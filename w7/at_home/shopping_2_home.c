
#include <stdio.h>

#define MAX_ITEMS 10
struct Item {
       int _sku;
       float _price;
       int _quantity;
};


void displayInventory(const struct Item items[],const int size);
void clear();
int validate(const int low, const int high);
void displayInventory(const struct Item items[],const int size);
int searchInventory(const struct Item items[],const int sku_item,const int size);
void addItem(struct Item items[], int *size);
void checkPrice(const struct Item items[],const int size);
void menu();


void clear()
{
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n");
}

//========================================================================================

int validate(const int low, const int high)
{
	int Value;

	scanf("%d", &Value);

	while(Value<low||Value>high){
			printf("Invalid input, try again: ");
			scanf("%d", &Value);
		}


	return Value;
}

//=========================================================================================
void displayInventory(const struct Item items[],const int size)
{
	int i;

	printf("\n\nInventory\n");
    printf("=========================================\n");
	printf("Sku         Price       Quantity\n");

    for(i=0; i< size; i++){

    	printf("%d        %-5.2f       %-10d\n", items[i]._sku, items[i]._price, items[i]._quantity);
    }
    printf("=========================================\n");
}
//==========================================================================================

int searchInventory(const struct Item items[],const int sku_item,const int size)
{

	int i;

    for(i=0; i < size; i++){ //

		if(sku_item == items[i]._sku){
    		return i;
    	}
	}

	return -1;
}

void addItem(struct Item items[], int *size)
{
	int skuNo, Quantity1;
	float Price1;

	printf("Please input a SKU number: ");
	scanf("%d",&skuNo);
	printf("Quantity: ");
	scanf("%d",&Quantity1);

	int res = searchInventory(items,skuNo,*size);

	if (res == -1)
	{
	// not found
		if(*size == MAX_ITEMS){
    		printf("The inventory is full\n");// if size = MAX_ITEMS display "The inventory is full."
    	}else{
            printf("Price: ");
            scanf("%f",&Price1);
            items[*size]._sku = skuNo;
            items[*size]._quantity = Quantity1;
            items[*size]._price = Price1;
            printf("The item is successfully added to the inventory.\n");

            *size = *size + 1;
        }
	}else{
	// found
		items[res]._sku = skuNo;
		items[res]._quantity = items[res]._quantity + Quantity1;
    	printf("The item exists in the repository, quanity is updated.\n");//finish update.

	}

}
//=================================================================================

void menu()
{
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add to the inventory.\n");
	printf("3) Check price.\n");
	printf("4) Clear Screen.\n");
	printf("0) Exit.\n");
	printf("Select: ");
}

//=================================================================================
void checkPrice(const struct Item items[],const int size)
{
	int skuNo;
	printf("Please input the sku number of the item: ");
	scanf("%d",&skuNo);
	int res = searchInventory(items,skuNo,size);
	
	if(res== -1){
		printf("Item does not exist in the shop! Please try again.\n");
	}else{
		printf("Item %d costs $%.2f\n",items[res]._sku,items[res]._price);
	}
}



int main(){
	struct Item item[MAX_ITEMS];
	int size = 0;
	int optionsnum;

	clear();
	printf("Welcome to the Shop\n");
	printf("===================\n");

	do{

		menu();
    	optionsnum = validate(0,4);

		if(optionsnum==0){
			printf("Good bye!\n");
			return 0;
		}else if(optionsnum==1){
			displayInventory(item,size);
		}else if(optionsnum==2){
			addItem(item,&size);
		}else if(optionsnum==3){
			checkPrice(item,size);
		}else if(optionsnum==4){
			clear();
		}
	}while(1);

   return 0;
}


/* Output




















Welcome to the Shop
===================
Please select from the following options:
1) Display the inventory.
2) Add to the inventory.
3) Check price.
4) Clear Screen.
0) Exit.
Select: 2
Please input a SKU number: 1234
Quantity: 23.90
Price: The item is successfully added to the inventory.
Please select from the following options:
1) Display the inventory.
2) Add to the inventory.
3) Check price.
4) Clear Screen.
0) Exit.
Select: 2
Please input a SKU number: 9010
Quantity: 5
Price: 89.20
The item is successfully added to the inventory.
Please select from the following options:
1) Display the inventory.
2) Add to the inventory.
3) Check price.
4) Clear Screen.
0) Exit.
Select: 2
Please input a SKU number: 8721
Quantity: 4
Price: 19.99
The item is successfully added to the inventory.
Please select from the following options:
1) Display the inventory.
2) Add to the inventory.
3) Check price.
4) Clear Screen.
0) Exit.
Select: 1


Inventory
=========================================
Sku         Price       Quantity
1234        0.90        23
9010        89.20       5
8721        19.99       4
=========================================
Please select from the following options:
1) Display the inventory.
2) Add to the inventory.
3) Check price.
4) Clear Screen.
0) Exit.
Select: 3
Please input the sku number of the item: 7777
Item does not exist in the shop! Please try again.
Please select from the following options:
1) Display the inventory.
2) Add to the inventory.
3) Check price.
4) Clear Screen.
0) Exit.
Select: 3
Please input the sku number of the item: 9010
Item 9010 costs $89.20
Please select from the following options:
1) Display the inventory.
2) Add to the inventory.
3) Check price.
4) Clear Screen.
0) Exit.
Select: 0
Goodbye!
*/



