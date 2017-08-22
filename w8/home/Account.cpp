#include "Account.h"

using namespace std;

namespace ict{ 
	double balance;
	// constructor   
	Account::Account() {
		balance = 0;
	}
	Account::Account(double n_balance) {
		if (n_balance >= 0) {
			Account::setBalance(n_balance);
		}
		else {
			balance = 1.0;
			std::cout << "Wrong Input Value!!";
		}
	}

	// credit (add) an amount to the account balance
	void Account::credit(double n_balance2) {
		balance +=n_balance2;
	}
	
	// debit (subtract) an amount from the account balance return bool 
	bool Account::debit(double n_balance3) {
		if (balance < n_balance3) return 0;
		else balance -= n_balance3;
		return 1;
	}

	double Account::getBalance() const
	{
		return balance;
	} 

	void Account::setBalance( double newBalance )
	{
		balance = newBalance;
	} 
}

