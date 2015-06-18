'''
Created on 18.06.2015

@author: Martin Watolla
'''

import random, math, string

class Tester():
    '''
    init the Tester
    '''
    def __init__(self, binaryTree):
        self.tree = binaryTree
        
    '''
    create a randam integer value
    '''
    def random_data_generator (self):
        
            return random.randint(0, 30)

    '''
    create a random String
    '''
    def random_string_generator(self):
        size=6 
        chars=string.ascii_uppercase
        return ''.join(random.choice(chars) for _ in range(size))
    
    '''
    the method for the integer test for the AVL tree fill the tree with random values 
    ''' 
    def int_test(self,tree):
        i = 0
        it = []
        while i < 10:    
            data = self.random_data_generator()
            tree.insert(data)
            it.insert(i, data)
            i = i+1
             
        for x in it:
            print(tree.has(x))
            
    '''
    The method for the String test for the generic tree fill the tree with random stringvalues
    '''       
    def string_test(self,tree):
        i = 0
        st = []
        while i < 10:    
            data = self.random_string_generator()
            tree.insert(data)
            st.insert(i, data)
            i = i+1
             
        for x in st:
          
            print(tree.has(x))