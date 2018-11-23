// asa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "App.h"
#include "Rules.h"
#include "Exec.h"
#include "FileManager.h"
#include <iostream>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{
	App::info(argc, argv);
	Rules *rules = new Rules();
	Exec *execute = new Exec();

	string fileName = "C:\\Users\\conta\\Desktop\\file.txt";
	FileManager *fManager = new FileManager(fileName);
/*
	string fileName2 = "C:\\Users\\conta\\Desktop\\file2.txt";
	FileManager *fManager2 = new FileManager(fileName2);*/

	if (argc > 1) {
		fManager->read();
		//fManager2->read();
		// If argv[1] is a valid function name
		if (rules->ifExistsInText(argv[1], rules->functionNames(fManager->getTempText()))) {

			execute->commandLines(rules->functionBody(argv[1], fManager->getTempText()));
			cout << " - - - - - - - - - - - - - - - - - - - - - - - " << endl;
		}
		else
		{
			cout << "Function does not exist" << endl;
			cout << " - - - - - - - - - - - - - - - - - - - - - - - " << endl;
		}
		/*if (rules->ifExistsInText(argv[1], rules->functionNames(fManager2->getTempText()))) {
			cout << rules->functionBody(argv[1], fManager2->getTempText()) << endl;
			cout << " - - - - - - - - - - - - - - - - - - - - - - - " << endl;
		}
		else
		{
			cout << "Function does not exist" << endl;
			cout << " - - - - - - - - - - - - - - - - - - - - - - - " << endl;
		}*/

	}
	return 0;

}