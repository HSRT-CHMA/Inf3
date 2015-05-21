class Another_Parser(object):
    """description of class"""

    '''
    Method to parse a given string.
    This method also checks if the given String can be parsed. This is necessary because the recursion would throw an exception
    if the string can't be parsed.
    If it can't be parsed a helpful error message will be printed.
    If it can be parsed the method parse_equation will be called with the given string as parameter and
    the result is calculated recursively.
    Parameters: string: The string that should be parsed.
    '''
    def parse(self, string):
        #string = str(string).replace(" ", "")
        self._s = string
        if len(self._s) == 0:
            print("Error: Nothing given to calculate.")
        elif self._s.endswith("+") or self._s.endswith("*") or self._s.endswith("=") or self._s.startswith("+") or self._s.startswith("*") or self._s.startswith("="):
            print("Error in " + self._s + " : Illegal character at the end or beginning")
        elif not (self._s.count("(") == self._s.count(")")):
            print("Error in " + self._s + " : Wrong amount of ( or ).")
        elif self._s.count("(") > 0 and not self._rightOrderOfBrackets():
            print("Error in " + self._s + " : The order of the brackets is wrong.")
        elif self._emptyBrackets():
            print("Error in " + self._s + " : Empty brackets.")
        elif self._noDigitBeforeOrAfterOperator():
            print("Error in " + self._s + " : No digit before or after operator.")
        elif self._noDigitBeforeBracketOrNoOperatorAfterBracket():
            print("Error in " + self._s + " : No operator before or after bracket.")
        elif not self._illegalCharacter() : # CAUTION
            print("Error in " + self._s + " : String contains a element which is no digit.")
        elif self._leadingZero():
            print("Error in " + self._s + " : Leading zero found.")
        elif self._s.count("=") > 1:
            print("Error in " + self._s + " : More than one =.")
        else:
            print("The result of " + self._s + " is: " + str(self._parseEquation()))
        
    '''
    Returns equation.
    '''
    def _parseEquation(self):
        if self._s.count("=") == 0:
            res = self._parseExpression()
        elif self._s.count("=") > 0:
            left = self._parseExpression()
            self._s = self._s[1:]
            right = self._parseExpression()
            res = int(left) == int(right)
        return res
        
    '''
    Returns expression.
    '''
    def _parseExpression(self):
        if self._s.count("+") == 0:
            res = self._parseTerm()
        elif self._s.count("+") > 0:
            res = int(self._parseTerm())
            while len(self._s) > 0 and self._s[0] == "+":
                self._s = self._s[1:]
                res += int(self._parseTerm())
        return res
        
    '''
    Returns term.
    '''
    def _parseTerm(self):
        if self._s.count("*") == 0:
            res = self._parseFactor()
        elif self._s.count("*") > 0:
            res = int(self._parseFactor())
            while len(self._s) > 0 and self._s[0] == "*":
                self._s = self._s[1:]
                res *= int(self._parseFactor())
        return res
        
    '''
    Returns factor.
    '''
    def _parseFactor(self):
        if self._s[0] != "(":
            res = self._parseConstant()
        elif self._s[0] == "(":
            self._s = self._s[1:]
            res = self._parseExpression()
            if self._s[0] == ")":
                self._s = self._s[1:]
        return res
        
    '''
    Returns constant.
    '''
    def _parseConstant(self):
        res = ""
        if self._isDigitWOZero():
            while len(self._s) > 0 and self._isDigit():
                res += self._s[0]
                self._s = self._s[1:]
        return res
        
    '''
    Checks if first character in the string is a digit without zero and returns a boolean.
    '''
    def _isDigitWOZero(self, line_input):
        # None is equivalent to Void or Null
        assert line_input != None
        # Precondition line_input is a String
        bol = False
        # Used to show the outcome of this method
        assert type(line_input) == str 
        bol = self._isDigit(line_input) and (not '0' in line_input)
        # bol = True if string line_input is a digit but no zero
        return bol
        
    '''
    Checks if the input string is a digit and returns a boolean.
    '''
    def _isDigit(self, line_input):
        # None is equivalent to Void or Null
        assert line_input != None
        # Precondition line_input is a String
        assert type(line_input) == str 
        return line_input.isdigit()
    
    '''
    Checks if the brackets are in the right order and returns a boolean.
    Therefor it checks if there are not more brackets closed than opened.
    '''
    def _rightOrderOfBrackets(self):
        brackets = 0
        for char in self._s:
            if brackets >= 0:
                if char == "(":
                    brackets += 1
                if char == ")":
                    brackets -= 1
        return brackets >= 0
        
    '''
    Checks if there are brackets without content.
    '''
    def _emptyBrackets(self):
        res = False
        for i in range(len(self._s)):
            if self._s[i] != None and str(self._s[i]) == "(" and str(self._s[i + 1]) == ")":
                res = True
        return res
    
    '''
    Checks if there is a digit or brackets before and after + and *.
    '''
    def _noDigitBeforeOrAfterOperator(self):
        res = False
        for i in range(len(self._s) - 1):
            if i > 0 and ((str(self._s[i]) == "+" or str(self._s[i]) == "*") and (not (str(self._s[i + 1]) == "(" or str(self._s[i + 1]).isdigit()) or not (str(self._s[i - 1]) == ")" or str(self._s[i - 1]).isdigit()))):
                res = True
        return res
    
    '''
    Checks if there is a digit before or after ( and ).
    '''
    def _noDigitBeforeBracketOrNoOperatorAfterBracket(self):
        res = False
        for i in range(len(self._s) - 1):
            if i > 0 and ((str(self._s[i]) == "(" and str(self._s[i - 1]).isdigit()) or (str(self._s[i]) == ")" and str(self._s[i + 1]).isdigit())):
                res = True
        return res
    
    '''
    Checks if there are numbers with a leading zero. These are invalid.
    '''
    def _leadingZero(self):
        res = False
        for i in range(len(self._s)):
            if i > 0 and (str(self._s[i]).isdigit() and int(self._s[i]) == 0 and not str(self._s[i - 1]).isdigit()):
                res = True
        return res

    '''
    Checks if the given characters are valid.
    '''
    def _illegalCharacter(self):
        res = False
        for char in self._s:
            if (str(char).isdigit() or char == "(" or char == ")" or char == "+" or char == "*" or char == "="): # not 
                res = True
        return res
    


