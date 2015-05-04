'''
Created on 17.04.2015

@author: Marco

Class for BinaryTree with Integers
'''
from Nodes import Nodes
class BinaryTree():                     # Class BinaryTree
    
    _root = Nodes(None,None)            # Initial Root Node for Initializiation

    def __init__(self,value):           # Constructor of BinaryTree
        self.root= Nodes(value,None)
    
    def setRoot(root):                  # Setter Root
        print("Can't change root after Initializiation")

    def getRoot():                      # Getter Root
        return root

    def insert(value):                  # Function to Insert a Value in the BinaryTree 
        insert(root,value)  
    
    def insert(parent, value):          # Insert a Value in the BinaryTree
        if root is not None:
            if value < parent.getValue():
                if parent.getLeft() is not None:    
                    insert(parent.getLeft(),value)
                else:
                    parent.setLeft(Nodes(value,parent))
            else:
                if parent.getRight() is not None:
                    insert(parent.getRight(),value)
                else:
                    parent.setRight(Nodes(value,parent))

    def hasValue(value):                # Value in Tree ?
        result = False
        if whereIsValue(root,value) is not None:
            result = True
        else:
            result = False
        return result

    def whereIsValue(node,value):       # Is Value in Tree ?
        nodeX = None
        if node is None:
            nodeX = None
        if value.compareTo(node.getValue()) == 0:
            nodeX = node
        if value.compareTo(node.getValue()) < 0:
            if node.getLeft() is None:
                nodeX = None
            else:
                nodeX = whereIsValue(node.getLeft(),value)
        if value.compareTo(node.getValue()) > 0:
            if node.getRight() is None:
                nodeX = None
            else:
                nodeX = whereIsValue(node.getRight(),value)
        return nodeX

    def delete(value):                  # delete a value in Tree reacomplish parents
        deleteNode = whereIsValue(root,value)
        delete = False
        if deleteNode is not None:
            if deleteNode.getRight() is not None & deleteNode.getLeft() is None:
                deleteNode.getRight().setParent(deleteNode.getParent())
            if deleteNode.getRight() is None & deleteNode.getLeft() is not None:
                deleteNode.getLeft().setParent(deleteNode.getParent())
            if deleteNode.getRight() is not None & deleteNode.getLeft() is not None:
                deleteNode.getLeft().setParent(deleteNode.getParent())                  
                deleteNode.getRight().setParent(deleteNode.getLeft())
            deleteNode = None
            delete = True
        return delete
    
    def getSmallest(value):             # Function to get Smallest Value in Tree         
        if value is not None:
            while value.getLeft() is not None:
                value = value.getLeft()
        return value
    
    def getSmallest():                  # Function to get smallest Value  
        return getSmallest(root)
        
    def getBiggest(value):              # Function to get Biggest Value
        if value is not None:
            while value.getRight() is not None:
                value = value.getRight()
        return value

    def getBiggest():                   # Function to get Biggest Value
        return getBiggest(root) 

    def getNodes(content):                  # Function to get Nodes with Value content
        return getNodesRec(root, content)   # calls Recursion in getNodesRec
        
    def getNodesRec(k, content):            # Recursion to get Nodes with Value content
        if k == None: 
            return None
        if content.compareTo(k.getContent()) == 0: 
            return k
        if content.compareTo(k.getContent()) < 0:
            if k.getLeft() == None:
                return None
        return getNodesRec(k.getRight(), content)
        if content.compareTo(k.getContent()) > 0:
            if k.getRight() == None:
                return None
        return getNodesRec(k.getRight(), content)
        return None
    
    def preOrderOutput():                   # Calls Recursion for preOrderOutput
        return preOrder(root)
    
    def preOrder(root):                     # Deepness trough Recursion preOrder
        s = ""
        if root == None:
            return "empty"
        s += root.getContent() + " "        # Root Value
        if root.getLeft() != None:          # Left Nodes
            s += preOrder(root.getLeft()) + " "
        if root.getRight() != None:         # Right Nodes
            s += preOrder(root.getRight())
        return s
    
    def inOrderOutput():                    # Calls Recursion for inOrderOutput
        return inOrder(root)
    
    def inOrder(root):                      # Recursion inOrder
        s = ""
        if root == None:
            return "empty"
        if root.getLeft() != None:          # Left Nodes
            s += inOrder(root.getLeft()) + " " 
        s += root.getContent() + " "        # Root Value
        if root.getRight() != None:         # Right Nodes
            s += inOrder(root.getRight()) + " "
        return s
    
    def postOrderOutput():                  # Calls Recursion for postOrderOutput
        return postOrder(root)
    
    def postOrder(root):                    # Recursion postOrder
        s = ""
        if root == None:
            return "empty"
        if root.getLeft() != None:          # Left Nodes
            s += postOrder(root.getLeft()) + " " 
        if root.getRight() != None:         # Right Nodes
            s += postOrder(root.getRight()) + " "
        s += root.getContent() + " "        # Root Value
        return s
    
    def toString():                         # toString Function
        return "Content of Node : " + root.getContent()

    def compareTo(self, that):
        return ((self > that) - (self < that))

'''
    def __lt__ (self, other):
        if self.a == other.a:
            return self.b < other.b
        return self.a < other.b
'''