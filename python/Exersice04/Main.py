'''
Created on 18.06.2015

@author: Martin Watolla
'''

from AVLTree import AVLTree
from Tester import Tester
from BinaryTree import BinaryTree

'''
bt = AVLTree(5)    
bt.insert(6)
bt.insert(11)
bt.insert(12)
bt.insert(13)
    
print(bt.has(11))
'''
    
print("Integer Test:")
testTree = AVLTree(0)
test = Tester(testTree)
test.int_test(testTree)
testTree.output()
print("String Test:")
stringTree = BinaryTree("")
test.string_test(stringTree)
   
        
    
    

#if __name__ =='__main__':
    #res = main()
