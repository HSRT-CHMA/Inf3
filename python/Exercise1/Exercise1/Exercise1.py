''' 
Created on 15.03.2015 
 
@author: Marco
''' 
 
import sys 
from copy import deepcopy 

 
class Excersice1: 
    ''' two underscores = private Attribute ''' 
     
     
    def modify(self, arguments): 
        result = deepcopy(arguments) 
        for i in range(1, len(arguments)): 
            word = arguments[i] 
            asci = 0 
            x = 0 
            while(x <= len(word)): 
                letter = word[x] 
                print(letter) 
                 
                if ((letter.__eq__("0")) or (letter.__eq__("1")) or (letter.__eq__("2"))  
                or (letter.__eq__("3")) or (letter.__eq__("4")) or (letter.__eq__("5"))  
                or (letter.__eq__("6")) or (letter.__eq__("7")) or (letter.__eq__("8"))  
                or (letter.__eq__("9")) or (letter.__eq__("."))) : 
                    a = ord(letter) 
                    asci += a 
                    arguments[i] = chr(asci) 
                    result[i] = float(arguments[i]) 
                    x += 1 
                    print("Test") 
 
        return result 
     
     
    def modify2(self, arguments): 
        result = deepcopy(arguments) 
        print(arguments) 
        for i in range(1, len(arguments)): 
            word = result[i] 
            asciiV = 0 
            letterAsciiValue = 0
            print(word) 
            for i in range(0, len(word)): 
                letter = word[i] 
                print(letter) 
                if(letter.isalpha()): 
                    letterAsciiValue = ord(letter) 
                    print(letterAsciiValue)  
                asciiV = asciiV + letterAsciiValue 
                result[i] = ascii(asciiV) 

        '''result[i] = float(arguments[i])'''
        print (result)
        return result
     
 
    def get_average(self, numbers): 
        s = self.get_sum(self, numbers) 
        count= len(numbers) 
        average = s / count 
        return average 
     
     
    def get_sum(self,numbers): 
        result = 0 
        for i in range(len(numbers)) : 
            result += numbers[i] 
        return result 
     
    def get_reverse_List(self, numbers): 
        reverse = deepcopy(numbers) 
         
        for i in range(len(numbers),1 , -1): 
            j = 0 
            print(i) 
            reverse[j] = numbers[i] 
            j -= 1 
            print(j) 
        return reverse 
     
     
    def get_sorted_List(self, numbers): 
        tmp = 0; 
        size = len(numbers) 
        sortedList = deepcopy(numbers) 
        for i in range(size): 
            tmp = numbers[i] 
            numbers[i] = numbers[i + 1] 
            numbers[i + 1] = tmp 
        return sortedList 
     
     
    def get_palindrome(self, numbers): 
        return numbers + self.get_reverse_List(numbers)
     
    '''Main-Methode''' 
    if __name__ == "__main__": 
        original = modify2(sys.argv, sys.argv) 
                 
     
        '''print(get_reverse_List(original))''' 
 
    
    '''
    print(original) 
    print(get_summe(original, original)) 
    print(get_average(original, original)) 
    print(get_reverse_List(original, original)) 
    ''' 