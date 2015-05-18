class Constant(object):
    """description of class"""

    def __init__(self, params):
        #params : A string containing the value of the constant
        '''
        Constructor
        ''' 
        print("New Constant : " + params)
        self.setValue(params)
        
    def setValue(self, params):
        constant_value = int(params)
        
    def getValue(self):
        return self.constant_value
