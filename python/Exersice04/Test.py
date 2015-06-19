'''
Created on 18.06.2015

@author: Martin Watolla
'''


from BinaryTree import BinaryTree
from RandomValue import RandomValue

class Test(object):
    
    tr = BinaryTree()
    
    def __init__(self, tree):
        
        self.tr = tree
    
        
    '''
    Method for Testing the Float Tree with 
    - Creating a new Binary Tree
    - Adding Random Values to the Binary Tree
    '''
    def testFloat(self):
        
        #Defining Variables to work with
        randomV = RandomValue()
        newItems = range(10)

        #Pull random strings into the Tree
        for i in newItems:
            newFloat = randomV.rFloat()
            print("Binary Tree add: ", newFloat)
            self.tr.insert(newFloat)
        
        print("\nTree Values:")
        print(self.tr.treeArray(self.tr.getRoot()))
        print("_________________________________________________________________________________________________________________________")
      
        print("\nFloats\n")
        print("negative values")
        negVal = list(self.tr.filter(lambda val : val < 0, self.tr.getRoot()))
        print(negVal)
        print("_________________________________________________________________________________________________________________________")
        
        print("\nvalues <= 5")
        lesVal = list(self.tr.filter(lambda val : val <= 5, self.tr.getRoot()))
        print(lesVal)
        print("_________________________________________________________________________________________________________________________")
        
        print("\nvalues % 2")
        evenVal = list(self.tr.filter(lambda val : val % 2 == 0, self.tr.getRoot()))
        print(evenVal)
        print("_________________________________________________________________________________________________________________________")
        print("\n\n")


    '''
    Method for Testing the String Tree with 
    - Creating a new Tree
    - Adding Random Values to the Tree
    - Output from Tree Height
    - Deleting a Value 
    - Output from Tree Height
    
    '''
    def testString(self):
        
        #Defining Variables to work with
        randomV = RandomValue()
        newItems = range(10)

        #Pull random strings into the Tree
        for i in newItems:
            newString = randomV.rString()
            print("Tree add:", newString)
            self.tr.insert(newString)
            
        print("\nTree Values:")
        print(self.tr.treeArray(self.tr.getRoot()))
        print("_________________________________________________________________________________________________________________________")
      
        print("\nStrings\n")
        
        print("length >= 3")
        negVal = list(self.tr.filter(lambda val : len(val) >= 3, self.tr.getRoot()))
        print(negVal)
        print("_________________________________________________________________________________________________________________________")

        print("\ncontains 'S'")
        lesVal = list(self.tr.filter(lambda val : val.find("S") > -1, self.tr.getRoot()))
        print(lesVal)

    
    