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
int _tmain(int argc, _TCHAR *argv[])
{
	/*Creating new Parser Object*/
	Parser* p = new Parser();

	/*Output for User Interface*/
	cout << "\nExercise 02";
	cout << "\nExpression: 5+5" + p->parse("5+5");
	cout << "\nExpression: 5+5" + p->parse("(5+5");
	cout << "\nExpression: 5+5" + p->parse("5+5)");
	
	system("pause");
	return 0;
}