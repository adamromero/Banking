#include "Account.h"
	
Account::Account(std::string strType, double dBalance) 
	: accountType(strType), balance(dBalance){}

std::string Account::getAccountType() const { 
	return accountType;
}

double Account::getBalance() const{ 
	return balance;
} 

void Account::makeWithdraw(double withdraw) {
	balance -= withdraw;
}

void Account::makeDeposit(double deposit) {
	balance += deposit;
}
