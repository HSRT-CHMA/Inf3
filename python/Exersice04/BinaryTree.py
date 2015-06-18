'''
Created on 18.06.2015

@author: Martin Watolla
'''
'''
This class is an implementation of a binary tree.
'''
from Node import Node
from Tree import Tree


class BinaryTree(Tree):
    
    '''
    The __init__-method generates a binary tree.
    The data type of the parameter value is either int or None. It's the value of the root.
    '''
    def __init__(self, value):
        
        if value is not None:
            self.__root = Node(value)
        else:
            self.__root = None
        
    
    
    '''
    The method inserts the parameter value in the binary tree.
    The data type of the parameter is int.
    If there's no root, it inserts a root. Otherwise it starts a recursion to insert.
    '''
    def insert(self,value):
       
        if self.__root is None and type(value) is int:
            self.__root = Node(value)
        else:
            self.__insertRecursion(self.__root, value)
       
            
    '''
    This is the recursion to insert a node.
    Duplicates will be inserted to the right.
    The data type of the parameter currentNode is Node and of value it's int.
    '''
    def __insertRecursion(self,currentNode,value):
        
        if currentNode is None:
            currentNode = Node(value)
        if self.__root is None:
            self.__root = currentNode
        else:
            
            if value < currentNode.getData(): # left
                if currentNode.getLeft() is not None:
                    self.__insertRecursion(currentNode.getLeft(), value)
                else:
                    currentNode.setLeft(Node(value))
                    currentNode.getLeft().setParent(currentNode)
            if value >= currentNode.getData():
                if currentNode.getRight() is not None:
                    self.__insertRecursion(currentNode.getRight(), value)
                else:
                    currentNode.setRight(Node(value))
                    currentNode.getRight().setParent(currentNode)
       

                
    '''
    The method returns a boolean. It returns true if the parameter value is in the tree.
    '''
    def has(self,value):
        return self.__hasRecursion(self.__root,value)
    
    '''
    This method searches for the parameter value.
    The data type of currentNode is Node.
    The data type of value is int.
    It returns a boolean variable. It returns true when the value is in the tree.
    '''
    def __hasRecursion(self,currentNode,value):
        has = False
        if currentNode is None:
            has = False
        elif currentNode.getData() is value:
            has = True #found
        elif value < currentNode.getData(): #search left
            has = self.__hasRecursion(currentNode.getLeft(), value)
        elif value > currentNode.getData(): #search right
            has = self.__hasRecursion(currentNode.getRight(), value)
            
        return has
        
            
    '''
    This method invokes the method __deleteRecursion if there's a node with the value of the parameter value in the tree.
    Otherwise there's nothing to delete.
    It returns a boolean. If the node with the value is deleted it returns a True. If there's nothing to delete it returns a False.
    '''
    def delete(self,value):
        has = False
        while self.has(value):
            has = self.__deleteRecursion(self.__root, value, None, False)
        
        return has
    
    
    '''
    This method searches for the node with the value and deletes it.
    The data type of the parameter value is int.
    The data type of the parameter currentNode is Node. 
    The data type of the parameter parent is Node. It's the node above the currentNode.
    The data type of the parameter isLeft is boolean. It's True when it's the left child of the parent.
    The method returns a boolean. It's true 
    '''
    def __deleteRecursion(self, currentNode, value, parent, isLeft):
        isDeleted = False
        if currentNode is None:
            isDeleted = False
        if value is currentNode.getData():
            if currentNode.getLeft() is None and currentNode.getRight() is None:
                if parent is None:
                    self.__root = None
                    isDeleted = True
                else:
                    self.__insertUnderParent(parent,isLeft,None)
                    isDeleted = True
            elif currentNode.getLeft() is None and currentNode.getRight() is not None:
                if parent is None:
                    self.__root = currentNode.getRight()
                    isDeleted = True
                else:
                    self.__insertUnderParent(parent, isLeft, currentNode.getRight())
                    isDeleted = True
            elif currentNode.getLeft() is not None and currentNode.getRight() is None:
                if parent is None:
                    self.__root = currentNode.getLeft()
                    isDeleted = True
                else:
                    self.__insertUnderParent(parent, isLeft, currentNode.getLeft())
                    isDeleted = True
            elif currentNode.getLeft() is not None and currentNode.getRight() is not None:
                x = self.__getMax(currentNode.getLeft())
                self.delete(x.getData())
                if parent is None:
                    x.setLeft(self.__root.getLeft())
                    x.setRight(self.__root.getRight())
                    self.__root = x
                else:
                    x.setLeft(currentNode.getLeft())
                    x.setRight(currentNode.getRight())
                    self.__insertUnderParent(parent,isLeft,x)
        if value < currentNode.getData():
            if currentNode.getLeft() is not None:
                isDeleted = self.__deleteRecursion(currentNode.getLeft(), value, currentNode, True)
        if value > currentNode.getData():
            if currentNode.getRight() is not None:
                isDeleted = self.__deleteRecursion(currentNode.getRight(), value, currentNode, False)
        
        return isDeleted
        
    '''
    This method looks whether the node if right or left of the parent. If it's left, it sets the node left of the new parent.
    '''  
    def __insertUnderParent(self, parent, isLeft, currentNode):
        if isLeft:
            parent.setLeft(currentNode)
        else:
            parent.setRight(currentNode)
            
    '''
    This method returns the node with the highest value.
    The parameter start is the node where you want to start searching.
    '''
    def __getMax(self, start):
        if start is not None:
            while start.getRight() is not None:
                start = start.getRight()
            return start
    
    '''
    This method returns the root of the tree.
    '''
    def getRoot(self):
        return self.__root
    
    '''
    Returns a string.
    Used for the output of __inorderOutput.
    '''
    @property
    def output(self):
        return self._outputString
    
    '''
    Parameters: outputString: a String, used for the output of __inorderOutput
    '''
    @__outputRec.setter
    def __outputRec(self, outputString):
        if type(outputString) == str:
            self._outputString = outputString
        else:
            raise TypeError("outputString must be a String")
