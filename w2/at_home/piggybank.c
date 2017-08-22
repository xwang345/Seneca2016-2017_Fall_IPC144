// piggybank program workshop 2 IPC144
// name:Xiaochen Wang
// student number:015297153
// Section:

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int t,l,q,d,n,p;
	float total;
       	int w, e, s, o;
	float change;	
	
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

	total = t*2 + l + q*0.25+d*0.1+n*0.05+p*0.01;
	printf("You have $%.2f in your piggy bank!\n",total);
	
	w = total / 50;
	printf("$50 bill: %d\n",w);
	e = (total - w*50) / 20;
	printf("$20 bill: %d\n",e);
	s = (total - w*50 - e*20) / 10;
	printf("$10 bill: %d\n",s);
	o = (total - w*50 - e*20 - s*10) / 5;
	printf("$5 bill: %d\n",o);
	
	change = total -(w*50 + e*20 + s*10 + o*5 );
	printf("Change: $%.2f\n",change);

	return 0;
}
			   
		 
	     
