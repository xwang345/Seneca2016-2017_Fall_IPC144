#include<stdio.h>
#include<stdlib.h>

	int main(void)
{
	int studentnum;
	int i;
	int stdno[40];
	float average = 0, total = 0;
	int mrk[40];

	printf("       ---=== IPC mark Analyser V2.0 ===---\n");
	printf("Please enter the number of students(between 3 and 40): ");
	scanf("%d", &studentnum);

	while (studentnum<3 || studentnum>40)
	{
		printf("Invalid number, enter a number between 3 and 40 inclusive: ");
		scanf("%d", &studentnum);
	}
	//================================================================================

	printf("Row   Std No  Mrk\n");
	printf("--- --------- ---\n");
	/*=================================== Input_Loop ==================================*/
	for(i=0;i<studentnum;i++)
	{
		printf("    _________ ___\r%3d ",i+1);
		scanf("%9d %3d",&stdno[i], &mrk[i]);
		total = total + mrk[i];
	}
	//==================================== Output  =====================================
	printf("=================\n");
	printf("Marks Entered, printing results:\n");
	printf("Row   Std No  Mrk\n");
	printf("--- --------- ---\n");
	//=================================== Output_Loop==================================

	for (i = 0; i < studentnum; i++)
	{
		printf("%03d %09d %3d\n",i+1,stdno[i], mrk[i]);
	}
	//==================================================================================
	average = total / studentnum;
	printf("=================\n");
	printf("The average of all marks in this group is %0.1f.\n", average);
	printf("Program Ended.\n");

	return 0;

}

/* the output
       ---=== IPC mark Analyser V2.0 ===---
Please enter the number of students(between 3 and 40): 2
Invalid number, enter a number between 3 and 40 inclusive: 41
Invalid number, enter a number between 3 and 40 inclusive: 5
Row   Std No  Mrk
--- --------- ---
  1 123456789 45_
  2 456789123 90_
  3 789123456 57_
  4 147258369 89_
  5 014725836 32_
=================
Marks Entered, printing results:
Row   Std No  Mrk
--- --------- ---
001 123456789  45
002 456789123  90
003 789123456  57
004 147258369  89
005 014725836  32
=================
The average of all marks in this group is 62.6.
Program Ended.
*/
