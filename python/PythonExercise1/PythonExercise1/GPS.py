'''
Created on 17.04.2015

@author: Marco

Class for General Problem Solver
'''
from abc import abstractmethod, ABCMeta
class GPS(metaclass=ABCMeta):

    '''
    Abstract method return Solution
    '''
    @abstractmethod
    def getSolution(self):
        pass