all: BankingDriver.o Account.o FileHandler.o Banking.o Functions.o
	g++ BankingDriver.o Account.o FileHandler.o Functions.o Banking.o -o bank

BankingDriver.o: BankingDriver.cpp Banking.h
	g++ BankingDriver.cpp -c

Account.o: Account.cpp Account.h
	g++ Account.cpp -c
	
FileHandling.o: FileHandler.cpp FileHandler.h Banking.h
	g++ FileHandler.cpp -c

Functions.o: Functions.cpp Functions.h
	g++ Functions.cpp -c
	
Banking.o: Banking.cpp Banking.h FileHandler.h Account.h
	g++ Banking.cpp -c

clean:
	rm -rf *o tic
