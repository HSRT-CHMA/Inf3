'''
Created on 18.06.2015

@author: Martin Watolla
'''
from Test import Test
from BinaryTree import BinaryTree

'''
float Tree
'''
trFloat = BinaryTree()
trFloat.insert(4.00)
testFloat = Test(trFloat)
testFloat.testFloat()
    
'''
string Tree
'''    
trString = BinaryTree()
testString = Test(trString)
testString.testString()