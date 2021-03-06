'''
Created on 17.04.2015

@author: Marco
'''
from Exercise1 import Nodes
class Binarytree:    
    def __init__(self):
        
    root = Nodes(Integers i)
    def add(i):
    if root is None:
        root = new Nodes(Integer i)
    else: 
        self.addRec(root, i)   
    def addRec(Nodes k, i):
    if k is None:
        k = new Nodes(i) 
    if root is None:
        root = k
    else: 
        if i.compareTo(k.getContent()) < 0: #Content from i is smaller then k
            if k.getLeft() != None:
                addRec(k.getLeft(),Integer i)
            else:
                k.setLeft(new Nodes(i))
            if i.compareTo(k.getContent()) > 0: #Content from i is bigger then k
                if k.getRight() != None:
                    addRec(k.getRight(),Integer i)
            else:
                k.setRight(new Nodes(i))
    def getHight():
    return getHightRec(0, root)
    def getHightRec(actHight, Nodes k):
    if k != None:
        return Math.max(getHightRec(actHight + 1, k.getLeft()), getHightRec(actHight + 1, k.getRight()))
    return actHight
    def getSmallest():
    Nodes k = getSmallest(root)
    if k == None:
        return 0
    else:
        return k.getContent()
    def Nodes getSmallest(Nodes start):
    if start != None:
        while start.getLeft() != None:
            start = start.getLeft()
            return start
        def Nodes getNodes(content):
            return getNodesRec(root, content)
        def Nodes getNodesRec(Nodes k, content):
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
    def preOrderOutput():
        return preOrder(root)
    def preOrder(Nodes root):  #Deepness trough Recursion
        s = ""
        if root == None:
            return "empty"
        s += root.getContent() + " "       #Ro
        if root.getLeft() != None:      #L
            s += preOrder(root.getLeft()) + " "
        if root.getRight() != None:     #R
            s += preOrder(root.getRight())
    return s
    def inOrderOutput():
        return inOrder(root)
    def inOrder(Nodes root):
        s = ""
        if root == None:
            return "empty"
        if root.getLeft() != None:       #L
            s += inOrder(root.getLeft()) + " " 
        s += root.getContent() + " "   #Ro
        if root.getRight() != None:       #R
            s += inOrder(root.getRight()) + " "
    return s
    def postOrderOutput()
        return postOrder(root)
    def postOrder(Nodes root)
        s = ""
        if root == None:
            return "empty"
        if root.getLeft() != None:        #L
            s += postOrder(root.getLeft()) + " " 
        if root.getRight() != None:   #R
            s += postOrder(root.getRight()) + " "
        s += root.getContent() + " "      #Ro
    return s
    
    def String toString():
        return "Content of Node : " + root.getContent()