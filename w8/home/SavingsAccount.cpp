#include "SavingsAccount.h"
#include<iomanip>
#include<iostream>
using namespace std;

namespace ict{ 
	
	// TODO: Implement SavingsAccount member functions here
	SavingsAccount::SavingsAccount(double n_balance,double n_interest):Account(n_balance){
		(n_interest < 0) ? interestRate = 0 : interestRate = n_interest;
	}
        
        
	std::ostream& SavingsAccount::display(std::ostream& os) {
		os << fixed<<setprecision(2);
		os << "Account type: Saving" << endl;
		os << "Balance: $ " << getBalance() << endl;
		os << "Interest Rate (%): " <<interestRate*100 << endl;
		return os;
        }
	double SavingsAccount::calculateInterest() {
		return getBalance()*interestRate;
	}
}