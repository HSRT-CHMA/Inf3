'''
Created on 17.04.2015

@author: Marco

Class for BinaryTree with Integers
'''
class BinaryTree(Nodes):               # Inerhit Nodes
    
    root = Nodes(None)                 # Initial Root Node for Initializiation

    def __init__(self):                # Constructor of BinaryTree
        self.left=Nodes(None)
        self.right=Nodes(None)
        self.root= self
    
    def insert(i):                     # Function to Insert a Value in the BinaryTree 
        if root is None:               # Calls Recursion in insertRec
            root = i
        else: 
            self.insertRec(root, i)   
    
    def insertRec(k, i):               # Recursion to Insert a Value in the BinaryTree
        if k is None:
            k = i 
        if root is None:
            root = k
        else: 
            if i<(k.getContent()):      # Content from i is smaller then k
                if k.getLeft() != None:
                    addRec(k.getLeft(), i)
            else:
                k.setLeft(i)
            if i>=(k.getContent()):     # Content from i is bigger then k
                if k.getRight() != None:
                    addRec(k.getRight(),i)
            else:
                k.setRight(i)
    
    def getHight():                     # Function to get Highest Value in Tree
        return getHightRec(0, root)     # calls Recursion in getHightRec
    
    def getHightRec(actHight, k):       # Recursion to get Highest Value with max function
        if k != None:
            return max(getHightRec(actHight + 1, k.getLeft()), getHightRec(actHight + 1, k.getRight()))
        return actHight
    
    def getSmallest():                  # Function to get Smallest Value in Tree
        k = getSmallest(root)           
        if k == None:
            return 0
        else:
            return k.getContent()
    
    def getSmallest(start):             # Function to get smallest Value after 
        if start != None:               # start Value
            while start.getLeft() != None:
                start = start.getLeft()
            return start
        
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