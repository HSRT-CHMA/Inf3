'''
Created on 17.04.2015

@author: Marco

Class for Nodes
'''    
class Nodes:
    '''
    Constructor Nodes
    Parms: left: the left child Node
           right: the right child Node
           parent: the parent Node
    '''
    def __init__(self,value,left = None, right = None, parent = None):
        # Pre Conditions
        assert type(value) == int
        assert type(left) == Nodes or left == None  
        assert type(right) == Nodes or right == None  
        assert type(parent) == Nodes or parent == None
        self.value = value                
        self.left = left
        self.right = right
        self.parent = parent
        # Post Conditions
        assert type(self.value) == int
        assert type(self.left) == Nodes or self.left == None
        assert type(self.right) == Nodes or self.right == None
        assert type(self.left) == Nodes or self.left == None  
    
    '''
    Return int value of the Node
    '''
    @property
    def value(self):
        # Pre & Post Condition
        assert type(self._value) == int
        return self._value

    '''
    Parms: value: the Value of the Node
    '''
    @value.setter
    def value(self,value):
        # Pre Condition
        assert type(value) == int
        if type(value) == int:
            self._value = value
        else:
            raise TypeError("value have to be int")
        # Post Condition
        assert type(self.value) == int

    '''
    Return left child Node
    '''
    @property
    def left(self):
        # Pre & Post Condition
        assert type(self._left) == Nodes or self._left == None
        return self._left

    '''
    Parms: left: the left child Node
    '''
    @left.setter
    def left(self,left):
        # Pre Condition
        assert type(left) == Nodes or left == None
        if type(left) == Nodes or left == None:
            self._left=left
        else:
            raise TypeError("left have to be a Node or None")
        # Post Condition
        assert type(self.left) == Nodes or self.left == None
        
    '''
    Return right child Node
    '''
    @property
    def right(self):
        # Pre & Post Condition
        assert type(self._right) == Nodes or self._right == None
        return self._right

    '''
    Parms: right: the right child Node
    '''
    @right.setter
    def right(self,right):
        # Pre Condition
        assert type(right) == Nodes or right == None
        if type(right) == Nodes or right == None:
            self._right=right
        else:
            raise TypeError("right have to be a Node or None")
        # Post Condition
        assert type(self.right) == Nodes or self.right == None

    '''
    Return parent Node
    '''
    @property
    def parent(self):
        # Pre & Post Condition
        assert type(self._parent) == Nodes or self._parent == None
        return self._parent

    '''
    Parms: parent: the left child Node
    '''
    @parent.setter
    def parent(self,parent):
        # Pre Condition
        assert type(parent) == Nodes or parent == None
        if type(parent) == Nodes or parent == None:
            self._parent=parent
        else:
            raise TypeError("parent have to be a Node or None")
        # Post Condition
        assert type(self.parent) == Nodes or self.parent == None
