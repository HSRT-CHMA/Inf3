'''
    Tree Test Class
    Inf3 - Group 7
'''

#Defining Imports of the complete Project
import avlTree
import binaryTree
import genericTree
import randomValue


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
    def testBinaryTree():
        
        #Defining Variables to work with
        randomValue = randomValue()
        tree = binaryTree()
        newItems = range(10)

        #Pull random strings into the Tree
        for i in newItems:
            newString = randomValue.rString()
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
    def testAVLTree():
        
        #Defining Variables to work with
        randomValue = randomValue()
        tree = avlTree()
        newItems = range(10)

        #Pull random strings into the Tree
        for i in newItems:
            randomValue = randomValue.rInteger()
            print("AVL-Tree add:", randomValue)
            tree.insert(randomValue)
            print("Value was added")

        #Output from the Tree
        print("AVL-Tree Output: ", tree.preOrderOutput())
        #Check if Value is in the AVL Tree
        print("Is the Value: ", randomValue, " in the AVL-Tree? ", tree.has(randomValue))
        #Delete the Value out of the Tree
        tree.delete(randomValue)
        print(randomValue, " was deleted out of the Tree")
        #Check if the Value is in the Tree
        print(randomValue, " is in the Tree: ", tree.has(randomValue))
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
    def testGenericTree():

        #Defining Variables to work with
        randomValue = randomValue()
        tree = binaryTree()
        newItems = range(10)

        #Pull random integer Values into the Tree
        for i in newItems:
            randomValue = randomValue.rInteger()
            print("Generic-Tree add: ", randomValue)
            tree.insert(randomValue)
            print("Value was added!")

        #Output from the Tree
        print("Generic-Tree Output: ", tree.preOrderOutput)
        #Print the Height of the Tree
        print("Height of the Tree: ", tree.height(tree.getRootNode()))

        
        #Now adding some other Values to our Tree - Floats
        for i in newItems:
            randomValue = randomValue.rFloat()
            print("Generic-Tree add: ", randomValue)
            tree.insert(randomValue)
            print("Value was added!")

        #Another Output from the Tree - now with additional Floats
        print("Generic-Tree Output: ", tree.preOrderOutput)

        #Delete last Float and check if its gone
        print("Deleteing: ", randomValue)
        tree.delete(randomValue)
        print("Last added Float is gone: ", tree.has(randomValue))
        #Output of Tree Height
        print("Generic-Tree Height: ", tree.Height(tree.getRotNode()))
        
        #Now adding some other Values to our Tree - String
        for i in newItems:
            randomValue = randomValue.rString()
            print("Generic-Tree add: ", randomValue)
            tree.insert(randomValue)
            print("Value was added!")

        #Another Output from the Tree - now with additional Strings
        print("Generic-Tree Output: ", tree.preOrderOutput)
        
        #Delete last Float and check if its gone
        print("Deleting: ", randomValue)
        tree.delete(randomValue)
        print("Last added String is gone: ", tree.has(randomValue))
        #Output of Tree Height
        print("Generic-Tree Height: ", tree.Height(tree.getRotNode()))
