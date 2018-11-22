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

	if (argc == 1) {
		fManager->read();
		fManager2->read();

		if (rules->ifExistsInText("asa", rules->functionNames(fManager->getTempText()))) {
			cout << rules->functionBody("asa", fManager->getTempText()) << endl;
		}
		else
		{
			cout << "Function does not exist" << endl;
		}

		if (rules->ifExistsInText("asa", rules->functionNames(fManager2->getTempText()))) {
			cout << rules->functionBody("asa", fManager2->getTempText()) << endl;
		}
		else
		{
			cout << "Function does not exist" << endl;
		}

	}
	return 0;

}