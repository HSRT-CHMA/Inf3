'''
    AVL Node Class
    Inf3 - Group 7
'''

#No Aditional Imports needed

'''
    Node Class for AVL Tree
    The single Nodes are defined here
'''
class avlNode():

    '''
    Constructor of avlNode
    Setting the key
    Initializing left Node with None
    Initializing right Node with None
    '''
    def __init__(self,key):
        self.key = key
        self.left = None
        selft.right = None