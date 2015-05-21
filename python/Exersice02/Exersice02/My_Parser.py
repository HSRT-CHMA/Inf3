class My_Parser(object):
    """description of class"""

    def __init__(self):
        #params might be added
        '''
        Constructor
        '''
    
    def parse(self,line_input):
        print (self.parseEquation(self, line_input))

    
    def parseEquation(self, line_input) : # (Expression) ; (Expression) = (Expression)
        print("input : " + str(line_input))
        left = ""
        right = ""
        result_left = ""
        result_right = ""
        result_eq = ""

        if line_input.count('=') == 0 :
            result_eq = self.parseExpression(line_input)
        elif line_input.count('=') == 1 :
            equation_elements = line_input.split('=') 
            left = equation_elements[0]
            # The first, left part of the Equation 
            right = equation_elements[1]
            # The second, right part of the Equation
            result_left = self.parseExpression(left)
            # String-output of first, left Expression
            result_right = self.parseExpression(right)
            # String-output of second, right Expression

            if result_left != None and result_right != None : # Both parts of the Equation are valid
                result_eq = int(result_left) == int(result_right)
            else :
                result_eq = None
        else :
            print("ERROR Line 40 ")
            result_eq = None

        return result_eq
   
    def parseExpression(self, line_input) :
        result_ex = ""
        left = ""
        right = ""
        neutral_element = 0 
        # Neutral element of addition
        tmp = 0
        
        if '+' in line_input and not '(' in line_input and not ')' in line_input :
            left = line_input[0:line_input.find('+')]
            # Substring of line_input; from first index to the one before first occurrence of '+'
            neutral_element = neutral_element + int(self.parseExpression(left))

            #Substring of line_input; from after the first index of '+' to the end of the string
            right = line_input[line_input.find('+')+1:len(line_input)]
            #print("Test : " + str(right))
            
            # If part behind first '+' contains more '+' --> Recursion
            if '+' in right :
                result_ex = self.parseExpression(right)
            else : # If the last single Term is reached and its valid; the result gets calculated
                if self.parseTerm(right) != None :
                    tmp = int(neutral_element)+int(self.parseTerm(right))
                    result_ex = str(tmp)
                else :
                    result_ex = None

        else :
            result_ex = self.parseTerm(line_input)

        return result_ex


    ''' Method checks if the given string is a valid Term (A single factor | a factor * factor ' ... * factor)'''
    def parseTerm(self, line_input):
        # None is equivalent to Void or Null
        assert line_input != None
        # Precondition line_input is a String
        assert type(line_input) == str 
        #result_t = None
        #Term-Object to show the outcome of this Method
        result_string = ""
        #String to show the outcome of this Method; can be None if Factor(s) are invalid or the value of a single Factor, 
        # or the combined values of all Factors in a Term
        bol = True 
        ## boolean-variable to interpret the result; must be set true at the beginning
        numeric_result = 1
        # Int-value to show the result of the multiplication of all factors in the given term
        # It is 1 because that is the neutral element in Multiplication
        
        if '*' in line_input : # Term contains multiple Factors
            #print("Multiple Factors")
            all_term = line_input.split('*') 
            #Split the string at the * - Operator
            for i in range(0, len(all_term)) :
                if self.parseFactor(all_term[i]) != None :
                # if the seperated factor is valid; True and Treu = True 
                    bol = bol and True
                    # int(a) returns the corresponding int-value of string a
                    numeric_result = numeric_result * int(self.parseFactor(all_term[i]))
                else :
                    # if the seperated factor is not valid ; True and False = False and stays False !
                    bol = bol and False
        
            if bol : # Valid Factor
                result_string = numeric_result
                #print("The numeric value of line_input " + line_input + " is " + str(numeric_result))
            else :
                result_string = None

        else : # Term contains a single Factor, which has to be checked 
            #print("Single factor")
            result_string = self.parseFactor(line_input)
            # If Factor is invalid ; result_string becomes None; 
            # else it becomes the value of the single Factor
        return result_string 
        

    ''' Method checks if input is a valid Factor (A Constant or an Expression)
    parms line_input: The given string to be checked '''
    def parseFactor(self, line_input):
        # None is equivalent to Void or Null
        assert line_input != None
        # Precondition line_input is a String
        assert type(line_input) == str 
        #result_f = None
        # To be used as the result-Object to show the outcome of the parse-Method
        result_string = ""
        # To be used to show the outcome of this method
        if '(' in line_input and ')' in line_input:
            no_brackets = ""
            no_brackets = line_input[1:len(line_input)-1]
            result_string = self.parseExpression(no_brackets)
            #  Result of parse Expression can be None (if invalid) or containing the value of the valid Expression

        else : # String contains a Constant which has to be checked
               # Result of parseConstant can be None, or a string containing the value of the Constant
            result_string = self.parseConstant(line_input)
            
        return result_string 
        # Result_string can be None or a string containing the value of the Constant; 
        # or a string containing the value of the Expression in the Factor


    ''' Method checks if input is a valid Constant (e.g. 1, 50, 908 etc)  
    or if it is not valid like : 0, 099, etc
    parms line_input: The given string to be checked'''
    def parseConstant(self, line_input):
        # None is equivalent to Void or Null
        assert line_input != None
        # Precondition line_input is a String
        assert type(line_input) == str 
        bol = True
        # boolean-variable to interpret the result; must be set true at the beginning
        #result_c = None
        # To be used as the result-Object to show the outcome of this parse-Method
        result_string = ""
        # String to show the outcome of this Method
        first_valid = self.isDigitWOZero(line_input[0])
        # The first number is checked seperatly; must not be a '0' 
        
        if len(line_input) == 1 :
            bol = first_valid
        else :
            if first_valid :
                for i in range(2, len(line_input)) :
                    bol = bol and self.isItDigit(line_input[i])
            else :
                bol = False
                
        if bol : 
            result_string = line_input # result is "value" of the constant if valid one
        else :
            result_string = None # result is None if constant is not valid 

        return result_string
    
    '''Method checks if input is a valid digit (0 - 9)
    parms line_input: The string to be checked'''
    def isItDigit(self, line_input):
        # None is equivalent to Void or Null
        assert line_input != None
        # Precondition line_input is a String
        assert type(line_input) == str 
        return line_input.isdigit()
        #str : isdigit() Return true if all characters in the string are digits (0-9)
        #and there is at least one character, false otherwise. 
    
    
    
    ''' This Method checks if input is a valid DigitWOZero (1-9) 
    parms line_input: The string to be checked'''    
    def isDigitWOZero(self, line_input):
        # None is equivalent to Void or Null
        assert line_input != None
        # Precondition line_input is a String
        assert type(line_input) == str 
        # line_input has to be a str, so isdigit() can be used
        bol = False 
        # boolean = bool in Python
        if line_input.isdigit() :
            if '0' in line_input :
                bol = False
            else : # No 0 in the string
                bol = True
        else : # No digit or empty string
            bol = False  
        
        return bol   
        #assert type(bol) == bool