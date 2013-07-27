#ifndef FILEHANDLE_H
#define FILEHANDLE_H

#include <iostream>
#include <fstream>
#include "Account.h"

class FileHandler {
  private:
		std::ifstream *inputFile;
		std::ofstream *outputFile;
		const char *filename;
	public:
		FileHandler(std::string name);
		~FileHandler();
		bool exists();
		void readFromFile(std::string *name);
		void writeToFile(std::string name, Account &save, Account &check);
		void closeInputFile();
};

#endif
