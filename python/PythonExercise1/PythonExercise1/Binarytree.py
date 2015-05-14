'''
Created on 17.04.2015

@author: Marco

Class for BinaryTree with Integers
'''
from Nodes import Nodes
class BinaryTree:                       
    '''
    Constructor BinaryTree
    Parms: root: root Node of Tree
           outString : used for inOrder output
    '''
    def __init__(self,value = None):
        # Pre Condition
        assert type(value) == int or value == None
        if value != None:
            self.__root = Nodes(value)         
        else:
            self.__root = None
        self.__outString = ""
        # Post Conditions
        assert type(self.__root) == Nodes or self.__root == None
        assert self.__outString == ""

    '''
    Return root Node
    '''
    @property
    def __root(self):
        # Pre & Post Condition
        assert type(self._root) == Nodes or self.__root == None
        return self._root

    '''
    Parms: root: Root of Tree
    '''
    @__root.setter
    def __root(self,root):
        # Pre Condition
        assert type(root) == Nodes or root == None
        if type(root) == Nodes or root == None:
            self._root = root
        else:
            raise TypeError("__root have to be a Node")
        # Post Condition
        assert type(self.__root) == Nodes or self.__root == None
       
    '''
    Return root of Tree
    '''   
    def getRootNode(self):
        # Pre & Post Condition
        assert type(self._root) == Nodes or self._root == None
        return self._root
       
    '''
    Return String
    Used for __inOrder
    '''   
    @property
    def __outString(self):
        # Pre & Post Condition
        assert type(self._outString) == str
        return self._outString
    
    '''
    Parms: outString: String used for __inOrder
    ''' 
    @__outString.setter
    def __outString(self,outString):
        # Pre Condition
        assert type(outString) == str
        if type(outString) == str:     
            self._outString = outString
        else:
            raise TypeError("outString have to be a String")
        # Post Condition
        assert type(self.__outString) == str
       
    '''
    Insert a new Node with value to Tree
    if value is already in Tree new Node will be placed as right child
    Parms: value: value for new Node
    '''
    def insert(self,value):
        # Pre Condition
        assert type(value) == int
        if self.__root == None:
            self.__root = Nodes(value)
        else:
            self.__insertRec(self.__root,value)
        # Post Condition
        assert self.has(value)

    '''
    Called by insert for Recursive insert of value
    Parms: node: local Recursion Node
           value: value for new Node
    '''
    def __insertRec(self,node,value):
        # Pre Conditions
        assert type(node) == Nodes or node == None
        assert type(value) == int
        if value < node.value:
            if node.left == None:
                # Post Condition
                assert node.left == None
                node.left = Nodes(value,None,None,node)
            else:
                # Post Condition
                assert node.left != None
                self.__insertRec(node.left,value)
        if value >= node.value:
            if node.right == None:
                # Post Condition
                assert node.right == None
                node.right = Nodes(value,None,None,node)
            else:
                # Post Condition
                assert node.right != None
                self.__insertRec(node.right,value)

    '''
    Return Bool
    if value exists true else false
    Parms: value: searched value
           bol: local bool
           node: local node
    '''
    def has(self,value):
        # Pre Condition
        assert type(value) == int
        bol = False
        node = self.__root
        while node != None and not bol:
            if node.value == value:
                bol = True
            else:
                if value < node.value:
                    node = node.left
                else:
                    node = node.right
        # Post Condition
        assert type(bol) == bool
        return bol
        
    '''
    Delete all Nodes with this value
    Parms: value: All Nodes with this value will be deleted
    '''                                          
    def delete(self,value):
        # Pre Condition
        assert type(value) == int
        while self.has(value):
            self.__deleteRec(self.__root,value,None)
        # Post Condition
        assert not self.has(value)

    '''
    Called by delete to delete all Nodes with this value Recursive
    Parms: node: local Current Node
           value: the value what should be deleted
           parent: parent of node
    '''
    def __deleteRec(self,node,value,parent):
        # Pre Conditions
        assert type(node) == Nodes or node == None
        assert type(value) == int
        assert type(parent) == Nodes or parent == None
        if node != None and node.value == value:
            # Post Conditions
            assert node != None
            assert node.value == value
            if node == self.__root:
                # Post Conditon
                assert node == self.__root
                self.__delNode(node,node.parent,False)
            else:
                # Post Condition
                assert node != self.__root
                self.__delNode(node,node.parent,node.parent.left == node)
        else:
            # Post Condition
            assert (node == None) or (node.value != value)
            if node.left != None:
                # Post Condition
                assert node.left != None
                self.__deleteRec(node.left,value,node)
            if node.right != None:
                # Post Condition
                assert node.right != None
                self.__deleteRec(node.right,value,node)

    '''
    Checking if Node have no child, one or two Childs
    Calls Tasks to Delete
    Parms: node: Node that should be deleted
           parent: parent of node
           lChild: bool for node to check is left Child or not
    '''
    def __delNode(self,node,parent,lChild):
        # Pre Conditions
        assert type(node) == Nodes
        assert type(parent) == Nodes or parent == None
        assert type(lChild) == bool
        if node.left == None and node.right == None:
            # Post Condition
            assert node.left == None and node.right == None
            self.__delNoChild(node,parent,lChild)
        elif (node.left != None and node.right == None) or (node.left == None and node.right != None):
            # Post Condition
            assert (node.left != None and node.right == None) or (node.left == None and node.right != None)
            self.__delOneChild(node,parent,lChild,node.left != None)
        elif node.left != None and node.right != None:
            # Post Condition
            assert node.left != None and node.right != None
            self.__delTwoChild(node,parent,lChild)

    '''
    Delete Node with no Child
    Parms: node: Node that should be deleted
           parent: parent of node that should be deleted
           lChild: bool if node is left Child of parent
    '''
    def __delNoChild(self,node,parent,lChild):
        # Pre Conditions
        assert type(node) == Nodes
        assert type(parent) == Nodes
        assert type(lChild) == bool
        if node == self._root:
            # Post Condition
            assert node == self._root
            self._root = None
            # Post Condition
            assert self._root == None
        elif lChild:
            # Post Condition
            assert lChild
            parent.left = None
            # Post Condition
            assert parent.left == None
        else:
            # Post Conditions
            assert not lChild
            assert node != self._root
            parent.right = None
            # Post Condition
            assert parent.right == None

    '''
    Delete Node with One Child
    Parms: node: Node that should be deleted
           parent: parent of node that should be deleted
           lChild: bool if node is left Child of parent
           haslChild: bool if node has left Child
    '''
    def __delOneChild(self,node,parent,lChild,haslChild):
        # Pre Conditions
        assert type(node) == Nodes
        assert type(parent) == Nodes or parent == None
        assert type(lChild) == bool
        assert type(haslChild) == bool
        if node == self._root:
            if haslChild:
                # Post Condition
                assert haslChild
                self._root = node.left
                # Post Condition
                assert self._root == node.left
            else:
                # Post Condition
                assert not haslChild
                self._root = node.right
                # Post Condition
                assert self._root == node.right
        elif lChild:
            # Post Condition
            assert lChild
            if haslChild:
                # Post Condition
                assert haslChild
                node.left.parent = parent
                # Post Condition
                assert node.left.parent == parent
                parent.left = node.left
                # Post Condition
                assert parent.left == node.left
            else:
                # Post Condition
                assert not haslChild
                node.right.parent = parent
                # Post Condition
                assert node.left.parent == parent
                parent.left = node.right
                # Post Condition
                assert parent.left == node.left
        else:
            # Post Condition
            assert node != self._root
            if haslChild:
                # Post Condition
                assert haslChild
                node.left.parent = parent
                # Post Condition
                assert node.left.parent == parent
                parent.right = node.left
                # Post Condition
                assert parent.right == node.left
            else:
                # Post Condition
                assert not haslChild
                node.right.parent = parent
                # Post Condition
                assert node.right.parent == parent
                parent.right = node.right
                # Post Condition
                assert parent. right == node.right

    '''
    Delete Node with two Children
    Parms: node: Node that should be deleted
           parent: parent of node that should be deleted
           lChild: bool if node is the left Child of parent
    '''
    def __delTwoChild(self,node,parent,lChild):
        # Pre Conditions
        assert type(node) == Nodes
        assert type(parent) == Nodes or parent == None
        assert type(lChild) == bool
        smallest = self.__getSmallest(node.right)
        node.value = smallest.value
        self.__delNode(smallest,smallest.parent,smallest.parent.left == smallest)
        # Post Condition
        assert smallest != node

    '''
    Return smallest Node, start at given Node
    Parms: node: start from this Node
    '''
    def __getSmallest(self,node):
        # Pre Condition
        assert type(node) == Nodes
        smallest = node
        while smallest.left != None:
            smallest = smallest.left
        # Post Condition
        assert type(smallest) == Nodes and smallest != None
        return smallest

    '''
    Print Tree inOrder
    Calls __inOrderRec for Recursive print of __outString
    '''
    def inOrder(self):
        # Pre Conditions
        assert type(self.__root) == Nodes or self.__root == None
        assert self.__outString == ""
        self.__inOrderRec(self.__root)
        print("In Order: " + self.__outString)
        self.__outString = ""
        # Post Condition
        assert self.__outString == ""

    '''
    Called by inOrder to store value in __outString
    Parms: node: Start Node
    '''
    def __inOrderRec(self,node):
        # Pre Condition
        assert type(node) == Nodes or node == None
        if node == None:
            # Post Condition
            assert node == None
            return
        # Post Condition
        assert node != None
        self.__inOrderRec(node.left)
        self.__outString += str(node.value) + " "
        self.__inOrderRec(node.right)