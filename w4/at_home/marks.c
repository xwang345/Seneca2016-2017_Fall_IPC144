#include<stdio.h>
#include<stdlib.h>

	int main(void)
{
	int studentnum;
	int i, ps = 0, fs = 0;
	int stdno[40];
	float average = 0, total = 0, an1, an2;
	int mrk[40];
	int max = 0, min = 0;
	float ap, af;

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
		scanf("%10d %3d",&stdno[i], &mrk[i]);//scan 10 spaces
		while(mrk[i]<0||mrk[i]>100)
		{
			printf("Error: Enter mark values between 0 and 100 inclusive.\n");
			printf("    _________ ___\r%3d ",i+1);
			scanf("%10d %3d",&stdno[i], &mrk[i]);
		}
		while(stdno[i]<10000000||stdno[i]>999999999)
		{
			printf("Error: Enter student number values between 10000000 and 999999999 inclusive.\n");
			printf("    _________ ___\r%3d ",i+1);
			scanf("%10d %3d",&stdno[i], &mrk[i]);
		}

		
//======================================= Count Passed and filed students number=================
		if(mrk[i] >= 50)
		{
			ps++;
			an1 +=  mrk[i];
		}else if(mrk[i] < 50)
		{
			fs++;
			an2 += mrk[i];
		}
//======================================= Find min and max marks number============================
		if(i == 0)
		{
			min = mrk[i];
		}else if(mrk[i] < min)
		{
			min = mrk[i];
		}
		if(mrk[i] > max)
		{
			max = mrk[i];
		}
//===============================================================================================
		total += mrk[i];
	}
	//==================================== Output  =====================================
	printf("=================\n");
	printf("Marks Entered, printing results:\n");
	printf("Row   Std No  Mrk\n");
	printf("--- --------- ---\n");
	//=================================== Output_Loop==================================

	for (i = 0; i < studentnum; i++)
	{
		if(max == mrk[i])
		{
			printf("%03d %09d %3d ***Highest mark***\n", i+1, stdno[i], mrk[i]);
		}
		else if(min ==mrk[i])
		{
			printf("%03d %09d %3d ***Lowest mark***\n",i+1, stdno[i], mrk[i]);
		}else{
			printf("%03d %09d %3d\n",i+1, stdno[i], mrk[i]);
		}
	}
	//==================================================================================
	average = total / studentnum;
	ap =  an1 / ps;
	af =  an2 / fs;
//========================================== Output the result =============================
	printf("=================\n");
	printf("Total of %d students passed with an average of %0.1f.\n",ps,ap);
	printf("Total of %d students failed with an average of %0.1f.\n",fs,af);
	printf("Highest mark in group: %d\n",max);
	printf("Lowest mark in group: %d\n",min);
	printf("The average of all marks in this group is %0.1f.\n", average);
	printf("Program Ended.\n");

	return 0;

}   
