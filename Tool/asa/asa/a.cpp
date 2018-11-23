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

	// TODO: Let the user set the mainFile
	string fileName = "C:\\Users\\conta\\Desktop\\file.txt";
	FileManager *fManager = new FileManager(fileName);

	string functionBody;

	if (argc > 1) {
		fManager->read();
		if (rules->ifExistsInText(argv[1], rules->functionName(fManager->getTempText()))) { // If function exists

			functionBody = rules->functionBody(argv[1], fManager->getTempText());
			if (rules->argCount > 0) {
				if (argc == rules->argCount + 2) {
					// TODO: Execute function with args
					cout << "Exec" << endl;

				}
				else if(argc < rules->argCount + 2)
				{
					cout << "MISSING ARG" << endl;
				}
				else if (argc > rules->argCount + 2)
				{
					cout << "MANY ARGs" << endl;
				}
			}
			else {
				execute->commandLines(functionBody);

			}
			cout << " - - - - - - - - - - - - - - - - - - - - - - - " << endl;
		}
		else
		{
			cout << "Function does not exist" << endl;
			cout << " - - - - - - - - - - - - - - - - - - - - - - - " << endl;
		}
	}
	else
	{
		App::highlightText("AUTO ", 11);
		App::highlightText("V-", 14);
		App::highlightText("Alpha\n", 14);
		App::highlightText("Developed by ", 14);
		App::highlightText("WesFerreira - https://github.com/WesFerreira \n", 112);

	}
	return 0;

}