using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics.Contracts;

namespace Exercise01{
    namespace System.Diagnostics.Contracts
    {
        /*
         * Class for Binary Tree with Integer Values
         */
        class BinaryTree
        {

            /*
             * Design by Contract Definition
             * Invariants 
             * --> 
             */
            [ContractInvariantMethod]
            protected void ObjectInvariant()
            {
                //Contract.Invariant(root.GetValue() != null);
                Contract.Invariant(root.GetParent() == null);
            }

            /*
             * Initial Root Node for Default Constructor
             * -> Initialized with null
             */
            private Node root = null;

            /*
             * Constructor for BinaryTree with int values
             * Console Output that the BinaryTree is created with the given value
             */
            public BinaryTree(int value)
            {
                root = new Node(value, null);
                Contract.Assert(root.GetValue() == value);
            }

            /*
             * Setter of BinaryTree
             * Modifing the Root is NOT allowed. Otherwise the Tree is not valid
             * @Param: User wants to modify the root with a new root which is prohibited
             */
            public void SetRoot(Node root)
            {
                Console.WriteLine("Modifing the root after initializiation of the BinaryTree is not allowed.");
                Console.WriteLine("Please Create a new BinaryTree.");
                Console.WriteLine("Nothing has been modified!");
            }

            /*
             * Getter of BinaryTree
             * @Param Value: Root Node is the return Value of the Getter
             */
            public Node GetRoot()
            {
                Contract.Ensures(GetRoot().Equals(this.root));
                return root;
            }

            /*
             * Method for User Insert
             * Public Visible to insert new Values in the BinaryTree
             * @Param int value: Value which will be added to the BinaryTree
             */
            public void Insert(int value)
            {
                Insert(root, value);
            }

            /*
             * Method to add Values 
             * -> Smaller than root on the left child 
             * -> Bigger than root or equal on the rigth child
             * Methode uses Recursion to insert a Node in the suited place in the tree
             * --> Ensures that the new value exists in the tree after method
             */
            private void Insert(Node parent, int value)
            {
                /*
                 * Check if root is valid -> not null
                 */
                if(root != null){
                    /*
                     *  Check if value of parent is smaller than the given value
                     */
                    if(value < parent.GetValue()){
                        /*
                         * Check if there is another Node on the left side
                         * Recursive call of Insert with Left Node unitl there
                         * is no Node Object
                         */
                        if(parent.GetLeft() != null){
                            Insert(parent.GetLeft(), value);
                        }
                        /*
                         * If not -> new Node will be created
                         */
                        else
                        {
                            parent.SetLeft(new Node(value, parent));
                        }
                    }
                    /*
                     * Same thing for the other side (Right Side)
                     * of the BinaryTree
                     */
                    else
                    {
                        /*
                         * Check if there is another Node on the right side
                         * Recursive call of Insert with Right Node until there
                         * is no Node Object
                         */
                        if (parent.GetRight() != null)
                        {
                            Insert(parent.GetRight(), value);
                        }
                        /*
                         * If not -> new Node will be created
                         */
                        else
                        {
                            parent.SetRight(new Node(value, parent));
                        }
                    }
                    Contract.Ensures(HasValue(value));
                }
            }

            /*
             *  Georgia : My try on has-Method
             *  If HasValue2 returns null --> nothing found or no tree --> false
             *  If HasValue2 returns an Node --> Value found in tree --> true
             *  It is ensured that just one of these two possibilities gets returned
             */
            public Boolean HasValue(int value)
            {
                Boolean result;

                /*
                 * Check if return Parameter is not null and
                 * so there is the Value in the BinaryTree
                 */
                if (WhereIsValue(root, value) != null)
                {
                    result = true;
                }
                
                /*
                 * Else when the value doesn't exist in
                 * the BinaryTree
                 */
                else
                {
                    result = false;
                }
                Contract.Ensures(result.Equals(true) || result.Equals(false));
                return result;
            }

            /*
             *  Method searches the given value and returns
             *  the node with the matching value
             *  No recoginition of duplicate values 
             *  -> first come, first serve
             *  Ensures that return-Node has the given value as its value
             */
            private Node WhereIsValue(Node node, int value)
            {
                Node result = null;

                /*
                 * Check if Node is not null
                 */
                if (node == null)
                {
                    Console.WriteLine("Value doesn't exist");
                } 
                
                /*
                 * Check if Value of Node and given value is the same
                 */
                if (value.CompareTo(node.GetValue()) == 0)
                {
                    result = node;
                } 
                
                /*
                 * Check if Value of Node and given value is smaller
                 */
                if (value.CompareTo(node.GetValue()) < 0)
                {
                    if (node.GetLeft() != null)
                    {
                        result = WhereIsValue(node.GetLeft(), value);
                    }
                }

                /*
                 * Check if Value of Node and given value is bigger
                 */
                if (value.CompareTo(node.GetValue()) > 0)
                {
                    if (node.GetRight() != null)
                    {
                        result = WhereIsValue(node.GetRight(), value);
                    }
                }

                /*
                 * CHMA:
                 * Can not be right ... or?
                 */
                //Contract.Ensures(result.GetValue() == value);
                return result;
            }


