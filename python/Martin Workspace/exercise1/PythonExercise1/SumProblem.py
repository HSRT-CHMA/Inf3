'''
Created on 17.04.2015

@author: Marco

Class for SumProblems for GPS
'''
from DivisibleProblem import DivisibleProblem
from SumSolution import SumSolution
from BinaryTree import BinaryTree
from Nodes import Nodes
class SumProblem(DivisibleProblem):
    
    '''
    Constructor for a SumProblem
    '''     
    def __init__(self):
        self._solution = SumSolution()
        # Post Condition
        assert type(self._solution) == SumSolution

    '''
    Return BinaryTree
    '''
    @property
    def tree(self):
        # Pre & Post Condition
        assert type(self._tree) == BinaryTree
        return self._tree

    '''
    Set Tree and starts Calculation
    Parms: tree: Given Tree
    '''
    @tree.setter
    def tree(self,tree):
        #  Pre Condition
        assert type(tree) == BinaryTree
        if type(tree) == BinaryTree and tree.getRootNode() != None:
            self._tree = tree
            self._node = tree.getRootNode()
            self._sum = 0
            self.solve()
        else:
            raise TypeError("tree have to be a BinaryTree with root")
        # Post Condition
        assert type(self._tree) == BinaryTree
        
    '''
    Is Problem direct solvaable
    '''             
    def isDirectlySolvable(self):
        # Pre Condition
        assert type(self.tree) == BinaryTree
        if type(self.tree) == BinaryTree:
            if self._node.left == None and self._node.right == None:
                self._solution.sumSolution = self._node.value
                self.directlySolvable = True
                # Post Condition
                assert self.directlySolvable == True

    '''
    if Problem is not direct Solvable
    '''
    def part(self):
        # Pre Condition
        assert type(self._node) == Nodes
        self.sumRec(self._node)
        self._solution.sumSolution = self._sum
        self._directSolvable = True
        # Post Condition
        assert type(self._node) == Nodes

    '''
    Called by part Recursive calculation of Summary sum
    '''
    def sumRec(self,node):
        # Pre Condition
        assert type(self._node) == Nodes
        if node == None:
            # Post Condition
            assert node == None
            return
        self.sumRec(node.left)
        self.sumRec(node.right)
        self._sum += node.value

    '''
    Return Solution
    '''
    def getSolution(self):
        # Pre & Post Condition
        assert type(self._solution) == SumSolution
        return self._solution.sumSolution
