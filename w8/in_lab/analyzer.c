
#include <stdio.h>

#define MAX 100

struct studentMarks {
   int   id;
   float marks;
};

void welcome(void);
int get_data( struct studentMarks * ptr );
void show( struct studentMarks list[], int num );

void welcome(void)
{
	printf("####### Marks Analyzer V3.0 #######\n");
}

int get_data( struct studentMarks * ptr )
{
	//int i = 0;
	int id;
	float marks;
	int itself = 1;

	if(id != -1 && marks != -1){
		printf("Enter student id and marks (e.g. 12345 89.5): ");
		scanf("%d %f",&id,&marks);

		ptr -> id = id;
		ptr ->  marks = marks;
		itself = 0;
	}else if(id == -1 && marks == -1){
		return itself;
	}
	
	return 0;
}
void show( struct studentMarks list[], int num )
{
	int i;

	for(i=0;i<num; i++)
	{
		if(list[i].id==-1){
			break;
		}else if(list[i].marks==-1){
			break;
		}
		printf("%d. %d, %.2f\n",i+1, list[i].id, list[i].marks);	

	}
}

int main(void){

    struct studentMarks St[MAX];
	// declarations of a constant, an array and variables
	int Num = 0;
	
	welcome();// call a function to display a welcome message

	do{// 1. use a do-while loop to get student ids and student marks

		get_data(&St[Num]);
		Num++;
		
	}while(Num<MAX || get_data(&St[Num]) == 1);

	show(St,Num);// 2. print out all the student marks

    return 0;
}