            /*
             * Method deletes Value -> Reference to Null
             * Of the matching Node from the BinaryTree
             * This Method Uses the WhereIsValue Method to 
             * identify the right Node. If this is null nothing
             * will be done by this method
             * @param value: Value which should be deleted
             * @param return boolean:   false if nothing was removed
             *                          true if the reference was removed
             */
            public Boolean Delete(int value)
            {
                /*
                 * Node deleteValue has the Node object with the 
                 * value which will be deleted from the BinaryTree
                 */
                Node deleteValue = WhereIsValue(root, value);
                Boolean delete = false;

                /*
                 * Check if the value is in the BinaryTree
                 */
                if(deleteValue != null){

                    /*
                     * Check if there is a Right Node and no Left Node
                     */
                    if(deleteValue.GetRight() != null && deleteValue.GetLeft() == null){
                        Console.WriteLine("Fixing Reference of Parent from the Right Node");
                        deleteValue.GetRight().SetParent(deleteValue.GetParent());
                        deleteValue.GetParent().SetRight(deleteValue.GetRight());
                    }

                    /*
                     * Check if there is a Left Node and no Right Node
                     */
                    if(deleteValue.GetRight() == null && deleteValue.GetLeft() != null){
                        Console.WriteLine("Fixing Reference of Parent from the Left Node");
                        deleteValue.GetLeft().SetParent(deleteValue.GetParent());
                        deleteValue.GetParent().SetLeft(deleteValue.GetLeft());
                    }

                    /*
                     * Check if there are a Left and a Right Node
                     * Left Node gets Parent from the delete Node
                     * Parent of Right Node is set to Left Node
                     */
                    if(deleteValue.GetRight() != null && deleteValue.GetLeft() != null){
                        Console.WriteLine("Fixing Reference of Parent from the Left and Right Node");
                        deleteValue.GetRight().SetParent(deleteValue.GetParent());
                        deleteValue.GetParent().SetRight(deleteValue.GetRight());
                        deleteValue.GetLeft().SetParent(deleteValue.GetRight());
                    }
                        
                    /*
                     * Removing Reference of the Object -> Delete
                     * Set the Boolean true -> return parameter
                     */
                   Console.WriteLine("Deleting Value: " + value);
                   deleteValue = null;
                   delete = true;
                }
                return delete;   
            }

            /*
             * Delete All Method is running for the whole time 
             * that Delete Method is true. So you can define by 
             * yourself if you want to delete the first node object 
             * of the duplicate or every matching node with the same
             * value (duplicate)
             */
            public void DeleteAll(int value)
            {
                while(Delete(value)){
                    Console.WriteLine("Value = " +value+ " of the BinaryTree with the root " +root.GetValue()+ " was deleted.");
                }
            }


            /*
             * Method returns the Node which is the last on the left side, 
             * so the one with the smallest value (if added correctly).
             * For the unsorted BinaryTree there is now method implemented yet.
             */
            private Node GetSmallest(Node smallestValue)
            {
                if (smallestValue != null)
                {
                    /*
                     * Runs for the whole left Tree Side not null
                     */
                    while (smallestValue.GetLeft() != null)
                    {
                        smallestValue = smallestValue.GetLeft();
                    }
                }
                return smallestValue;
            }

            /*
             * GetSmallest Method for Puplic User Access 
             * Root from BinaryTree is given to the Method 
             */
            public Node GetSmallest()
            {
                return GetSmallest(root);
            }

            /*
            * Method returns the Node which is the last on the rigth side, 
            * so the one with the biggest value (if added correctly).
             * For the unsorted BinaryTree there is now method implemented yet.
            */
            private Node GetBiggest(Node biggestValue)
            {
                if (biggestValue != null)
                {
                    /*
                     * Runs for the whole right Tree Side not null
                     */
                    while (biggestValue.GetRight() != null)
                    {
                        biggestValue = biggestValue.GetRight();
                    }
                }
                return biggestValue;
            }

            /*
             * GetBiggest Method for Public User Access
             * Root from BinaryTree is given to the Method 
             */
            public Node GetBiggest()
            {
                return GetBiggest(root);
            }

            /*
             * Method for Testig : Returns the values of tree in In-Order (L, W, R)
             */
            public String InOrder(Node node)
            {
                String value = "";

                if (node == null)
                {
                    Console.WriteLine("This binary tree is empty");
                }

                /*
                 * Running through the tree from the left side
                 */
                if (node.GetLeft() != null)
                {
                    value += InOrder(node.GetLeft());
                    value += " | ";
                }

                /*
                 * Showing the root after the left side is completed
                 */
                value += node.GetValue();
                value += " | ";

                /*
                 * Running through the tree from the right side
                 */
                if (node.GetRight() != null)
                {
                    value += InOrder(node.GetRight());
                    value += " | ";
                }

                /*
                 * Return of the whole String with
                 * the Output from the different Nodes
                 */
                return value;
            }

            /*
             * Test Implementation of the
             * General Problem Solver
             * Sum Problem
             */
            public int GPSSum(Node node)
            {
                /*
                 * Check if Node is null and end of recursion
                 */
                if(node == null){
                    return 0;
                }
                return node.GetValue() + GPSSum(node.GetLeft()) + GPSSum(node.GetRight());
            }

            /*
             * Test Implementation of the
             * General Problem Solver
             * Max Problem
             */
            public int GPSMax(Node node)
            {
                int max = node.GetValue();

                if(node.GetLeft() != null){
                    max = Math.Max(max, GPSMax(node.GetLeft()));
                }
                if(node.GetRight() != null){
                    max = Math.Max(max, GPSMax(node.GetRight()));
                }
                return max;
            }
        }
    }
}