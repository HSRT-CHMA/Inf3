'''
    Random Value Class
    Inf3 - Group 7
'''

#Defining Imports
from random import randrange
import random

'''
Class for creating random Values for testing our Trees
'''
class randomValue():
       
    '''
    Method for Creating a random String Value
    from the given >>Words<<
    ''' 
    def rString(self):
        stringItem = ["Christoph", "Marco", "sdsdfgf","dssdad", "96aefg", "mkn","Schorschi", "Sonderzeichen!!", "Homer","hereisapotato",
     "Watolla", "vsdsd3233", "1234Test", "P@55word","g12344", "gh5135sdft6", "123123","b44","13215ssda", "9gag"]
        return random.choice(stringItem)
    
    '''
    Method for Creating a Random Float Value
    in the Range of -50 to 50
    '''  
    def rFloat(self):
        return random.uniform(-50,50)

    '''
    Method for Creating a Random Integer Value
    in the Range of -50 to 50
    '''
    def rInteger(self):
        return randrange(-50, 50)