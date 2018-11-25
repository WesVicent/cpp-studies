#include <iostream>
#include <string>

#include "pch.h"
#include "App.h"
#include "Rules.h"
#include "Exec.h"
#include "Obj.h"
#include "FileManager.h"

char  **g_argv;
int		g_argc;

using namespace std;

int main(int argc, char *argv[])
{
	g_argc = argc;
	g_argv = argv;

	Rules *rules = new Rules();
	Exec *execute = new Exec();

	/*argc = 3;
	std::string funcName("a");
	std::vector<char> charArrFuncName(funcName.begin(), funcName.end());
	charArrFuncName.push_back(0);

	std::string arg1("C:\\Users\\conta\\Desktop\\Projects\\cpp-studies");
	std::vector<char> charArrArgValor(arg1.begin(), arg1.end());
	charArrArgValor.push_back(0);

	g_argv[1] = &charArrFuncName[0];
	g_argv[2] = &charArrArgValor[0];*/

	// TODO: Let the user set the mainFile
	string fileName = "C:\\Users\\conta\\Desktop\\file.txt";
	FileManager *mainFile = new FileManager(fileName);
	
	if (argc > 1) {
		Obj::getInstance()->file.mainText = mainFile->read();
		rules->file.functionNames(Obj::getInstance()->file.mainText);
		
		if (App::ifExistsInText(g_argv[1], Obj::getInstance()->file.functionNames)) { // If function exists

			// Check if function has args, sets args and rawName
			rules->function.checkForArgs(g_argv[1], Obj::getInstance()->file.functionNames);
			// Match function body and set it
			rules->function.body(g_argv[1], Obj::getInstance()->file.mainText);

			execute->validateCall();
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

	App::info(argc, argv);

	return 0;

}