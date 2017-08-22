#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int t, l, q, d, n, p;
	float total;

	printf("Please enter the number of coins in your piggy bank:\n");

	printf("Toonies: ");
	scanf("%d",&t);
	printf("Loonies: ");
	scanf("%d",&l);
	printf("Quarters: ");
	scanf("%d",&q);
	printf("Dimes: ");
	scanf("%d",&d);
	printf("Nickels: ");
	scanf("%d",&n);
	printf("Pennies: ");
	scanf("%d",&p);

	total = t*2 + l + q*0.25 + d*0.1 + n*0.05 + p*0.01;
	printf("You have $%.2f in your piggy bank!\n",total);

	return 0;
}
