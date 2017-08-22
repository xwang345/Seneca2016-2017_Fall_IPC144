#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i;
	int marks;
	float n, average , total = 0;
	
	printf("       ---=== IPC mark Analyser ===---\n");
	printf("Please enter the number of marks(between 3 and 40): ");
	scanf("%d",&marks);

	while(marks<3||marks>40)
	{
		printf("Invalid number, enter a number between 3 and 40 inclusive: ");
		scanf("%d",&marks);
	}

	for(i=1;i<=marks;i++)
	{
		printf("%d> ",i);
		scanf("%f",&n);
		total = total + n;
	}

	average = total / marks;
	printf("The average of all marks in this group is %.1f.\n",average);
	printf("Program Ended.\n");
	return 0;
}
