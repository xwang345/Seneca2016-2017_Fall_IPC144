#include "CheckingAccount.h"
#include<iostream>
#include<iomanip>
using namespace std;

namespace ict {

    // TODO: define CheckingAccount class member functions here  

    CheckingAccount::CheckingAccount(double c_balance, double c_transcation) : Account(c_balance) {
        if (c_transcation < 0)transactionFee = 0;
        else transactionFee = c_transcation;
    }

    void CheckingAccount::chargeFee(double fee) {
        Account::setBalance(Account::getBalance()-fee);
    }
    
    void CheckingAccount::credit(double fee){
        Account::setBalance(Account::getBalance()+fee-transactionFee);
	CheckingAccount::chargeFee(transactionFee);
    }
    
    bool CheckingAccount::debit(double debit_fee) {
        if (debit_fee <= Account::getBalance()) {
          	CheckingAccount::chargeFee((debit_fee-transactionFee));
	  	CheckingAccount::chargeFee(transactionFee);
		return 1;
        } else {
            return 0;
        }
    }

    std::ostream & CheckingAccount::display(std::ostream & os){
        os << fixed << setprecision(2);
        os << "Account type: Checking" << endl;
        os << "Balance: $ " << getBalance() << endl;
        os << "Transaction Fee: " << transactionFee << endl;
        return os;
    }

}
