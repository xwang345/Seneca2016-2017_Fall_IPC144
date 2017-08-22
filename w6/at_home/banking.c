/*/*
== Banking - Savings Account ==

Author	:
Date	:
Revision:
Workshop: #6 in-Lab

*/

#include <stdio.h>


// Structure Declaration for account
struct account
{
	int accNumber;				// Account number
	double balance;				// Balance of the account
};

/*  Function to add an amount if positive-valued */
double balanceUp(double balance, double amount)//
{
	double result;
	result = balance + amount;
	return result;
}

/* Function to calculate the interest rate*/
double interestCalc(double balance, double rate)
{
	double monthly_rate;
	monthly_rate = balance * (rate/100);
	return monthly_rate;
}
//acct[nosClients].balance = acct[nosClients].balance + cad;//

double balanceDown(double balance, double amount)
{
	double result;
	result = balance - amount;
	return result;
}

/* main program */
int main()
{
	const int nosClients = 5;							// Number of accounts
	int option;											// Hold the selection
	// Initialize the struct account array with opening balance
	struct account acct[] = { { 11111111, 123.45 },{ 22222222, 12365.50 },{ 33333333,0 },{ 44444444,1475 },{ 55555555,25000.65 } };
	float cad, rate1;
	int i;
	int account_number, flag;
	double calcInterest[nosClients];
	double servicecharge;
	double service_charge_array[nosClients];

	
	printf("***** Welcome to Savings Account Banking *****\n\n");

	do
	{
		// Print the option list
		printf("1.) Deposit \n");
		printf("2.) Withdraw\n");
		printf("3.) Apply monthly interest earnings to all accounts\n");
		printf("4.) Apply service charges to all accounts\n");
		printf("5.) Account Summary\n");
		printf("0.) Log out\n\n");
		printf("Please enter an option to continue: ");
		
		// Waiting for the input
		scanf("%d",&option);

		switch (option)
		{
		case 0: // Exit the program
		
			break;

		case 1: // Deposit
				//@IN-LAB				
		printf("\n");
		printf("-- Make a deposit --\n");
		printf("\n");
		printf("Enter account number: ");
		scanf("%d",&account_number);
		
		// Suposes that element is not in the array
		flag = 0;
		for(i=0; i<nosClients; i++)
		{
			if(acct[i].accNumber==account_number)
			{
				flag = 1;//if flag = 1 means account number is found in the array.
				printf("Enter amount to deposit (CAD): ");
				scanf("%f",&cad);
				printf("Current balance is : %.2f\n\n",balanceUp(acct[i].balance, cad));
				acct[i].balance = balanceUp(acct[i].balance,cad);
			}
			
		}
		//if flag = 0 means account number is not found in the array.
		if(flag==0)
		{
			printf("ERROR: Account number does not exist.\n\n");
			break;
		}
			break;

		case 2: // Withdraw funds
				//@HOME
		printf("\n");
		printf("-- Withdraw funds --\n");
		printf("\n");
		printf("Enter account number: ");
		scanf("%d",&account_number);
		
		// Suposes that element is not in the array
		flag = 0;
		for(i=0; i<nosClients; i++)
		{
			if(acct[i].accNumber==account_number)
			{
				flag = 1;//if flag = 1 means account number is found in the array.
				printf("Enter amount to withdraw (CAD): ");
				scanf("%f",&cad);
				if(balanceDown(acct[i].balance, cad)<0)
				{
					printf("Withdrawal failed. You only have : 0.00 in your account\n\n");
				}
				if(balanceDown(acct[i].balance, cad)>0)
				{
					printf("Current balance is : %.2f\n",balanceDown(acct[i].balance, cad));
					acct[i].balance = balanceDown(acct[i].balance,cad);
					printf("\n");					
				}
			}
			
		}
		//if flag = 0 means account number is not found in the array.
		if(flag==0)
		{
			printf("ERROR: Account number does not exist.\n\n");
			break;
		}	

			break;

		case 3: // Apply interest earnings to all accounts
				//@IN-LAB

			for(i=0; i < nosClients; i++)
			{
				if(acct[i].balance <= 500)
				{
					rate1 = 0.99;
				}else if(acct[i].balance <= 1500){
					rate1 = 1.66; 
				}else{
					rate1 = 2.49;
				}
				calcInterest[i] = interestCalc(acct[i].balance, rate1);
				acct[i].balance = balanceUp(acct[i].balance,calcInterest[i]);
				
			}
			printf("\n");
			printf("-- Add monthly interest earnings to all accounts --\n");
			printf("\n");
			printf("Account# New Balance Interest Earnings (M)\n");
			printf("-------- ----------- ---------------------\n");
				for(i=0; i<nosClients; i++)
				{
					printf("%8d %11.2lf %21.2lf\n", acct[i].accNumber, acct[i].balance, calcInterest[i]);
				}	
			printf("\n");
		
			
			break;

		case 4: // Apply Service Charges
				//@HOME

			for(i=0; i < nosClients; i++)
			{
				if(acct[i].balance <= 1500)
				{
					servicecharge = 7.50;
				}else{
					servicecharge = 2.50;
				}
				
				service_charge_array[i] = servicecharge;
				acct[i].balance = balanceDown(acct[i].balance,service_charge_array[i]);
				
			}
			printf("\n");
			printf("-- Apply service charges to all accounts --\n");
			printf("\n");
			printf("Account# New Balance Service charges (M)\n");
			printf("-------- ----------- -------------------\n");
				for(i=0; i<nosClients; i++)
				{
					printf("%8d %11.2lf %19.2lf\n", acct[i].accNumber, acct[i].balance, service_charge_array[i]);
				}	
			printf("\n");			

			break;

		case 5: // Display Account Information
				//@IN-LAB
		printf("\n");
		printf("-- Account information --\n\n");
		printf("Account# Balance   \n");
		printf("-------- ----------\n");
		
		//for(i=0; i<5; i++)
		//{
		for(i=0; i<nosClients; i++)
		{
			//printf("%d",i);
			printf("%8d %10.2lf\n",acct[i].accNumber,acct[i].balance);
		}
		//}
		printf("\n");
			break;

		default:
			printf("Error: Please enter a valid option to continue\n\n");
			break;
		}


	} while (option != 0);


	return 0;
}


