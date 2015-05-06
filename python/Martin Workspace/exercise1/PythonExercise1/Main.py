'''
Created on 17.04.2015

@author: Marco

Main Function for BinaryTree and General Problem Solver
'''

from BinaryTree import BinaryTree
from Nodes import Nodes
#from GPS import GPS

if __name__== "__main__":
    myTree = BinaryTree(Nodes(2))       # Erstellung BinaryTree Root 2
    myTree.insert(2)
    myTree.insert(-1)
    myTree.delete(2)
    print(myTree.has(2))
    print(myTree.has(-1))

   # gps = GPS(myTree)                  # Erstellung General Problem Solver auf myTree 


