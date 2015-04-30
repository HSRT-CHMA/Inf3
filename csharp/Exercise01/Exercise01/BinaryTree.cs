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

                if (WhereIsValue(root, value) != null)
                {
                    result = true;
                }
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

                if (node == null)
                {
                    result = null;
                } if (value.CompareTo(node.GetValue()) == 0)
                {
                    return node;
                } if (value.CompareTo(node.GetValue()) < 0)
                {
                    if (node.GetLeft() == null)
                    {
                        result = null;
                    }
                    else
                    {
                        result = WhereIsValue(node.GetLeft(), value);
                    }
                }

                if (value.CompareTo(node.GetValue()) > 0)
                {
                    if (node.GetRight() == null)
                    {
                        result = null;
                    }
                    else
                    {
                        result = WhereIsValue(node.GetRight(), value);
                    }
                }

                Contract.Ensures(result.GetValue() == value);
                return result;
            }


            /*
             * Method redirects to DeleteValue()
             */
            public Boolean Delete(int new_value)
            {
                return true;   
            }

            /*
             * If Tree is empty, nothing can be deleted
             * Method receive root-Node , new value, the parent node and flag if node is left
             * It is ensured that ALL nodes with given value are deleted !
             * 
             */


            /*
             * Method returns the Node which is the last on the left side, so the one with the smallest value (if added correctly)
             */
            public Node GetSmallest(Node start)
            {
                if (start != null)
                {
                    while (start.GetLeft() != null)
                    {
                        start = start.GetLeft();
                    }
                }
                return start;
            }

            /*
            * Method returns the Node which is the last on the rigth side, so the one with the biggest value (if added correctly)
            */

            public Node GetBiggest(Node start)
            {
                if (start != null)
                {
                    while (start.GetRight() != null)
                    {
                        start = start.GetRight();
                    }
                }
                return start;
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

                //L
                if (node.GetLeft() != null)
                {
                    value += InOrder(node.GetLeft());
                    value += " | ";
                }

                //W
                value += node.GetValue();
                value += " | ";

                //
                if (node.GetRight() != null)
                {
                    value += InOrder(node.GetRight());
                    value += " | ";
                }

                return value;
            }


            /*
             *  Method to set a Node "under" a given parent-node , either left or rigth 
             */
            private void FindParent(Node parent, Boolean left, Node new_n)
            {
                if (left)
                {
                    parent.SetLeft(new_n);
                }
                else
                {
                    parent.SetRight(new_n);
                }
            }

        }
    }
}