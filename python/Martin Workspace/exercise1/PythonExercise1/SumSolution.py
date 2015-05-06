'''
Created on 17.04.2015

@author: Marco

Class for SumSolutions for GPS
'''
class SumSolution:
    '''
    Return sum = Summary.
    ''' 
    @property
    def sumSolution(self):
        # Pre & Post Condition
        assert type(self._sumSolution) == int
        return self._sumSolution

    '''
    Parms: sumSolution: Set the sum
    '''
    @sumSolution.setter
    def sumSolution(self,sumSolution):
        # Pre Condition
        assert type(sumSolution) == int
        if type(sumSolution) == int:
            self._sumSolution = sumSolution
        # Post Condition
        assert type(self._sumSolution) == int


