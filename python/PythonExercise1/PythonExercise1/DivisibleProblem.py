'''
Created on 17.04.2015

@author: Marco

Class for Divisible Problems for GPS
'''
from abc import abstractmethod, ABCMeta
from GPS import GPS

class DivisibleProblem(GPS, metaclass=ABCMeta):

    '''
    Return true if problem is direct solvable
    '''
    @property
    def directSolvable(self):
        # Pre & Post Condition
        assert type(self._directSolvable) == bool 
        return self._directSolvable
    
    '''
    Parms: directSolvable: Set if problem is direct solvable
    '''
    @directSolvable.setter
    def directSolvable(self, directSolvable):
        # Pre Condition
        assert type(directSolvable) == bool
        self._directSolvable = directSolvable
        # Post Condition
        assert type(self._directSolvable) == bool 

    '''
    Abstract method checks if problem is direct solvable
    '''
    @abstractmethod
    def isDirectSolvable(self):
        pass
    
    '''
    Abstract method divides not direct solvable problems into smaller problems
    '''
    @abstractmethod
    def part(self):
        pass
    
    '''
    Solution of the problem
    '''
    def solve(self):
        self.directSolvable = False
        # Pre Condition
        assert self.directSolvable == False 
        while not self.directSolvable:
            self.isDirectSolvable()
            if not self.directSolvable:
                self.part()
        # Post Condition
        assert self.directSolvable == True 