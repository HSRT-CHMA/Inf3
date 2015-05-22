
/*Default Namespace of Parser*/
using namespace std;

/*Header File of Parser*/
class Parser
{
	/*Private Methods of Parser*/
private:

	/*Methods for Shape of EBNF*/
	
	/*
	Method for Shape of the EBNF
	True if there is the valid count
	of the Brackets on both sides
	Check if there is same count of both Brackets
	Return true if there is the same Count
	*/
	bool checkBracketCount(string input);
	
	/*
	Method for Shape of the EBNF
	True if there is the valid order
	of the Brackets.
	Copy Index to rightBracket and leftBracket
	Return true if index from leftBracket is smaller
	than the index rightBracket
	*/
	bool checkBracketOrder(string input);
	
	/*
	Methodfor Shape of the EBNF
	Same thing as checkBracketOrder
	Check if there is Space for Values
	between the Brackets
	Return Type True if Index of Brackets is
	not side by side
	*/
	bool checkEmptyBrackets(string input);
	
	/*
	Method for Shape of the EBNF
	True if there is the right Shape
	-> no Operators on the Left Side of
	the Bracket
	Return true if there is the right shape on the left side
	*/
	bool checkBracketShapeLeft(string input);
	
	/*
	Method for Shape of the EBNF
	True if there is the right Shape
	-> no Operators on the Right Side of
	the Bracket
	Return true if there is the right shape on the right side
	*/
	bool checkBracketShapeRight(string input);
	
	/*Method for special cases*/

	/*
	Methodfor Shape of the EBNF
	Check string for no numbers and if
	there are operators
	Return Type True if no numbers are
	in the expression but operators
	*/
	bool checkNumbers(string input);
	
	/*
	Method for Shape of the EBNF
	True if there are numbers and
	an Operator in the string
	Return true if there is an Operator and Numbers
	*/
	bool checkOperator(string input);


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
	
	/*
	Method which checks the string with
	the regex match Method for Digits with Zero
	Start Value for bool return - false intialized
	Return Value isDigit - true if Regex match true
	*/
	bool isDigit(string input);
	
	/*
	Method which checks the string with
	the regex match Method for Digits without Zero
	Start Value for bool return - false initializied
	Regex Match true if Digit without Zero
	Return Value of isDigitWithoutZero - true if Regex match true
	*/
	bool isDigitWithoutZero(string input);

	/*
	Method which checks the string with
	the regex match Method for only Zero Value
	Start Value for bool return - false initializied
	Regex Match true if Zero
	Return Value of isZero - true if Regex match true
	*/
	bool isZero(string input);

	/*
	Method which checks the string if
	there are not valid Characters
	Start Value for bool return - false initializied
	Return Value of invalidCharacters - true if there is an invalid character in string input
	*/
	bool invalidCharacters(string input);



	/*Public Methods of Parser*/
public:

	/*Default Constructor Prototype*/
	Parser();
	
	/*Default Destructior Prototype*/
	~Parser();
	
	/*Parse Method*/
	string parse(string input);
};