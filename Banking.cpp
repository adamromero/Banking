#include <stdlib.h>
#include "Banking.h"
#include "Functions.h"

Banking::Banking(std::string file) : filename(file){}

void Banking::setBankingFields(std::string name, Account save, Account check){
	accountHolder = name;
	savings = save;
	checking = check;
}

void Banking::savingsTransaction(){
	std::cout << "Enter amount: \n";
	double transfer = enterAmount();
	isDeposit? savings.makeDeposit(transfer) : savings.makeWithdraw(transfer);
}

void Banking::checkingTransaction(){
	std::cout << "Enter amount: \n";
	double transfer = enterAmount();
	isDeposit? checking.makeDeposit(transfer): checking.makeWithdraw(transfer);
}

void Banking::chooseAccount(){
	int accountNum = 0;
	std::cout << "Savings(1) or Checking(2):\n";
	
	while(true){
		std::cin >> accountNum;
		if(accountNum == 1){
			savingsTransaction();
			break;
		} else if(accountNum == 2){
			checkingTransaction();
			break;
		} else {
			std::cout << "***Bad command***\n";
			flushInputBuffer();
		}
	}
}

void Banking::showAccountInfo(){
	std::cout << "--------------------------------------------\n";
	std::cout << "Account Holder: " << accountHolder << std::endl;
	std::cout << "--------------------------------------------\n";
	std::cout << "Balance\t\t\t\tAccount Type\n";
	std::cout << "--------------------------------------------\n";
    std::cout << "$" << savings.getBalance() << "\t\t\t\t" << savings.getAccountType() << std::endl;
    std::cout << "$" << checking.getBalance() << "\t\t\t\t" << checking.getAccountType() << std::endl;
    double totalBalance = savings.getBalance() + checking.getBalance();
	std::cout << "Total Balance: $" << totalBalance << std::endl;

}

bool Banking::manageAccount(){
	int choice = -1;
	while(true){
		showAccountInfo();
		std::cout << "Deposit(1), Withdraw(2) or Exit(0): \n";
		std::cin >> choice;

		if(choice >= 0 && choice <= 2){
			if(!choice)
				return false;
			isDeposit = choice == 1? true : false;
			chooseAccount();
			choice = -1;
		} else {
			std::cout << "***Bad command***\n";
			flushInputBuffer();
		}	
	}
}

void Banking::run(){
	const int LINES = 4;
	std::string line[LINES], name;
	double saveBalance = 0, checkBalance = 0;
	FileHandler file(filename);

	if(file.exists()){ 
		file.readFromFile(line);	 
		name = line[0];
		saveBalance = atof(line[1].c_str());
		checkBalance = atof(line[2].c_str());
	} else { 
		name = enterName();
		std::cout << "Enter savings balance: \n";
		saveBalance = enterAmount();
		std::cout << "Enter checking balance: \n";
		checkBalance = enterAmount(); 
	}
	
	Account save("Savings", saveBalance);
	Account check("Checking", checkBalance);
	setBankingFields(name, save, check);
	manageAccount();
	file.closeInputFile();
	
	if(saveChanges())	
		file.writeToFile(name, savings, checking);	
	std::cout << "Good-bye!\n";
}
