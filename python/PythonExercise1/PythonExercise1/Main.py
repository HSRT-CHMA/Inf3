'''
Created on 17.04.2015

@author: Marco

Main Function for BinaryTree and General Problem Solver
'''

from BinaryTree import BinaryTree
from MaxProblem import MaxProblem
from SumProblem import SumProblem


if __name__== "__main__":
    myTree = BinaryTree(2)               # Erstellung BinaryTree myTree Root 2
    myTree.insert(2)
    myTree.insert(-1)
    myTree.delete(2)
    print(myTree.has(2))
    print(myTree.has(-1))

    myTree2 = BinaryTree(5)                          # Erstellung BinaryTree myTree2 Root 5
    myTree2.insert(5)
    myTree2.insert(-1)
    myTree2.delete(9)
    print(myTree2.has(2))
    print(myTree2.has(-1))

    print(myTree.getRootNode().value)                # Ausgabe Root Node myTree,myTree2
    print(myTree2.getRootNode().value)

    print("myTree: " + str(myTree.inOrder()))        # Ausgabe in Order von myTree,myTree2
    print("myTree2: " + str(myTree2.inOrder()))

    mp = MaxProblem()                                # Erstellung Maximum auf myTree,myTree2 
    mp.tree = myTree
    print("Maximum myTree: " + str(mp.getSolution()))
    mp.tree = myTree2
    print("Maximum myTree2: " + str(mp.getSolution()))
          
    sp = SumProblem()                                # Erstellung Summary auf myTree,myTree2
    sp.tree = myTree
    print("Summary myTree: " + str(sp.getSolution()))                                          
    sp.tree = myTree2
    print("Summary myTree2: " + str(sp.getSolution()))  

    gps = GPS()
    gps2 = GPS()
