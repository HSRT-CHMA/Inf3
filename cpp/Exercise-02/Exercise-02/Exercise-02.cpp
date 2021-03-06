// Exercise-02.cpp : Defines Start Point for the Application
/*Includes of Exercise 2 - Main Method*/
#include "stdafx.h"

/*Default Namespace of Parser*/
using namespace std;

/*
	Initial Class for Exercise 02
	Creating Parser for E1
	Creating Interaction for E2
*/
int main(int argc, char* argv[])
{
	
	/*Exercise 01 - Parser*/
	/*Creating new Parser Object*/
	Parser* p = new Parser();


	/*Output for User Interface*/
	cout << "\nExercise 02";
	cout << "\nExpression: 5+5" + p->parse("5+5");

	/*Check if there are Arguments*/
	if (argc == 1){
		cout << "\nInfo: There are no additional Parameters given!\n";
	}
	else{
		if (argc > 3){
			cout << "\nThe Program is executed with to much Parameters.";
			cout << "\nValid Parameters:";
			cout << "\n1. Parameter: Only a Term which will be calculated, Example: (2+2+2)*4";
			cout << "\n2. Parameters: The First Parameter is 'File'. The Second Parameter is the path to the file.\n";
		}
		else{

			/*Check if there is not the file*/
			if (!strcmp(argv[1], "file")==0){
				cout << "\nParsing Parameter: ";
				cout << argv[1];
				cout << p->parse(argv[1]);
			}

			/*Parsing Parameters with a File*/
			else{

				/*Exercise 02 with external Parameters*/
				ifstream file(argv[2]);
				string lineParsing = "";

				cout << "\nReading from File";
				/*Walk trough file until End of File*/
				while (!file.eof()){
					cout << "\nGet Parameter...";
					/*Get each Line*/
					getline(file, lineParsing);
					cout << "\nParsing Paramter: ";
					cout << lineParsing;
					/*Parse each Line*/
					cout << p->parse(lineParsing);
				}

				/*Close File*/
				file.close();
			}
		}
	}
	
	/*Halt System to show Terminal Output*/
	system("pause");
	return 0;
}