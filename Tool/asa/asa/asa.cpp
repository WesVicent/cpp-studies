// asa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "App.h"
#include "Rules.h"
#include "FileManager.h"
#include <iostream>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{
	App::info(argc, argv);
	Rules *rules = new Rules();

	string fileName = "C:\\Users\\conta\\Desktop\\file.txt";
	FileManager *fManager = new FileManager(fileName);
	string fileName2 = "C:\\Users\\conta\\Desktop\\file2.txt";
	FileManager *fManager2 = new FileManager(fileName2);

	if (argc > 1) {
		fManager->read();
		cout << rules->ifExistsInText(argv[1], rules->functionNames(fManager->getTempText())) <<endl;

		fManager2->read();
		cout << rules->ifExistsInText(argv[1], rules->functionNames(fManager2->getTempText())) << endl;

	}
	return 0;

}