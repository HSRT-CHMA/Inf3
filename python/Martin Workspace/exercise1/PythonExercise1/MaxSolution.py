'''
Created on 17.04.2015

@author: Marco

Class for SumSolutions for GPS
'''
class MaxSolution():
    
    '''
    Return the Maximum
    ''' 
    @property
    def maxSolution(self):
        # Pre & Post Condition
        assert type(self._maxSolution) == int
        return self._maxSolution

    '''
    Parms: maxSolution: Set Maximum
    '''
    @maxSolution.setter
    def maxSolution(self,maxSolution):
        # Pre Condition
        assert type(maxSolution) == int
        if type(maxSolution) == int:
            self._maxSolution = maxSolution
        # Post Condition
        assert type(self._maxSolution) == int

