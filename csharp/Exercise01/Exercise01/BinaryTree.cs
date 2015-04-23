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
                root = new Node(value);
                Console.WriteLine("New BinaryTree is initialized with Value: " + value);
            }

            /*
             * Setter of BinaryTree
             * Modifing the Root is NOT allowed. Otherwise the Tree is not valid
             * @Param: User wants to modify the root with a new root which is prohibited
             */
            public void SetRoot(Node root)
            {
                Console.WriteLine("Modifing the root after initializiation of the BinaryTree is not allowd.");
                Console.WriteLine("Please Create a new BinaryTree");
            }

            /*
             * Getter of BinaryTree
             * @Param Value: Root Node is the return Value of the Getter
             */
            public Node GetRoot()
            {
                return root;
            }

            /*
             * Method creates a tree with given value as root, or
             * adds new given int-value to existing tree by calling InsertValue-Metod
             * @Param int value: Value which will be added to the BinaryTree
             * Duplicate Values are also added on the Right Side of the Tree
             */
            public void Insert(int value)
            {
                if (root == null)
                {
                    root = new Node(value);
                }
                else
                {
                    this.InsertValue(root, value);
                }
            }

            /*
             * Method to insert Values 
             * -> Smaller than root on the left child 
             * -> Bigger than root or equal on the rigth child
             */
            private void InsertValue(Node new_n, int new_value)
            {
                if (new_n == null)
                {
                    new_n = new Node(new_value);
                } if (root == null)
                {
                    root = new_n;
                }
                else
                {
                    if ((new_value.CompareTo(new_n.GetValue())) < 0)
                    {
                        if (new_n.GetLeft() != null)
                        {
                            InsertValue(new_n.GetLeft(), new_value);
                        }
                        else
                        {
                            new_n.SetLeft(new Node(new_value));
                            Console.WriteLine("Left :  " + new_value);
                        }
                    } if (new_value.CompareTo(new_n.GetValue()) >= 0)
                    {
                        if (new_n.GetRight() != null)
                        {
                            InsertValue(new_n.GetRight(), new_value);
                        }
                        else
                        {
                            new_n.SetRight(new Node(new_value));
                            Console.WriteLine("Right : " + new_value);
                        }
                    }

                }
            }

            /*
             *  Georgia : My try on has-Method
             *  If HasValue2 returns null --> nothing found or no tree --> false
             *  If HasValue2 returns an Node --> Value found in tree --> true
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
                return result;
            }

            /*
             *  Method searches the given value and returns
             *  the node with the matching value
             *  No recoginition of duplicate values 
             *  -> first come, first serve
             */
            private Node WhereIsValue(Node n, int value)
            {
                Node result = null;

                if (n == null)
                {
                    result = null;
                } if (value.CompareTo(n.GetValue()) == 0)
                {
                    return n;
                } if (value.CompareTo(n.GetValue()) < 0)
                {
                    if (n.GetLeft() == null)
                    {
                        result = null;
                    }
                    else
                    {
                        result = WhereIsValue(n.GetLeft(), value);
                    }
                }

                if (value.CompareTo(n.GetValue()) > 0)
                {
                    if (n.GetRight() == null)
                    {
                        result = null;
                    }
                    else
                    {
                        result = WhereIsValue(n.GetRight(), value);
                    }
                }

                return result;
            }


            /*
             * Method redirects to DeleteValue()
             */
            public Boolean Delete(int new_value)
            {
                return DeleteValue(root, new_value, null, false);
            }

            /*
             * If Tree is empty, nothing can be deleted
             * Method receive root-Node , new value, the parent node and flag if node is left
             * 
             */
            private Boolean DeleteValue(Node new_n, int new_value, Node parent, Boolean is_left)
            {
                if (new_n == null)
                {
                    return false;
                } if (new_value.CompareTo(new_n.GetValue()) == 0)
                {
                    if ((new_n.GetLeft() == null) && (new_n.GetRight() == null))
                    {
                        if (parent == null)
                        {
                            root = null;
                        }
                        else
                        {
                            FindParent(parent, is_left, null);
                        }
                        return true;
                    }

                    if ((new_n.GetLeft() != null) && (new_n.GetRight() == null))
                    {
                        if (parent == null)
                        {
                            root = null; // Sicher ? Warum nicht : new_n.GetLeft() 
                        }
                        else
                        {
                            FindParent(parent, is_left, new_n.GetLeft());
                        }
                        return true;
                    }

                    if ((new_n.GetLeft() == null) && (new_n.GetRight() != null))
                    {
                        if (parent == null)
                        {
                            root = new_n.GetRight();
                        }
                        else
                        {
                            FindParent(parent, is_left, new_n.GetRight());
                        }
                        return true;
                    }

                    Node n = GetSmallest(new_n.GetRight());
                    Delete(n.GetValue());
                    if (parent == null)
                    {
                        n.SetLeft(root.GetLeft());
                        n.SetRight(root.GetRight());
                        root = n;
                    }
                    else
                    {
                        n.SetLeft(new_n.GetLeft());
                        n.SetRight(new_n.GetRight());
                        FindParent(parent, is_left, n);
                    }

                }

                /*
                 * Found nothing : continue search on left side
                 */
                if (new_value.CompareTo(new_n.GetValue()) < 0)
                {
                    if (parent.GetLeft() == null)
                    {
                        return DeleteValue(new_n.GetLeft(), new_value, parent, true);
                    }
                }

                /*
                 * Found nothing : continue search on right side
                 */
                if (new_value.CompareTo(new_n.GetValue()) > 0)
                {
                    if (parent.GetRight() == null)
                    {
                        return DeleteValue(new_n.GetRight(), new_value, parent, false);
                    }
                }
                return false;
            }

            /*
             * Method returns the smallest value existing in the current tree
             * Warning if there exists no tree 
             */
            public int GetSmallest()
            {
                Node node = GetSmallest(root);
                int value = 0;

                if (node != null)
                {
                    value = node.GetValue();
                }
                else
                {
                    Console.WriteLine("Class BinaryTree, Method GetSmallest, no Tree exists");
                }
                return value;
            }

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
             * Method returns the biggest value existing in the current tree
             * Warning if there exists no tree 
             */
            public int GetBiggest()
            {

                Node node = GetBiggest(root);
                int value = 0;

                if (node != null)
                {
                    value = node.GetValue();
                }
                else
                {
                    Console.WriteLine("Class BinaryTree, Method GetBiggest, no Tree exists ");
                }
                return value;
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
             * Method for Testig : Redirects to In-Order (L, W, R) - Method
             */

            public String InOrderOutput()
            {
                return InOrder(root);
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