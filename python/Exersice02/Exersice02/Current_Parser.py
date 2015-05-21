class Current_Parser(object):
    """description of class"""



    def _parse(self, string):
        self._s = string
        return self._parseEquation()

    
    def _parseEquation(self):
        if not '=' in self._s : #self._s.count("=") == 0:
            res = self._parseExpression()
        else : #self._s.count("=") > 0:
            left = self._parseExpression()
            self._s = self._s[1:]
            right = self._parseExpression()
            res = left == right
        return res
        
    '''
    Returns expression.
    '''
    def _parseExpression(self):
        if not '+' in self._s :
            res = self._parseTerm()
        else : #self._s.count("+") > 0:
            res = int(self._parseTerm())
            while len(self._s) > 0 and self._s[0] == "+":
                self._s = self._s[1:]
                res += int(self._parseTerm())
        return res
        
    '''
    Returns term.
    '''
    def _parseTerm(self):
        if not '*' in self._s :
            res = self._parseFactor()
        else : #self._s.count("*") > 0:
            res = int(self._parseFactor())
            while len(self._s) > 0 and self._s[0] == "*":
                self._s = self._s[1:]
                res *= int(self._parseFactor())
        return res
        
    '''
    Returns factor.
    '''
    def _parseFactor(self):
        if not "(" in self._s[0] :
            res = self._parseConstant()
        else : # if "(" in self._s[0] :
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
            while len(self._s) > 0 and self._isItDigit():
                res += self._s[0]
                self._s = self._s[1:]
        return res
        
    '''
    Checks if first character in the string is a digit without zero and returns a boolean.
    '''
    def _isDigitWOZero(self):
        bol = False
        # Used to show the outcome of this method
        bol = self._isItDigit() and (not '0' in self._s)
        # bol = True if string is a digit but no zero
        return str(bol) 
        
    '''
    This Method checks if current input is a valid Digit (1-9)  and returns a boolean value 
    '''
    def _isItDigit(self):
        # Returns True or False
        return str(self._s[0]).isdigit()