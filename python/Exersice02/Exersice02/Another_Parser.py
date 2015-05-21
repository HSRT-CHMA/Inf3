class Another_Parser(object):
    """description of class"""

    '''
    This public Method parses a given string. In order to do so, it checks if the given input is valid, 
    and prints out Error-Messages. If input is valid, is gets the _s-Variable, on which all further 
    Methods will operate, started with parseEquation()
    param: input: The string that should be parsed.
    '''
    def parse(self, input):
        self._s = input
        # input becomes _s, a string-variable on which further methods operate
        if len(self._s) == 0:
            print("Error: The length of given input-string is zero.")
        elif self._s.endswith("+") or self._s.endswith("*") or self._s.endswith("=") or self._s.startswith("+") or self._s.startswith("*") or self._s.startswith("="):
            print("Error: The given input-string begins or ends with an invalid element.")
        elif not (self._s.count("(") == self._s.count(")")):
            print("Error: The amount of '(' or ')' in the given input-string is not equal.")
        elif self._s.count("(") > 0 and not self._bracketsInRigthOrder():
            print("Error: The brackets in the given input-string are in the wrong order.")
        elif self._emptyBrackets():
            print("Error: The given input-string contains a pair of empty brackets.")
        elif self._noDigitBeforeOrAfterOperator():
            print("Error: The given input-string contains an operator without corresponding digit.")
        elif self._noDigitBeforeBracketOrNoOperatorAfterBracket():
            print("Error: The given input-string contains an operator directly before or after a bracket.")
        elif not self._illegalCharacter() : 
            print("Error: The given input-string contains an invalid element.")
        elif self._leadingZero():
            print("Error: The given input-string contains a number which starts with a zero.")
        elif self._s.count("=") > 1:
            print("Error: The given input-string contains multiple '='.")
        else:
            # Only if the input is valid, parseEquation will be called
            print("Result : " + str(self._parseEquation()) + "\n______________________________________")
        
    
    '''
    This Method checks if an equation is valid : it only contains 2 valid expressions or 
    a valid single expression, linked by '='.
    The method returns the value of a valid expression or if 2 Expressions are equal
    (returns Treu if equal, False if not equal)
    param : _s : String-variable which contains the given input 
    '''
    def _parseEquation(self):
        if self._s.count("=") == 0:
            # if s contains no '=' , its a single expression which has to be checked 
            res = self._parseExpression()
        elif self._s.count("=") > 0:
            # if s contains min. one '=' , it contains 2 Expressions
            left = self._parseExpression()
            self._s = self._s[1:]
            # new s becomes substring of the old s (first char is 'cut')
            right = self._parseExpression()
            res = int(left) == int(right)
            # Value of left,first expression and value of right,second expression are checked for equality
        return res
        
    '''
    This Method checks if an expression is valid : it only contains valid multiple terms or 
    a valid single term, linked by Addition.
    The method returns the value of a valid term or multiple terms 
    param : _s : String-variable which contains the given input 
    '''
    def _parseExpression(self):
        res = ""
        # Used to show the outcome of this method
        if self._s.count("+") == 0:
             # if s contains no '+' , its a single term which has to be checked 
            res = self._parseTerm()
        elif self._s.count("+") > 0:
            # if s contains multiple '+' , it contains multiple terms
            res = int(self._parseTerm())
            while len(self._s) > 0 and self._s[0] == "+":
                # Cuts until there are chars left and the first char is a '+'
                self._s = self._s[1:]
                # new s becomes substring of the old s (first char is 'cut')
                res += int(self._parseTerm())
                # res becomes the value of all terms added
        return res
        
    '''
    This Method checks if a term is valid : it only contains valid multiple factors or 
    a valid single factor, linked by Multiplication. 
    The method returns the value of a valid factor or multiple factors
    param : _s : String-variable which contains the given input 
    '''
    def _parseTerm(self):
        res = ""
        # Used to show the outcome of this method
        if self._s.count("*") == 0:
            # if s contains no '*' , its a single factor which has to be checked 
            res = self._parseFactor()
        elif self._s.count("*") > 0:
            # if s contains multiple '*' , it contains multiple factors
            res = int(self._parseFactor())
            while len(self._s) > 0 and self._s[0] == "*":
                # Cuts until there are chars left and the first char is a '*'
                self._s = self._s[1:]
                # new s becomes substring of old s (first char is 'cut')
                res *= int(self._parseFactor())
                # res becomes the value of all factors multiplied
        return res
        
    '''
    This Method checks if a factor is valid : it only contains a valid constant or 
    a valid Expression inside '(' and ')'. Method returns the value of the constant by using parseConstant() 
    or the value of the Expression by using parseExpression(). 
    The method returns the value of a valid factor or multiple factors
    param : _s : String-variable which contains the given input 
    '''
    def _parseFactor(self):
        res = ""
        # Used to show the outcome of this method
        if self._s[0] != "(":
            res = self._parseConstant()
            # if factor does not start with an open bracket; its a Constant which has to be checked
        elif self._s[0] == "(":
            self._s = self._s[1:]
             # new s becomes substring of old s (first char is 'cut') 
            res = self._parseExpression()
            # if factor does start with an open bracket; it is cut out and remaining string gets checked
            if self._s[0] == ")":
                self._s = self._s[1:]
                 # if first char in s is a close-bracket, string after it becomes new s
        return res
        
    '''
    This Method checks if a constant is valid : it only contains Digits and does not start with a zero 
    Method returns the value of constant.
    param : _s : String-variable which contains the given input 
    '''
    def _parseConstant(self):
        res = ""
        # Used to show the outcome of this method
        if self._isDigitWOZero():
            while len(self._s) > 0 and self._isDigit():
                # Cuts until there are chars left and those are valid digits
                res += self._s[0]
                # res saves the first char
                self._s = self._s[1:]
                # new s becomes substring of old s (first char is 'cut') 
        return res
        
    '''
    This Method checks if first character in the string is a valid DigitWOZero (1-9) and returns a boolean.
    param : _s : String-variable which contains the given input 
    '''
    def _isDigitWOZero(self):
        # returns True if string is a digit but no zero
        return str(self._s[0]).isdigit() and (not '0' in self._s[0])
        
    '''
    This Method checks if current input is a valid Digit (0-9)  and returns a boolean value
    param : _s : String-variable which contains the given input 
    '''
    def _isDigit(self):
        # Returns True if char is in range(0,9)
        return str(self._s[0]).isdigit()
    
    '''
    Checks if the brackets are in the right order.
    In order to do so, method checks if there are more brackets closed than opened.
    Returns True if problem in string does not occur
    '''
    def _bracketsInRigthOrder(self):
        brackets = 0
        # Used to show the outcome of this method
        for char in self._s:
            # For each char in String s do check on brackets
            if brackets >= 0:
                if char == "(":
                    brackets += 1
                if char == ")":
                    brackets -= 1
        return brackets >= 0
        
    '''
    Checks if there are brackets without content between them.
    Returns True if problem in string does not occur
    '''
    def _emptyBrackets(self):
        res = False
        # Used to show the outcome of this method
        for i in range(len(self._s)):
            if self._s[i] != None and str(self._s[i]) == "(" and str(self._s[i + 1]) == ")":
                res = True
        return res
    
    '''
    Checks if there is a digit or brackets before and after + and *.
    Returns True if problem in string does not occur
    '''
    def _noDigitBeforeOrAfterOperator(self):
        res = False
        # Used to show the outcome of this method
        for i in range(len(self._s) - 1):
            if i > 0 and ((str(self._s[i]) == "+" or str(self._s[i]) == "*") and (not (str(self._s[i + 1]) == "(" or str(self._s[i + 1]).isdigit()) or not (str(self._s[i - 1]) == ")" or str(self._s[i - 1]).isdigit()))):
                res = True
        return res
    
    '''
    Checks if there is a digit directly before or after ( and ).
    Returns True if problem in string does not occur
    '''
    def _noDigitBeforeBracketOrNoOperatorAfterBracket(self):
        res = False
        # Used to show the outcome of this method
        for i in range(len(self._s) - 1):
            if i > 0 and ((str(self._s[i]) == "(" and str(self._s[i - 1]).isdigit()) or (str(self._s[i]) == ")" and str(self._s[i + 1]).isdigit())):
                res = True
        return res
    
    '''
    Checks if the given characters are valid and just contains digits or operators .
    Returns True if problem in string does not occur
    '''
    def _illegalCharacter(self):
        res = False
        # Used to show the outcome of this method
        for char in self._s:
            if not (str(char).isdigit() or char == "(" or char == ")" or char == "+" or char == "*" or char == "="):
                res = True
        return res
    
    '''
    Checks if there are numbers which starts with a leading zero. These are invalid because all constants must not start with a zero.
    Returns True if problem in string does not occur
    '''
    def _leadingZero(self):
        res = False
        # Used to show the outcome of this method
        for i in range(len(self._s)):
            if i > 0 and (str(self._s[i]).isdigit() and int(self._s[i]) == 0 and not str(self._s[i - 1]).isdigit()):
                res = True
        return res