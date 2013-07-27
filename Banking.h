#ifndef BANKING_H
#define BANKING_H

#include "Account.h"
#include "FileHandler.h"

class Banking {
  	private:
		std::string accountHolder;
		Account savings;
		Account checking;
		std::string filename;
		bool isDeposit;
	public:
		Banking(std::string file);
		void setBankingFields(std::string name, Account save, Account check);
		std::string getAccountHolder();
		Account getSavings();
		Account getChecking();
		bool manageAccount();
		void chooseAccount();
		void savingsTransaction();
		void checkingTransaction();
		void showAccountInfo();
		void writeToFile();
		void run();
};

#endif
