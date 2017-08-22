
#include <stdio.h>

#define MAX 100
struct studentMarks {
   int   id;
   float marks;
};

void welcome(void);
int get_data( struct studentMarks * ptr );
void show( struct studentMarks list[], int num );
float analyze( struct studentMarks list[], int num, float* ptr_highest, float* ptr_lowest);
void print_summary( float avg, float high, float low);

void welcome(void)
{
	printf("####### Marks Analyzer V3.0 #######\n");
}

int get_data( struct studentMarks * ptr )
{
	int id;
	float marks;
	int itself = 1;

	printf("Enter student id and marks (e.g. 12345 89.5): ");
	scanf("%d %f",&id,&marks);

	if(id != -1 && marks != -1){
		ptr->id = id;
		ptr->marks = marks;
		itself = 0;
	}else {
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

float analyze( struct studentMarks list[], int num, float* ptr_highest, float* ptr_lowest)
{
	float avg = 0, total = 0;
	int i;

	*ptr_lowest = list[0].marks;
	*ptr_highest = list[0].marks;
	
	for(i=0;i<num;i++){
		total += list[i].marks;
	
		if(list[i].marks < *ptr_lowest){
			*ptr_lowest = list[i].marks;
		}
		else if(list[i].marks > *ptr_highest)
		{
			*ptr_highest = list[i].marks;
		}
	}
	
	avg = total / num;
	
	return avg;
}

void print_summary( float avg, float high, float low)
{
	printf("### result of marks analysis ###\n");
	printf("average: %.2f, highest marks: %.2f, lowest marks: %.2f\n",avg,high,low);
}

int main(void){

	float avg = 0, highestMark = 0, lowestMark = 0;
    struct studentMarks St[MAX];
	// declarations of a constant, an array and variables
	int Num = 0;
	int a;
	welcome();// call a function to display a welcome message

	do{// 1. use a do-while loop to get student ids and student marks

		a = get_data(&St[Num]);
		if ( a != 1) {
			Num++;
		}
		
	}while(Num<MAX && a != 1);

	show(St,Num);// 2. print out all the student marks


   avg = analyze(St, Num, &highestMark, &lowestMark);// 3. data analysis


   print_summary(avg,highestMark, lowestMark);// 4. print the result of data analysis


    return 0;
}

