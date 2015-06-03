class avlTree(genericTree):
    
    '''
        Constructor for the Class avlTree
        Initializing the Node with None
        Setting Height to -1 and Balance to 0
    '''
    def __init__(self, *args):
        self.node = None
        self.height = -1
        self.balance = 0

        if len(args) == 1:
            for i in args[0]:
                self.insert(i)


    '''
        Height Method. Returns the Height of the AVL Tree
        Recursive Call with Max Method
    '''
    def height(self):
        if self.node != None:
            value = max(self.node.left.height), self.node.right.height) + 1
        else:
            value = 0
        return value
    #Check Method - Not Working correctly

    '''
        Method for Rotating Node to
        the Left Side of the AVL-Tree
    '''
    def rotateLeft(self):
        A = self.node
        B = self.node.right.node
        T = B.left.node

        self.node = B
        B.left.node = A
        A.right.node = T

    '''
        Method for Rotating Node to 
        the Right Side of the AVL-Tree
    '''
    def rotateRight(self):
        A = self.node
        B = self.node.left.node
        T = B.right.node

        self.node = B
        B.right.node = A
        A.left.node = T

    '''
        True if Self Node is Root
    '''
    def isLeaf(self):
        return (self.height == 0)

    '''

    '''
    def insert(self, key):
        tree = self.node
        newNode = Node(key)

        if tree == None:
            self.node = newNode
            self.node.left = avlTree()
            self.node.right = avlTree()
        elif key < tree.key:
            self.node.right.insert(key)

        self.rebalance()

    '''
        Rebalance the Tree by Rotating the Nodes
        Balance is called for the whole Time that
        self.balance is not 0
    '''
    def rebalance(self):

        self.updateHeights(False)
        self.updateBalance(False)

        while self.balance < -1 or self.balance > 1:
            
            #First Check if Balance is above 1
            if self.balance > 1:
                self.node.left.rotateLeft()
                self.updateHeights()
                self.updateBalances()
            self.rotateRight()
            self.rotateHeights()
            self.updateBalances()

            #Second Check if Balance is under -1
            if self.balance < -1:
                if self.node.right.balance > 0:
                    self.node.right.rotateRight()
                    self.updateHeights()
                    self.updateBalances()
                self.rotateLeft()
                self.updateHeights()
                self.updateBalances()

    