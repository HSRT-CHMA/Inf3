import Expression
import Constant

class Parser(object):
    """description of class"""

    def __init__(self):
        #params might be added
        '''
        Constructor
        ''' 
        print("New Parser")
        my_expression = Expression.Expression()

    def parse(self, line_input):
        print(line_input)
    
    def parseEquation(self, line_input):
        print(line_input)
    
    def parseExpression(self, line_input):
        print(line_input)
    
        
        
    ''' Is it a valid Term (A single factor, a factor * factor ' ... * factor)'''
    def parseTerm(self, line_input):
         # None is equivalent to Void or Null
        assert line_input != None
        # Precondition line_input is a String
        assert type(line_input) == str 
        result_t = None
        
        if '*' in line_input : # Term contains multiple Factors
            all_term = line_input.split('*')
            for i in range(0, len(all_term)) :
                self.parseFactor(all_term[i])
        else : # Term contains a single Factor, which has to be checked 
            result_t = self.parseFactor(line_input)
        
        
        return result_t
        
        
    
    ''' Method checks if input is a valid Factor (A Constant or an Expression)
    parms line_input: The given string to be checked '''
    def parseFactor(self, line_input):
        # None is equivalent to Void or Null
        assert line_input != None
        # Precondition line_input is a String
        assert type(line_input) == str 
        result_f = None
        # To be used as the result-Object to show the outcome of the parse-Method
        if '(' in line_input and ')' in line_input:
            result_f = self.parseExpression(line_input)

        else : # String contains a Constant which has to be checked
            result_f = self.parseConstant(line_input)
            
        return result_f
            
        
    ''' Method checks if input is a valid Constant (e.g. 1, 50, 908 etc)  
    or if it is not valid like : 0, 099, etc
    parms line_input: The given string to be checked'''
    def parseConstant(self, line_input):
        # None is equivalent to Void or Null
        assert line_input != None
        # Precondition line_input is a String
        assert type(line_input) == str 
        bol = True
        result_c = None
        # To be used as the result-Object to show the outcome of this parse-Method
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
            # From valid string, a Constant-Object is created
            valid_constant = Constant.Constant(line_input)
            result_c = valid_constant
        return result_c
        
        
    
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



