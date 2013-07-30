all: BankingDriver.o Account.o FileHandler.o Banking.o Functions.o
	g++ BankingDriver.o Account.o FileHandler.o Functions.o Banking.o -o bank

BankingDriver.o: BankingDriver.cpp
	g++ BankingDriver.cpp -c

Account.o: Account.cpp
	g++ Account.cpp -c
	
FileHandling.o: FileHandler.cpp
	g++ FileHandler.cpp -c

Functions.o: Functions.cpp
	g++ Functions.cpp -c
	
Bank.o: Banking.cpp
	g++ Banking.cpp -c

clean:
	rm -rf *o tic
