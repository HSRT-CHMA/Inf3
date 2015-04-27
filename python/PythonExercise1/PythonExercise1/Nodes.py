'''
Created on 17.04.2015

@author: Marco

Class for Nodes
'''    
class Nodes():
    
    left=0                              # Class Variables
    right=0
    content=0
    
    def __init__(self):                 # Constructor Nodes
        self.setContent(content)
    
    def getLeft():                      # Getter Left Node
        return left
    
    def setLeft(left):                  # Setter Left Node
        if left != None:
            self.left = left
    
    def getRight():                     # Getter Right Node
        return right
    
    def setRight(right):                # Setter Right Node
        if right != None:
            self.right = right
    
    def getContent():                   # Getter Content Node
        return content
    
    def setContent(content):            # Setter Content Node
        self.content = content
    
    def getContent(content):            # Getter Content Node at content Value
        self.content = content
    
    def toString():                     # toString Function
        return "Content of Node : " + getContent()