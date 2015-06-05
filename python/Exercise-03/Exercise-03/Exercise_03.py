'''
    Tree Test Class
    Inf3 - Group 7
'''

#Defining Imports
from treeTest import treeTest

if __name__== "__main__":
    
    #Console Output for starting the Exercise
    print("Inf3 - Exercise 3")
    
    #Creating Tests with Trees
    exercise3 = treeTest()
    
    print("Creating Binary Tree Test")
    exercise3.testBinaryTree()

    print("Creating AVL Tree Test")
    #exercise3.testAVLTree()

    print("Creating Generic Tree Test")
    exercise3.testGenericTree()
    
    print('Test complete!')