/* marks.c */
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int i, ps = 0, fs = 0;
	int marks;
	float an1,an2;
	float n, average = 0, ap, af, total = 0;
	int max = 0, min =0;
	
	
	printf("       ---=== IPC mark Analyser ===---\n");
	printf("Please enter the number of marks(between 3 and 40): ");
	scanf("%d",&marks);

	while(marks<3||marks>40)
	{
		printf("Invalid number, enter a number between 3 and 40 inclusive: ");
		scanf("%d",&marks);

	}

	for(i=0;i<marks;i++)
	{
		printf("%d> ",i+1);
		scanf("%f",&n);
		while(n<0||n>100)
		{
			printf("Error: Enter values between 0 and 100 inclusive.\n");
			printf("%d> ",i+1);
			scanf("%f",&n);
		}
//=============================================================================================		
		if(n >= 50)//ps: passed students counter.
		{

			ps++;
			an1 = an1 + n;
		}
		else if(n < 50)//fs: failed students counter.
		{

			fs++;
			an2 = an2 + n;
		}
	
//===================================Find min and max number===================================	

		if(i == 0){
			min = n;
		}else if(n < min)
		{
			min = n;
		}
		if(n > max)
		{
			max = n;
		}
//=================================================================================================
		total = total + n;
	}
		
		average = (float) total /marks;
		ap = (float) an1 / ps;
		af = (float) an2 / fs;

	printf("Total of %d students passed with an average of %.1f.\n",ps,ap);
	printf("Total of %d students failed with an average of %.1f.\n",fs,af);

	printf("Highest mark in group: %d\n",max);
	printf("Lowest mark in group: %d\n",min);
	printf("The average of all marks in this group is %.1f.\n",average);
	printf("Program Ended.\n");
	return 0;

}
