'''
    Tree Test Class
    Inf3 - Group 7
'''

#Defining Imports of the complete Project
from avlTree import avlTree
from binaryTree import binaryTree
from genericTree import genericTree
from randomValue import randomValue


'''
Class for Testing our Data Trees
'''
class treeTest(object):
    
    def __init___ (self):
        print('Starting with the Tests!')
        
        print('Creating Binary Tree Test')
        testBinaryTree()

        print('Creating AVL Tree Test')
        testAVLTree()

        print('Creating Generic Tree Test')
        testGenericTree()
    
        print('Test complete!')
    
        
    '''
    Method for Testing the Binary Tree with 
    - Creating a new Binary Tree
    - Adding Random Values to the Binary Tree
    - Output from Tree Height
    - Deleting a Value 
    - Output from Tree Height
    '''
    def testBinaryTree(self):
        
        #Defining Variables to work with
        randomV = randomValue()
        tree = binaryTree()
        newItems = range(10)

        #Pull random strings into the Tree
        for i in newItems:
            newString = randomV.rString()
            print("Binary Tree add: ", newString)
            tree.insert(newString)

        #Output the added Strings
        print("Output of the Values:")
        tree.preOrderOutput()
        print(newString, tree.has(newString))

        #Print Height of the Tree
        print("Height of the Tree: ", tree.height(tree.getRootNode()))

        #Delete the temporary Value out of the Tree
        print("Deleting temporary String: ", newString)
        tree.delete(newString)
        print("Deleting complete")

        #Print Height of the Tree
        print("Height of the Tree: ", tree.height(tree.getRootNode()))

    '''
    Method for Testing the AVL Tree with 
    - Creating a new AVL Tree
    - Adding Random Values to the AVL Tree
    - Output from Tree Height
    - Deleting a Value 
    - Output from Tree Height
    '''
    def testAVLTree(self):
        
        #Defining Variables to work with
        randomV = randomValue()
        tree = avlTree()
        newItems = range(10)

        #Pull random strings into the Tree
        for i in newItems:
            randomV = randomV.rInteger()
            print("AVL-Tree add:", randomV)
            tree.insert(randomV)
            print("Value was added")

        #Output from the Tree
        print("AVL-Tree Output: ", tree.preOrderOutput())
        #Check if Value is in the AVL Tree
        print("Is the Value: ", randomV, " in the AVL-Tree? ", tree.has(randomV))
        #Delete the Value out of the Tree
        tree.delete(randomV)
        print(randomV, " was deleted out of the Tree")
        #Check if the Value is in the Tree
        print(randomV, " is in the Tree: ", tree.has(randomV))
        #Print Height of the Tree
        print("Tree Height: ", tree.getHeight())
        #Output of the Tree
        print("Output of the Tree: ", tree.preOrderOutput())


    '''
    Method for Testing the Generic Tree with 
    - Creating a new Generic Tree
    - Adding Random Values to the Generic Tree
    - Output from Tree Height
    - Deleting a Value 
    - Output from Tree Height
    '''
    def testGenericTree(self):

        #Defining Variables to work with
        randomV = randomValue()
        tree = binaryTree()
        newItems = range(10)

        #Pull random integer Values into the Tree
        for i in newItems:
            randomV = randomV.rInteger()
            print("Generic-Tree add: ", randomV)
            tree.insert(randomV)
            print("Value was added!")

        #Output from the Tree
        print("Generic-Tree Output: ", tree.preOrderOutput)
        #Print the Height of the Tree
        print("Height of the Tree: ", tree.height(tree.getRootNode()))

        
        #Now adding some other Values to our Tree - Floats
        for i in newItems:
            randomV = randomV.rFloat()
            print("Generic-Tree add: ", randomValue)
            tree.insert(randomV)
            print("Value was added!")

        #Another Output from the Tree - now with additional Floats
        print("Generic-Tree Output: ", tree.preOrderOutput)

        #Delete last Float and check if its gone
        print("Deleteing: ", randomV)
        tree.delete(randomV)
        print("Last added Float is gone: ", tree.has(randomV))
        #Output of Tree Height
        print("Generic-Tree Height: ", tree.Height(tree.getRotNode()))
        
        #Now adding some other Values to our Tree - String
        for i in newItems:
            randomV = randomV.rString()
            print("Generic-Tree add: ", randomV)
            tree.insert(randomV)
            print("Value was added!")

        #Another Output from the Tree - now with additional Strings
        print("Generic-Tree Output: ", tree.preOrderOutput)
        
        #Delete last Float and check if its gone
        print("Deleting: ", randomV)
        tree.delete(randomV)
        print("Last added String is gone: ", tree.has(randomV))
        #Output of Tree Height
        print("Generic-Tree Height: ", tree.Height(tree.getRotNode()))
