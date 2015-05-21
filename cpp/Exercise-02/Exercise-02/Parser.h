
/*Default Namespace of Parser*/
using namespace std;

/*Header File of Parser*/
class Parser
{
	/*Private Methods of Parser*/
private:

	/*Methods for Shape of EBNF*/
	bool checkBracketCount(string input);
	bool checkBracketOrder(string input);
	bool checkEmptyBrackets(string input);
	bool checkNumbers(string input);
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
	
	/*Method for isDigit*/
	bool isDigit(string input);
	
	/*Method for isDigitWithoutZero*/
	bool isDigitWithoutZero(string input);

	/*Method for Zero Value*/
	bool isZero(string input);

	/*Method for not allowed Character*/
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