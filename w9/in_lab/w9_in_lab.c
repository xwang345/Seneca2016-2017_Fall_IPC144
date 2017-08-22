// Workshop 9 - Files

// Name: Xiaochen Wang
// Student #: 015297153
#include<stdio.h>
#include<stdlib.h>
struct Box{
   int id;        // the box ID
   double size[3];   // dimensions of the box (Length, Width, Height)
   double weight; // weight of the box
};

void listBoxes(const char filename[]) // lists all boxes in the file
{
    FILE *fp = NULL;
    struct Box w;
    int ret;

    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);         
    }
    

    printf("List of boxes\n");
    printf("=============\n\n");
    printf("ID Length Width Height Weight\n");
    printf("-----------------------------\n");
    	
    fp = fopen(filename,"r");
    
	while(!feof(fp)){
		ret = fscanf(fp,"%d %lf %lf %lf %lf",&w.id, &w.size[0], &w.size[1], &w.size[2], &w.weight);
		if ( ret != EOF) {
			printf("%2d %6.2lf %5.2lf %6.2lf %6.2lf\n", w.id, w.size[0], w.size[1], w.size[2], w.weight);
		}
	}
	
	printf("\n");

    fclose(fp);
    
}

void printBox(struct Box b);     // print one box- already implemented for you

// returns the record number of a box with specified ID, if found
int searchBox( FILE *fp, int id2Find)
{
	int a = -1;
	int i=0;
	struct Box w;

	if( fp != NULL){
    
		while(fscanf(fp,"%d %lf %lf %lf %lf", &w.id, &w.size[0], &w.size[1], &w.size[2], &w.weight) != EOF){
			if(w.id == id2Find){
				a = i;
			}
			i++;
		}
	}
	return a;
};


void displayBox(const char filename[], int id2Find)     // display a box, given ID
{
	FILE *fp = NULL;
	fp = fopen(filename,"r");
	int i=0;
	int a=0;
	struct Box w;
	
	if(fp == NULL){
		printf("Error!\n");
	}else{
		a = searchBox(fp, id2Find);
		
		if(a != -1){
			rewind(fp);
			do{
				fscanf(fp, "%d %lf %lf %lf %lf",&w.id, &w.size[0], &w.size[1], &w.size[2], &w.weight);
				i++;
			}while(i <= a);
			
			printf("Found box %d as record #%d:\n", w.id, i);
			printBox(w);			
			}else{
				printf("This box is not recorded.\n\n");
			} 
		}
	fclose(fp);
	
}
//int addBox(const char filename[], const struct Box * b2Add);// add a box to file

int numberBoxes(const char filename[]);      // find the number of boxes in a file
int getRandomInt(int lower, int higher);  // get a random number
void displayBoxN(char filename[], int n); // display a box given its record number

void printBox(struct Box b){
   printf("\nID:     %6d\n"
      "Length: %6.2lf\n"
      "Width:  %6.2lf\n"
      "Height: %6.2lf\n"
      "Weight: %6.2lf\n\n", b.id, b.size[0], b.size[1], b.size[2], b.weight);
}

int menu(void){
   int choice = -1;

   printf("1- List all boxes\n");
   printf("2- Find a box\n");
   printf("3- Add a box\n");
   printf("4- Randomly pick a lucky box!\n");
   printf("0- Exit program\n");

   printf("Select an option: ");
   do{
      scanf("%d", &choice);
      if (choice < 0 || choice > 4)
         printf("Please enter a number between 0 and 4: ");
   } while (choice < 0 || choice > 4);
   return choice;
}


int main(void){

   int choice; // , boxID, r;
   char filename[] = "storage.txt";
   struct Box b;//struct Box b;


   printf("Welcome to My Storage Room\n");
   printf("==========================\n");
   do {
      // get user's choice
      choice = menu();


      switch (choice){
      case 1:
         // IN_LAB: list items
		listBoxes(filename);
         break;

      case 2:
         // IN_LAB: find a box given its ID
        printf("Enter box ID: ");// ask for ID
        scanf("%d",&b.id);
	displayBox(filename,b.id);// call displayBox
         break;

      case 3:
         // AT_HOME: add a box
         // get user input for box's ID, size and weight



         // call addBox, print message to show number of boxes added



         break;

      case 4:
         // AT_HOME: randomly pick a lucky box



         // choose a random number between 1 and the number of boxes in storage


         // display the lucky box!



         break;


      };

   } while (choice > 0);

   return 0;
}

/*
Welcome to My Storage Room
==========================
1- List all boxes
2- Find a box
3- Add a box
4- Randomly pick a lucky box!
0- Exit program
Select an option: 1
List of boxes
=============

ID Length Width Height Weight
-----------------------------
10  50.34 61.00  30.00  50.50
11  25.60 12.34   9.23  12.89
55  10.00 20.00  30.00  40.50
56  30.00 40.00  50.00  60.00
57   5.20  6.30   7.40   8.50

1- List all boxes
2- Find a box
3- Add a box
4- Randomly pick a lucky box!
0- Exit program
Select an option: 2
Enter box ID: 55
Found box 55 as record #3:

ID:         55
Length:  10.00
Width:   20.00
Height:  30.00
Weight:  40.50

1- List all boxes
2- Find a box
3- Add a box
4- Randomly pick a lucky box!
0- Exit program
Select an option: 2
Enter box ID: 15
This box is not recorded.

1- List all boxes
2- Find a box
3- Add a box
4- Randomly pick a lucky box!
0- Exit program
Select an option: 0
*/
