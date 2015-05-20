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
int _tmain(int argc, string *argv[])
{
	/*Creating new Parser Object*/
	Parser* p = new Parser();

	/*Output for User Interface*/
	cout << "Exercise 02";

	/*Check if Parameters are given from the console*/
	if (argv[0] != NULL){
		/*Check if String consists keyword file*/
		if (argv[0]->find("file")){

		}
		/*If not parse will be called*/
		else {
			p->parse(*argv[1]);
		}
	}
	/*
		End of programm
		Return Value for OS - not defined
	*/
	return 0;
}

