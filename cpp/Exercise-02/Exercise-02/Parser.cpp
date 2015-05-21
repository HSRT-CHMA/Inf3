/*Includes of the CPP Program*/
#include "Parser.h"
#include "stdafx.h"

/*Default Namespace of Parser*/
using namespace std;

/*
	Default Constructor of Parser
	Sets the different regex Defintions
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
	Start Value for bool return - false intialized
	Return Value isDigit - true if Regex match true
*/
bool Parser::isDigit(string input)
{
	bool value = false;
	
	if (regex_match(input, numbers)){
		value = true;
	}

	return value;
}

/*
	Method which checks the string with
	the regex match Method for Digits without Zero
	Start Value for bool return - false initializied
	Regex Match true if Digit without Zero
	Return Value of isDigitWithoutZero - true if Regex match true
*/
bool Parser::isDigitWithoutZero(string input)
{
	bool value = false;
	
	if (regex_match(input, numbersWZ)){
		value = true;
	}

	return value;
}

/*
	Method which checks the string with
	the regex match Method for only Zero Value		
	Start Value for bool return - false initializied
	Regex Match true if Zero
	Return Value of isZero - true if Regex match true
*/
bool Parser::isZero(string input)
{
	bool value = false;

	if (regex_match(input, onlyZero)){
		value = true;
	}

	return value;
}

/*
	Method which checks the string if
	there are not valid Characters
	Start Value for bool return - false initializied
	Return Value of invalidCharacters - true if there is an invalid character in string input
*/
bool Parser::invalidCharacters(string input)
{
	bool value = false;

	if (!regex_match(input, onlyZero) || !regex_match(input, numbers) || !regex_match(input, numbersWZ)){
		value = true;
	}
	for (int i = 0; i < input.length; i++){
		if (input[i] != '(' && input[i] != ')' && input[i] != '+' && input[i] != '*'){
			value = true;
		}
	}

	return value;
}

/*Start of Check Methods for Brackets and stuff like that*/

/*
	Method for Shape of the EBNF
	True if there is the valid count 
	of the Brackets on both sides
	Check if there is same count of both Brackets
	Return true if there is the same Count
*/
bool Parser::checkBracketCount(string input)
{
	int leftBracket = 0;
	int rightBracket = 0;

	for (int i = 0; i < input.length; i++){
		if (input[i] == '('){
			leftBracket++;
		}
		if (input[i] == ')'){
			rightBracket++;
		}
	}
	return leftBracket == rightBracket;
}

/*
	Method for Shape of the EBNF
	True if there is the valid order
	of the Brackets.
	Copy Index to rightBracket and leftBracket
	Return true if index from leftBracket is smaller 
	than the index rightBracket
*/
bool Parser::checkBracketOrder(string input)
{
	int rightBracket = 0;
	int leftBracket = 0;

	for (int i = 0; i < input.length; i++){
		if (input[i] == '('){
			leftBracket = i;
		}
		if (input[i] == ')'){
			rightBracket = i;
		}
	}

	return leftBracket < rightBracket;
}

/*
	Methodfor Shape of the EBNF
	Same thing as checkBracketOrder
	Check if there is Space for Values
	between the Brackets
	Return Type True if Index of Brackets is 
	not side by side
*/
bool Parser::checkEmptyBrackets(string input)
{
	int rightBracket = 0;
	int leftBracket = 0;

	for (int i = 0; i < input.length; i++){
		if (input[i] == '('){
			leftBracket = i;
		}
		if (input[i] == ')'){
			rightBracket = i;
		}
	}

	return leftBracket != rightBracket-1;
}

bool Parser::checkNumbers(string input)
{

}

/*
	Method for Shape of the EBNF
	True if there are numbers and 
	an Operator in the string
	Return true if there is an Operator and Numbers
*/
bool Parser::checkOperator(string input)
{
	bool value = false;

	if (regex_match(input, numbers)){
		for (int i = 0; i < input.length; i++){
			if (input[i] != '+' || input[i] !='*'){
				value = true;
			}
		}
	}

	return value;
}


string Parser::parseEquation(string input)
{
	int valueLeft = 0;
	int valueRight = 0;
	string value = "";
	string left = "";
	string right = "";
	bool checkEquation = false;

	for (int i = 0; i < input.length; i++){
		if (input[i] == '='){
			checkEquation = true;
		}
	}
	if (checkEquation){

	}

	return value;
}

string Parser::parseExpression(string input)
{
	bool checkPlus = false;
	bool checkBracketLeft = false;
	bool checkBracketRight = false;
	string result = "";
	string left = "";
	string right = "";

	for (int i = 0; i < input.length; i++){
		if (input[i] != '('){
			checkBracketLeft = true;
		}
		if (input[i] != ')'){
			checkBracketRight = true;
		}
		if (input[i] == '+'){
			checkPlus = true;
		}
	}

	if (checkPlus && checkBracketLeft && checkBracketRight){

	}
}

/*
	Method to parse the Constant Value
	Start Value for return - clear initialized
	Check if there is a digit in input
	Return Value - Clear if nothing was changed
*/
string Parser::parseConstant(string input)
{
	string value = "";

	if (isDigit(input)){
		value = input;
	}

	return value;
}

/*
	Method to parse an EBNF
	Only Method which is public accessable
	for the User.
	Return Value for the Method Parse
*/
string Parser::parse(string input)
{
	string value= "";

	/*Start Complete Check if the Input Value is valid*/
	if (!invalidCharacters(input)){
		if (checkBracketCount(input)){
			if (checkEmptyBrackets(input)){
				if (checkNumbers(input)){
					if (checkOperator(input)){

					}
				}
				else{
					cout << "Sorry the numbers of the term are not valid.";
				}
			}
			else{
				cout << "Sorry there is no content between the brackets.";
			}
		}
		else{
			cout << "Sorry the brackets are not valid in this term.";
		}
	}
	else{
		cout << "Sorry there are invalid Characters in your Input String.";
	}

	//TODO
	return value;
}
