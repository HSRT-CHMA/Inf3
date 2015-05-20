#pragma once
/*Header File of Parser*/
class Parser
{
	
	/*Private Methods of Parser*/
private:
	parseEquation(EquationString input);
	parseExpression(EquationString input);
	parseTerm(EquationString input);
	parseFactor(EquationString input);
	parseConstant(EquationString input);
	isDigit(EquationString input);
	boolean isDigitWithoutZero(EquationString input);
	
	/*Public Methods of Parser*/
public:
	/*Default Constructor Prototype*/
	Parser();
	/*Default Destructior Prototype*/
	~Parser();
	/*Parse Method*/
	Expression< ? > parse(String input)
};

