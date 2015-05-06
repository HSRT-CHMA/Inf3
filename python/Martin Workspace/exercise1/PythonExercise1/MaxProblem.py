'''
Created on 17.04.2015

@author: Marco

Class for MaxProblems for GPS
'''
from DivisibleProblem import DivisibleProblem
from BinaryTree import BinaryTree
from MaxSolution import MaxSolution
from Nodes import Nodes

class MaxProblem(DivisibleProblem):
    
    '''
    Constructor MaxProblem
    '''
    def __init__(self):
        self._solution = MaxSolution()
        # Post Condition
        assert type(self._solution) == MaxSolution
    
    '''
    Return tree
    '''
    @property
    def tree(self):
        # Pre & Post Condition
        assert type(self._tree) == BinaryTree 
        return self._tree
    
    '''
    Set tree starts Calculation of Maximum
    Parms: tree: the given tree
    '''
    @tree.setter
    def tree(self, tree):
        # Pre Condition
        assert type(tree) == BinaryTree 
        if type(tree) == BinaryTree and tree.getRootNode() != None:
            self._tree = tree
            self._node = tree.getRootNode()
            self.solve()
        else:
            raise TypeError("tree have to be a BinaryTree with a root")
        # Post Condition
        assert type(self._tree) == BinaryTree 
    
    '''
    Is Problem direct solvable
    '''
    def isDirectlySolvable(self):
        # Pre Condition
        assert type(self.tree) == BinaryTree 
        if type(self.tree) == BinaryTree:
            if self._node.right == None:
                self._solution.maxSolution = self._node.value
                self.directlySolvable = True
                # Post Condition
                assert self.directlySolvable == True 
    
    '''
    Divides Problem into smaller problems 
    '''
    def part(self):
        # Pre Condition
        assert type(self._node) == Nodes 
        while self._node.right != None:
            self._node = self._node.right
        # Post Condition    
        assert type(self._node) == Nodes
    
    '''
    Return Solution
    '''
    def getSolution(self):
        # Pre & Post Condition
        assert type(self._solution) == MaxSolution 
        return self._solution.maxSolution  


