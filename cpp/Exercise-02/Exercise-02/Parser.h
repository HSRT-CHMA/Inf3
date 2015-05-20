#pragma once

/*Includes of Parser Class*/
#include <iostream>
#include <string>
#include "stdafx.h"

using namespace std;

/*Header File of Parser*/
class Parser
{
	/*Private Methods of Parser*/
private:
	
	/*Method for Equation*/
	string parseEquation(string input);
	
	/*Method for Expression*/
	string parseExpression(string input);
	
	/*Method for Term*/
	string parseTerm(string input);
	
	/*Method for Factor*/
	string parseFactor(string input);
	
	/*Method for Constant*/
	string parseConstant(string input);
	
	/*Method for isDigit*/
	bool isDigit(string input);
	
	/*Method for isDigitWithoutZero*/
	bool isDigitWithoutZero(string input);
	
	/*Public Methods of Parser*/
public:
	
	/*Default Constructor Prototype*/
	Parser();
	
	/*Default Destructior Prototype*/
	~Parser();
	
	/*Parse Method*/
	string parse(string input);
};

