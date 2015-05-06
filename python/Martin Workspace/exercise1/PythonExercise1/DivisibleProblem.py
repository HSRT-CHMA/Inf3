'''
Created on 17.04.2015

@author: Marco

Class for Divisible Problems for GPS
'''
from abc import abstractmethod, ABCMeta
from GPS import GPS

class DivisibleProblem(Problem, metaclass=ABCMeta):

    '''
    Return true if problem is direct solvable.
    '''
    @property
    def directlySolvable(self):
        # Pre & Post Condition
        assert type(self._directlySolvable) == bool 
        return self._directlySolvable
    
    '''
    Parms: directlySolvable: Set if problem is direct solvable
    '''
    @directlySolvable.setter
    def directlySolvable(self, directlySolvable):
        # Pre Condition
        assert type(directlySolvable) == bool
        self._directlySolvable = directlySolvable
        # Post Condition
        assert type(self._directlySolvable) == bool 

    '''
    Abstract method checks if problem is direct solvable.
    '''
    @abstractmethod
    def isDirectlySolvable(self):
        pass
    
    '''
    Abstract method divides a not direct solvable problem into smaller problems.
    '''
    @abstractmethod
    def part(self):
        pass
    
    '''
    Solves the problem.
    '''
    def solve(self):
        self.directlySolvable = False
        # Pre Condition
        assert self.directlySolvable == False 
        while not self.directlySolvable:
            self.isDirectlySolvable()
            self.part()
        # Post Condition
        assert self.directlySolvable == True 