'''
    Binary Tree Class
    Inf3 - Group 7
'''
#Defining Imports
from genericTree import genericTree
from genericNode import genericNode

'''
Binary Tree Class with Generics 
form Exercise 1.2
'''
class binaryTree(genericTree):
    
    '''
    Constructor for BinaryTree Class
    '''
    def __init___ (self, value = None):
        if value != None:
            self.__root = Node(value)
        else:
            self.__root = None
        self.__outputString = ""


    
    #Getter for the Class binaryTree
    @property 
    def __root(self):
        return self.__root

    def getRootNode(self):
        return self._root

    #Setter for the Class binaryTree
    @__root.setter
    def __root(self, root):
        if type(root) == Node or root == None:
            self.__root = root
        else:
            raise TypeError("Root Node musst be a Node.")

    #Getter for Root Node
    def getRootNode(self):
        return self._root

    '''
    Returns a string.
    Used for the output of __inorderOutput.
    '''
    @property
    def __outputString(self):
        return self._outputString
    
    '''
    Parameters: outputString: a String, used for the output of __inorderOutput
    '''
    @__outputString.setter
    def __outputString(self, outputString):
        if type(outputString) == str:
            self._outputString = outputString
        else:
            raise TypeError("outputString must be a String")

    '''
    Insert Method which can be called by the Main Program
    '''
    def insert(self, value):
        if self.__root == None:
            self.__root = Node(value)
        else:
            self.__insertRecursion(self.__root, value)

    '''
    Method which inserts a Object to the BinaryTree with Recursion
    '''
    def __insertRecursion(self, node, value):
        if value < node.value:
            if node.left == None:
                node.left = Node(value, None, None, node)
            else:
                self.__insertRecursion(node.left, value)
        if value >= node.value:
            if node.right == None:
                node.right = Node(value, None, None, node)
            else:
                self.__insertRecursion(node.right, value)

    '''
    Returns true if a Node with the given value exists.
    In other cases false will be returned.
    Parameters: value: the value to search the Nodes for.
    '''
    def has(self, value):
        value = False
        currentNode = self.__root
        while currentNode != None and not found:
            if currentNode.value == value:
                value = True
            else:
                if value < currentNode.value:
                    currentNode = currentNode.left
                else:
                    currentNode = currentNode.right
        return value

    '''
    Method to delete all Nodes with the given value.
    Parameters: value: Nodes with this value will be deleted.
    Duplicates in the Tree will be also deleted
    '''
    def delete(self, value):
        while self.has(value):
            self.__deleteRecursion(self.__root, value, None)
    
            
    '''
    Checks if the Node that should be deleted has no child, one child or two children and calls
    the corresponding method to delete the Node.
    nodeToDel: the Node that should be deleted
    parent: the parent of the node that should be deleted
    isLeftChild: boolean, indicates if the nodeToDel is the left child of parent
    '''
    def __deleteNode(self, nodeToDel, parent, isLeftChild):
        if nodeToDel.left == None and nodeToDel.right == None:
            self.__delNoChild(nodeToDel, parent, isLeftChild)
        elif (nodeToDel.left != None and nodeToDel.right == None) or (nodeToDel.left == None and nodeToDel.right != None):
            self.__delOneChild(nodeToDel, parent, isLeftChild, nodeToDel.left != None)
        elif nodeToDel.left != None and nodeToDel.right != None:
            self.__delTwoChildren(nodeToDel, parent, isLeftChild)
    
    '''
    Deletes a Node with no child.
    nodeToDel: the Node that should be deleted
    parent: the parent of the node that should be deleted
    isLeftChild: boolean, indicates if the nodeToDel is the left child of parent
    '''                
    def __delNoChild(self, nodeToDel, parent, isLeftChild):
        if nodeToDel == self._root:
            self._root = None
        elif isLeftChild:
            parent.left = None
        else:
            parent.right = None
    
    '''
    Deletes a Node with one child.
    nodeToDel: the Node that should be deleted
    parent: the parent of the node that should be deleted
    isLeftChild: boolean, indicates if the nodeToDel is the left child of parent
    hasLeftChild: boolean, indicates if the nodeToDel has a left child
    ''' 
    def __delOneChild(self, nodeToDel, parent, isLeftChild, hasLeftChild):
        if nodeToDel == self._root:
            if hasLeftChild:
                self._root = nodeToDel.left
            else:
                self._root = nodeToDel.right
        elif isLeftChild:
            if hasLeftChild:
                nodeToDel.left.parent = parent
                parent.left = nodeToDel.left
            else:
                nodeToDel.right.parent = parent
                parent.left = nodeToDel.right
        else:
            if hasLeftChild:
                nodeToDel.left.parent = parent
                parent.right = nodeToDel.left
            else:
                nodeToDel.right.parent = parent
                parent.right = nodeToDel.right    
      
    '''
    Deletes a Node with two children.
    nodeToDel: the Node that should be deleted
    parent: the parent of the node that should be deleted
    isLeftChild: boolean, indicates if the nodeToDel is the left child of parent
    '''         
    def __delTwoChildren(self, nodeToDel, parent, isLeftChild):
        smallest = self.__getSmallest(nodeToDel.right)
        nodeToDel.value = smallest.value
        self.__deleteNode(smallest, smallest.parent, smallest.parent.left == smallest)
         
    '''
    Method to 
    '''        
    def __deleteRecursion(self, currentNode, value, parent):
        if currentNode != None and currentNode.value == value:
            if currentNode == self.__root:
                self.__deleteNode(currentNode, currentNode.parent, False)
            else:
                self.__deleteNode(currentNode, currentNode.parent, currentNode.parent.left == currentNode)
        else:
            if currentNode.left != None:
                self.__deleteRecursion(currentNode.left, value, currentNode)
            if currentNode.right != None:
                self.__deleteRecursion(currentNode.right, value, currentNode)
