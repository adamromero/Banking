#include "FileHandler.h"
#include "Banking.h"

FileHandler::FileHandler(std::string name){
  filename = name.c_str();
	inputFile = new std::ifstream(filename);
	outputFile = NULL;
}

FileHandler::~FileHandler(){
	delete inputFile;
	if(outputFile)
		delete outputFile;
}

bool FileHandler::exists(){ 
	return (*inputFile);
}

void FileHandler::readFromFile(std::string *line){
	int idx = 0;
	while(inputFile->good()){
		getline(*inputFile, line[idx++]);
	}
}

void FileHandler::writeToFile(std::string name, Account &save, Account &check){
	outputFile = new std::ofstream(filename);
	*outputFile << name << std::endl;
	*outputFile << save.getBalance() << std::endl;
	*outputFile << check.getBalance() << std::endl;
	outputFile->close();
}

void FileHandler::closeInputFile(){
	inputFile->close();
}
