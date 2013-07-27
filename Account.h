#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account {
  private:
		std::string accountType;
		double balance;
	public:
		Account(std::string strType, double dBalance);
		Account(){}
		void setBalance(double dBalance);
		std::string getAccountType() const; 
		double getBalance() const; 
		void makeWithdraw(double withdraw);
	    void makeDeposit(double deposit);
		
};

#endif
