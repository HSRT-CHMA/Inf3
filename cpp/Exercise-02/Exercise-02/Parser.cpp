/*Includes of the CPP Program*/
#include "Parser.h"
#include "stdafx.h"

/*Default Namespace of Parser*/
using namespace std;

/*Regular Expressions for Parser*/
regex onlyZero("[0]");
regex numbers("[0-9]");
regex numbersWZ("[1-9]");

/*Global Varliables*/
int g_Multiply = 1;
int g_Addition = 0;

/*
	Default Constructor of Parser
	Sets the different regex Defintions
*/
Parser::Parser()
{
	cout << "\nDefinition of Regular Expression";
	cout << "\nOnly Zero to 0";
	cout << "\nNumbers to 0-9";
	cout << "\nNumbers without Zero to 1-9";
	cout << "\nNew Parser was created!";
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

	if (!regex_match(input, onlyZero) && !regex_match(input, numbers) && !regex_match(input, numbersWZ) 
			&& !input.find('(') && !input.find(')') && !input.find('+') && !input.find('*')){
		value = true;
		cout << input.find('(');
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

	for (int i = 0; i < input.length(); i++){
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

	if (checkBracketCount(input)){
		for (int i = 0; i < input.length(); i++){
			if (input[i] == '('){
				leftBracket = i;
			}
			if (input[i] == ')'){
				rightBracket = i;
			}
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

	for (int i = 0; i < input.length(); i++){
		if (input[i] == '('){
			leftBracket = i;
		}
		if (input[i] == ')'){
			rightBracket = i;
		}
	}

	return leftBracket != rightBracket-1;
}

/*
	Methodfor Shape of the EBNF
	Check string for no numbers and if
	there are operators
	Return Type True if no numbers are
	in the expression but operators
*/
bool Parser::checkNumbers(string input)
{
	bool value = false;

	if (!regex_match(input, onlyZero) &&
		!regex_match(input, numbers) &&
		!regex_match(input, numbersWZ)){

		for (int i = 0; i < input.length(); i++){
			if (input[i] == '+' || input[i] == '*'){
				value = true;
			}
		}
	}

	return value;
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

	for (int i = 0; i < input.length(); i++){
		if (input[i] != '+' || input[i] !='*'){
			value = true;
		}
	}
	
	return value;
}

/*
	Method for Shape of the EBNF
	True if there is the right Shape
	-> no Operators on the Left Side of
	the Bracket
	Return true if there is the right shape on the left side
*/
bool Parser::checkBracketShapeLeft(string input)
{
	bool value = false;
	int bracketCtr = 0;
	string leftBracketSide = "";

	for each(char c in input){
		bracketCtr++;
		if (c == '('){
			leftBracketSide = input.substr(0, bracketCtr-1);
			if (!leftBracketSide.find_last_of("=") &&
				!leftBracketSide.find_last_of("*") &&
				!leftBracketSide.find_last_of("+") &&
				!leftBracketSide.find_last_of("(") &&
				!(input.find("(") == 0)){
				
				value = true;

			}
		}
	}

	return value;
}

/*
	Method for Shape of the EBNF
	True if there is the right Shape
	-> no Operators on the Right Side of 
	the Bracket
	Return true if there is the right shape on the right side
*/
bool Parser::checkBracketShapeRight(string input)
{
	bool value = false;
	int bracketCtr = 0;
	string rightBracketSide= "";

	for each(char c in input)
	{
		bracketCtr++;
		if (c == ')'){
			rightBracketSide = input.substr(0, bracketCtr);
			if (!(bracketCtr == input.length())){
				if (!rightBracketSide.find_last_of("=") && 
					!rightBracketSide.find_last_of("*") && 
					!rightBracketSide.find_last_of("+") && 
					!rightBracketSide.find_last_of("(") &&
					!rightBracketSide.find_last_of("")){
					
					value = true;
				}
			}
		}
	}

	return value;
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
	Method to parse the Term of the string

*/
string Parser::parseTerm(string input)
{
	string value = "";
	string left = "";
	string right = "";

	if (input.find("*") && !input.find("(") && !input.find(")")){
		
		/*
			Left Side Action
			Split String from the beginning to *
		*/
		left = input.substr(0, input.find("*"));
		g_Multiply *= stoi(parseExpression(left));

		/*
			Right Side Action
			Split String from * to the End of the String
		*/
		right = input.substr(input.find("*")+1, input.length()-(input.find("*")+1));
		
		if (right.find("*")){
			value = parseTerm(right);
		}
		else{
			value += (g_Multiply*stoi(parseTerm(right)));
		}
	}
	else{
		value = parseFactor(input);
	}
	
	return value;
}

/*
	Method to parse the Factor of the string

*/
string Parser::parseFactor(string input)
{
	///*Defition of Variables for Output*/
	string value = "";
	//string leftPart = "";
	//string middle = "";
	//string rightPart = "";

	//int bracketCnt = 0;
	//int indexOfLeftBracket = 0;
	//int indexOfRightBracket = 0;
	//
	///*Setting from global Variables*/
	//g_Addition = 0;
	//g_Multiply = 1;

	//for each(char c in input){

	//	if (c == '('){
	//		indexOfLeftBracket = bracketCnt;
	//	}
	//	bracketCnt++;
	//}
	//
	//bracketCnt = 0;

	//if (input.find('(')){
	//	leftPart = input.substr(0, indexOfLeftBracket);

	//	if (indexOfLeftBracket > input.find(')')){
	//		for each(char c in input){
	//			if (c == ')'){
	//				indexOfRightBracket = bracketCnt;
	//			}
	//			bracketCnt++;
	//		}
	//		bracketCnt = 0;
	//		rightPart = input.substr(indexOfRightBracket + 1, input.length() - (indexOfRightBracket + 1));
	//	}
	//	else{
	//		rightPart = input.substr(input.find(')') + 1, input.length() - (input.find(')') + 1));
	//	}

	//	middle = input.substr(indexOfLeftBracket, (input.length()) - indexOfLeftBracket);
	//	middle = middle.substr(middle.find("("), middle.find(")"));
	//	cout << middle.find('(');
	//	if (middle.find('(') || middle.find(')')){
	//		if (middle.find('(')){
	//			middle = middle.erase(input.find('('), input.find('('));
	//		}
	//		else{
	//			middle = middle.erase(input.find(')'), input.find(')'));
	//		}
	//		value = parseExpression(middle);
	//	}

	//	middle = leftPart + value + rightPart;
	//	value = parseExpression(middle);
	//}
	//else{
		value = parseConstant(input);
	//}
	return value;
}

/*
	Method for parsing Equation
	Check if there is a "=" in the string
	and splits from the "=" -> input.substr
	Method stoi to get the value of string to integer
	
*/
string Parser::parseEquation(string input)
{
	int valueLeft = 0;
	int valueRight = 0;
	string left = "";
	string right = "";
	string value = "";

	if (input.find("=")){
		
		/*Left Side Action*/
		left = input.substr(0, input.find('='));
		value = parseExpression(left);
	//	valueLeft =+ stoi(value);

		/*Right Side Action*/
		right = input.substr(input.find("=")+1, input.length()-(input.find("=")+1));
		value = parseExpression(right);
	//	valueRight += stoi(value);
	}
	else{
		value = parseExpression(input);
		valueLeft += stoi(value);
	}

	return value;
}

/*
	Method for parsing Expression
*/
string Parser::parseExpression(string input)
{
	string left = "";
	string right = "";
	string result = "";

	//Checks if String contains "+"
	if (input.find("+") && !input.find("(") && !input.find(")"))
	{
		//Splits string from the beginning until before "+"
		left = input.substr(0, input.find("+"));
		g_Addition += stoi(parseExpression(left));

		//Splits string after "+" until string end
		right = input.substr(input.find("+") + 1, input.length() - (input.find("+") + 1));
		if (right.find("+"))
		{
			result = parseExpression(right);
		}
		else
		{
			result += (g_Addition + stoi(parseTerm(right)));
		}
	}
	else
	{
		result = parseTerm(input);
	}
	return result;
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
						value = parseEquation(input);
					}
					else{
						cout << "\nSorry the Operator of the term is not valid.";
					}
				}
				else{
					cout << "\nSorry the numbers of the term are not valid.";
				}
			}
			else{
				cout << "\nSorry there is no content between the brackets.";
			}
		}
		else{
			cout << "\nSorry the brackets are not valid in this term.";
		}
	}
	else{
		cout << "\nSorry there are invalid Characters in your Input String.";
	}

	return value;
}