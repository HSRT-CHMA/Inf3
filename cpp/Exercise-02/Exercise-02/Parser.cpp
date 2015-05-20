#include "Parser.h"
#include "stdafx.h"

/*Default Namespace of Parser*/
using namespace std;

/*
	Default Constructor of Parser
*/
Parser::Parser()
{
	cout << "Definition of Regular Expression";
	cout << "Set only Zero to 0";
	onlyZero = "[0]";
	cout << "Set numbers to 0-9";
	numbers = "[0-9]";
	cout << "Set numbers without Zero to 1-9";
	numbersWZ = "[1-9]";
	cout << "New Parser was created!";
}

/*
	Default Destructor of Parser
*/
Parser::~Parser()
{
	cout << "Parser will be destroyed!";
}

/*
	Method which checks the string with
	the regex match Method for Digits with Zero
*/
bool Parser::isDigit(string input)
{
	/*Start Value for bool return - false intialized*/
	bool value = false;
	
	if (regex_match(input, numbers)){
		value = true;
	}

	/*Return Value isDigit - true if Regex match true*/
	return value;
}

/*
	Method which checks the string with
	the regex match Method for Digits without Zero
*/
bool Parser::isDigitWithoutZero(string input)
{
	/*Start Value for bool return - false initializied*/
	bool value = false;
	
	/*Regex Match true if Digit without Zero*/
	if (regex_match(input, numbersWZ)){
		value = true;
	}

	/*Return Value of isDigitWithoutZero - true if Regex match true*/
	return value;
}

/*
		Method which checks the string with
		the regex match Method for only Zero Value
*/
bool Parser::isZero(string input)
{
	/*Start Value for bool return - false initializied*/
	bool value = false;

	/*Regex Match true if Zero*/
	if (regex_match(input, onlyZero)){
		value = true;
	}

	/*Return Value of isZero - true if Regex match true*/
	return value;
}

/*
	Method which checks the string if
	there are not valid Characters
*/
bool Parser::invalidCharacters(string input)
{
	/*Start Value for bool return - false initializied*/
	bool value = false;
	char singleChar;

	/*Loop for whole String input Values*/
	for (int i = 0; i < input.length; i++){
		/*Copy to single Char*/
		singleChar = input[i];
		if (singleChar!='(' && singleChar!=')' && singleChar!='+' && singleChar!='*'){
			value = true;
		}
	}
	/*Return Value of invalidCharacters - true if there is an invalid character in string input*/
	return value;
}

string Parser::parseEquation(string input)
{
	return NULL;
}

string Parser::parseExpression(string input)
{
	return NULL;
}

string Parser::parseConstant(string input)
{
	/*Start Value for return - clear initialized*/
	string value = "";

	/*Check if there is a digit in input*/
	if (isDigit(input)){
		value = input;
	}

	/*Return Value - Clear if nothing was changed*/
	return value;
}

string Parser::parse(string input)
{
	return NULL;
}
