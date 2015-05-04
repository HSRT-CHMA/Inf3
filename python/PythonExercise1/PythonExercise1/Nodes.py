'''
Created on 17.04.2015

@author: Marco

Class for Nodes
'''    
class Nodes(object):
    '''
    Class Variables
    ''' 
    _parent=None
    _left=None                              
    _right=None
    _content=0

    '''
    Constructor Nodes
    '''
    def __init__(self,content,parent):             
        self._content = setContent(content)
        self._parent = setParent(parent)
        if parent is None:
            print("New Tree with Root " + content + "was created.")
        else:
            print("New Node with Value: " + content)
    
    def getLeft():                      # Getter Left Node
        return left
    
    def setLeft(left):                  # Setter Left Node
        self.left = left
    
    def getRight():                     # Getter Right Node
        return right
    
    def setRight(right):                # Setter Right Node
        self.right = right
    
    def setParent(parent):              # Setter Parent
        self.parent= parent

    def getParent(parent):              # Getter Parent
        return parent

    def getContent():                   # Getter Content Node
        return content
    
    def setContent(content):            # Setter Content Node
        self.content = content
    
    def getContent(content):            # Getter Content Node at content Value
        self.content = content