'''
Created on 18.06.2015

@author: Martin Watolla
'''
'''
    Class for Node Objects
'''

class Node:

    '''
        Constructor of Node
        Setting Value
        to the given Values
    '''
    def __init__(self, value):
        self.value = None
        self.parent = None
        self.left = None
        self.right = None
        self.setValue(value)


    '''
        Definition of all Setters and Getters
    '''

    #Getter for Value of Node
    def getValue(self):
        return self.value

    #Setter for Value of Node
    def setValue(self, value):
        self.value = value


    #Getter for Parent Node
    def getParent(self):
        return self.parent

    #Setter for Parent Node
    def setParent(self, parent):
        self.parent = parent


    #Getter for Left Node
    def getLeft(self):
        return self.left

    #Setter for Left Node
    def setLeft(self, left):
        self.left = left


    #Getter for Right Node
    def getRight(self):
        return self.right

    #Setter for Right Node
    def setRight(self, right):
        self.right = right