/* SAMPLE INPUT/OUTPUT EXPECTED */
/*
***** Welcome to Savings Account Banking *****

1.) Deposit
2.) Withdraw
3.) Apply monthly interest earnings to all accounts
4.) Apply service charges to all accounts
5.) Account Summary
0.) Log out

Please enter an option to continue: 5

-- Account information --

Account# Balance
-------- ----------
11111111     123.45
22222222   12365.50
33333333       0.00
44444444    1475.00
55555555   25000.65

1.) Deposit
2.) Withdraw
3.) Apply monthly interest earnings to all accounts
4.) Apply service charges to all accounts
5.) Account Summary
0.) Log out

Please enter an option to continue: 1

-- Make a deposit --

Enter account number: 67676767
ERROR: Account number does not exist.

1.) Deposit
2.) Withdraw
3.) Apply monthly interest earnings to all accounts
4.) Apply service charges to all accounts
5.) Account Summary
0.) Log out

Please enter an option to continue: 1

-- Make a deposit --

Enter account number: 44444444
Enter amount to deposit (CAD): 20
Current balance is : 1495.00

1.) Deposit
2.) Withdraw
3.) Apply monthly interest earnings to all accounts
4.) Apply service charges to all accounts
5.) Account Summary
0.) Log out

Please enter an option to continue: 1

-- Make a deposit --

Enter account number: 11111111
Enter amount to deposit (CAD): 450.67
Current balance is : 574.12

1.) Deposit
2.) Withdraw
3.) Apply monthly interest earnings to all accounts
4.) Apply service charges to all accounts
5.) Account Summary
0.) Log out

Please enter an option to continue: 5

-- Account information --

Account# Balance
-------- ----------
11111111     574.12
22222222   12365.50
33333333       0.00
44444444    1495.00
55555555   25000.65

1.) Deposit
2.) Withdraw
3.) Apply monthly interest earnings to all accounts
4.) Apply service charges to all accounts
5.) Account Summary
0.) Log out

Please enter an option to continue: 3

-- Add monthly interest earnings to all accounts --

Account# New Balance Interest Earnings (M)
-------- ----------- ---------------------
11111111      583.65                  9.53
22222222    12673.40                307.90
33333333        0.00                  0.00
44444444     1519.82                 24.82
55555555    25623.17                622.52

1.) Deposit
2.) Withdraw
3.) Apply monthly interest earnings to all accounts
4.) Apply service charges to all accounts
5.) Account Summary
0.) Log out

Please enter an option to continue: 5

-- Account information --

Account# Balance
-------- ----------
11111111     583.65
22222222   12673.40
33333333       0.00
44444444    1519.82
55555555   25623.17

1.) Deposit
2.) Withdraw
3.) Apply monthly interest earnings to all accounts
4.) Apply service charges to all accounts
5.) Account Summary
0.) Log out

Please enter an option to continue: 0

*/
