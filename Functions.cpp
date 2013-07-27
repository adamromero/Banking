#include <iostream>

void flushInputBuffer(){
  const int MAX_CHARS = 50;
	std::cin.clear();
	std::cin.ignore(MAX_CHARS, '\n');
}

std::string enterName(){
	std::string name;
	std::cout << "Enter name: \n";
	getline(std::cin, name);
	return name;
}

double enterAmount(){
	double amount;
	std::cin >> amount;
	return amount;
}

bool saveChanges(){
	char action;
	std::cout << "Save changes? y/n\n";
	
	while(true){
		flushInputBuffer();
		std::cin.get(action);
		action = tolower(action);
		if(action == 'y'){
			return true;
		} else if(action == 'n'){
			return false;
		} else {
			std::cout << "***Bad command***\n";
		}
	}
}
