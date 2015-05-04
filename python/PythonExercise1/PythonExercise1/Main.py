'''
Created on 17.04.2015

@author: Marco

Main Function for BinaryTree and General Problem Solver
'''

from BinaryTree import BinaryTree
from GPS import GPS

if __name__== "__main__":
    myTree = BinaryTree(2)              # Erstellung BinaryTree Root 2
    myTree.insert(345)
    myTree.insert(456)
    myTree.insert(5463)
    print(myTree)                       # Ausgabe myTree

   # gps = GPS(myTree)                   # Erstellung General Problem Solver auf myTree 


