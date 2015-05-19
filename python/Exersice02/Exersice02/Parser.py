import Expression
import Constant

class Parser(object):
    """description of class"""

    def __init__(self):
        #params might be added
        '''
        Constructor
        ''' 
        my_expression = Expression.Expression()

    # Add some more general methods to check the incomming string 
    #e.g. BracketProblem; ExpressionStarts/EndsWithAnOperator; MoreThan1=Problem; and so on
    

    def parse(self, line_input):
        # None is equivalent to Void or Null
        assert line_input != None
        # Precondition line_input is a String
        assert type(line_input) == str 
        print(line_input)
        final_output = ""


        final_output = self.parseEquation(line_input) # Check the given input
        if final_output == None :
            print("The current Equation is NOT VALID ")
        else :
            print("The current Equation is VALID ")
            if final_output.isdecimal :
                print("The current Expression has the value of " + str(final_output))
            elif 'true' in final_output.lower :
                print("The elements of the current Equation are equal :-) ")
            elif 'false' in final_output.lower :
                print("The elements of the current Equation are not equal :-(")

   
    ''' Method checks if the given string is a valid Equation (An Expression ; optional followed by "=" , and one more Expression )
        Method returns None if Equation is in any form invalid, or True/False or int-Value of Expression '''
    def parseEquation(self, line_input):
         # None is equivalent to Void or Null
        assert line_input != None
        # Precondition line_input is a String
        assert type(line_input) == str 
        print(line_input)
        result_eq = ""
        # A String to show the outcome of this Method ( can be None if invalid, 
        # True/False as a value for Equality of the Equation or a int-Value of the Expression )
        left = 0
        right = 0
        # Int-Variables to be used as results

        if '=' in line_input : # Is input an Equation or an Expression ?
            print("Its an Equation !")
            equation_elements = line_input.split('+') 
            #Split the string at the '=' - Operator
            left = equation_elements[0]
            # The first, left part of the Equation 
            right = equation_elements[1]
            # The second, right part of the Equation
            result_left = self.parseExpression(left)
            result_right = self.parseExpression(right)

            if result_left != None and result_right != None : # Both parts of the Equation are valid
                if int(result_left) == int(result_right) : # Both parts of the equation are of the same value
                    result_eq = True 
                else :
                    result_eq = False
            else :
                result_eq = None
                

        else : # A single Expression ; returns 
            result = self.parseExpression(line_input)
            if result != None :
                # Why here ERROR ?

                result_eq += int(result)
                print("Its a int-Value !")
            else :
                result_eq = None

        return result_eq
    
    
    ''' Method checks if the given string is a valid Expression (A single Term | Term + Term + ....+ Term )'''    
    def parseExpression(self, line_input):
         # None is equivalent to Void or Null
        assert line_input != None
        # Precondition line_input is a String
        assert type(line_input) == str 
        #result = None or result = valueOfTheExpression
        result_string = ""
        #String to show the outcome of this Method
        bol = True 
        ## boolean-variable to interpret the result; must be set true at the beginning
        numeric_result = 0
        # Int-value to show the result of the addition of all Terms in the given Expression
        # It is 0 because that is the neutral element in Addition

        if '+' in line_input : # Expression contains of multiple Terms
            all_term = line_input.split('+') 
            #Split the string at the + - Operator
            for i in range(0, len(all_term)) :
                print("Its not a single Term !!")
                if self.parseTerm(all_term[i]) != None :
                # if the seperated Term is valid; True and Treu = True 
                    bol = bol and True
                    # int(a) returns the corresponding int-value of string a
                    numeric_result = numeric_result + int(self.parseFactor(all_term[i]))
                else :
                    # if the seperated Term is not valid ; True and False = False and stays False !
                    bol = bol and False

            if bol : # Valid Term
                result_string = numeric_result
                print("The numeric value of line_input " + line_input + " is " + str(numeric_result))
            else :
                result_string = None

        else :
            print("Its a single Term :")
            result_string = self.parseTerm(line_input)
            # If Term is invalid ; result_string becomes None; 
            # else it becomes the value of the single Factor; or combined value of all Factors

        return result_string

    
        
        
    ''' Method checks if the given string is a valid Term (A single factor | a factor * factor ' ... * factor)'''
    def parseTerm(self, line_input):
         # None is equivalent to Void or Null
        assert line_input != None
        # Precondition line_input is a String
        assert type(line_input) == str 
        #result_t = None
        #Term-Object to show the outcome of this Method
        result_string = ""
        #String to show the outcome of this Method
        bol = True 
        ## boolean-variable to interpret the result; must be set true at the beginning
        numeric_result = 1
        # Int-value to show the result of the multiplication of all factors in the given term
        # It is 1 because that is the neutral element in Multiplication
        
        if '*' in line_input : # Term contains multiple Factors
            all_term = line_input.split('*') 
            #Split the string at the * - Operator
            for i in range(0, len(all_term)) :
                print("Its not a single Factor !!")
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
                print("The numeric value of line_input " + line_input + " is " + str(numeric_result))
            else :
                result_string = None

        else : # Term contains a single Factor, which has to be checked 
            print("Its a single Factor :")
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
            result_string = self.parseExpression(line_input)
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
        # String to show the outcome of 
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
                
        if bol : # If line_input is a valid Constant
            # From valid string, a Constant-Object is created
            #valid_constant = Constant.Constant(line_input)
            #result_c = valid_constant
            result_string = line_input
        else :
            result_string = None

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





