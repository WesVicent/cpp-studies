#ifndef FILEHOLDER_H_INCLUDED
#define FILEHOLDER_H_INCLUDED
/*
	Created by WesFerreira 30/11/2018
*/

#include <iostream>
#include <string>

#include "FileManager.h"

class FileHolder : private FileManager
{
public:
	friend class Igniter;

protected:
	static FileHolder* getInstance(); // Only inherited or friend can to have this class.
	static std::string getFileContent(const FileHolder &fh);

private:
	std::string fileContent = "Welis";

	static FileHolder* instance;
	void hold();
};
FileHolder* FileHolder::instance = 0;
FileHolder* FileHolder::getInstance()
{
	if (instance == 0)
	{
		instance = new FileHolder();
	}

	return instance;
}

std::string FileHolder::getFileContent(const FileHolder &fh) {
	return fh.fileContent;
}

void FileHolder::hold() {
	getInstance()->fileContent = read("C:\\Users\\conta\\Desktop\\file2.txt");
	std::cout << getInstance()->fileContent << std::endl;
}

#endif
