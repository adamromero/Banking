#include <iostream>
#include "Banking.h"

int main(int argc, char *argv[]){
  	if(argc != 2){
		std::cout << "Usage: ./bank [databasefilename]\n";
		return 0;
	}
	
	Banking program(argv[1]);
	program.run();
	return 0;
}
