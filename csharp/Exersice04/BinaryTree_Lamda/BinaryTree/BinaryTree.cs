using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics.Contracts;

namespace BinaryTree
{
    class BinaryTree<T> : AbstractTree<T>, IEnumerable<T> where T : IComparable<T>
    {
        private Comparison<IComparable> comp = CompareElements;
        private Node<T> node = null;
        
        /// <summary>
        /// This Method performes a foreach()-loop on the output of Traversal statrting at the root-node
        /// needs two help-Methods to cover the whole tree
        /// </summary>
        /// <returns>The data of the actual node in a yield statement</returns>
        public IEnumerator<T> GetEnumerator()
         {
             foreach (Node<T> tmp in Traversal(node)) 
               { 
                   yield return tmp.getData(); 
               }
         }

        /// <summary>
        /// This Method is built-in and iterates over the main tree; splits it up in 
        /// left and right sub-tree
        /// </summary>
        /// <returns>Returns the nodes in the tree one after one</returns>
         System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
         {
             if (node.getLeft() != null)
             {
                 foreach (Node<T> LeftNode in Traversal(node.getLeft()))
                     yield return node.getData();
             }
             yield return node.getData(); 

             if (node.getRight() != null)
             {
                 foreach (Node<T> RightNode in Traversal(node.getRight()))
                     yield return node.getData(); 
             }
         }



        /// <summary>
        /// This Method traversals the tree and returns the elements in it
        /// </summary>
        /// <param name="node">The node with which the traversal starts</param>
        /// <returns>Returns the nodes in the tree one after one </returns>
         private IEnumerable<Node<T>> Traversal(Node<T> node)
         {
             if (node != null)
                 //If root exists...
             {
                 if (node.getLeft() != null)
                     //Go to the left...
                 {
                     foreach (Node<T> LeftNode in Traversal(node.getLeft()))
                         yield return LeftNode;
                 }
                 yield return node;
                 // yield is used to return a single elemente one after one

                 if (node.getRight() != null)
                     //or go to the right...
                 {
                     foreach (Node<T> RightNode in Traversal(node.getRight()))
                         yield return RightNode;
                 }
             }
         }
            
        /// <summary>
        /// The overwritten Method from AbstarctTree
        /// </summary>
        /// <param name="p">The received lambda expression</param>
        /// <returns></returns>
        public override T[] Filter(Predikat<T> p)
        {
            List<T> result = new List<T>();
            foreach (Node<T> nod in Traversal(node))
            {
                if (p(nod.getData()))
                {
                    result.Add(nod.getData());
                }
            }
            return result.ToArray();
        }

        /// <summary>
        /// Standard Constructor
        /// </summary>
        public BinaryTree()
        {
        }

        /// <summary>
        /// create a new binary tree with the first node
        /// </summary>
        /// <param name="i">value of the first node</param>
        public BinaryTree(T i)
        {
            node = new Node<T>(i);

        }
        /// <summary>
        /// Return the High of the Tree
        /// </summary>
        /// <returns>integer Value</returns>
        public int getHigh()
        {
            return getHighFunction(0, node);
        }
        /// <summary>
        /// Collect the High of the Tree and return the Value
        /// </summary>
        /// <param name="aktHigh">is the aktuel high of the tree</param>
        /// <param name="n">is the aktuel sheet of the tree</param>
        /// <returns>integer with the high of the tree</returns>
        private int getHighFunction(int aktHigh, Node<T> n)
        {
            int back;
            if (n != null)
            {
                back = Math.Max(getHighFunction(aktHigh + 1, n.getLeft()), getHighFunction(aktHigh + 1, n.getRight()));
            }
            else
            {
                back = aktHigh;
            }
            return back;
        }
        /// <summary>
        /// collect the lowest value of the tree
        /// </summary>
        /// <returns>integer value with the lowest value</returns>
        public T getLowest()
        {
            T back;
            Node<T> n = getLowest(node);
            if (n == null)
            {
                back = default(T);
            }
            else
            {
                back = n.getData();
            }
            return back;
        }
        /// <summary>
        /// collect the lowest value of the tree
        /// </summary>
        /// <param name="start">Start Node of the tree</param>
        /// <returns> the node with the lowest value</returns>
        private Node<T> getLowest(Node<T> start)
        {
            if (start != null)
            {
                while (start.getLeft() != null)
                {
                    start = start.getLeft();
                }
            }
            return start;
        }
        /// <summary>
        /// Return the highest value of the tree
        /// </summary>
        /// <returns>integer with the highest value</returns>
        public T getHighest()
        {
            T back;
            Node<T> n = getHighest(node);
            if (n == null)
            {
                back = default(T);
            }
            else
            {
                back = n.getData();
            }
            return back;
        }
        /// <summary>
        /// Collect the sheet with the highest value
        /// </summary>
        /// <param name="start">Start position of the tree</param>
        /// <return>The sheet with the highest value</returns>
        private Node<T> getHighest(Node<T> start)
        {
            if (start != null)
            {
                while (start.getRight() != null)
                {
                    start = start.getRight();
                }
            }
            return start;
        }
        /// <summary>
        /// Return the node
        /// </summary>
        /// <returns> Return the node</returns>
        public Node<T> getNode()
        {
            return node;
        }
        /// <summary>
        /// Returns the node with the value you want
        /// </summary>
        /// <param name="i">The Value of the node you are searching</param>
        /// <returns>The node with the value </returns>
        public Node<T> getNode(T i)
        {
            return getNodeFunction(node, i);
        }
        /// <summary>
        /// Collect the node with the value you are searching
        /// </summary>
        /// <param name="n">Aktuel node</param>
        /// <param name="i">Value you search</param>
        /// <returns>The node with the right value</returns>
        private Node<T> getNodeFunction(Node<T> n, T i)
        {
            Node<T> back = null;
            if (n != null)
            {
                bool leftside = comp((IComparable)n.getData(), (IComparable)node.getParent().getData()) <= 0;

                if (comp((IComparable)n.getData(), (IComparable)i) == 0) //n.getData()== i
                {
                    back = n;
                }
                else if (leftside) //i < n.getData()
                {
                    if (n.getLeft() != null)
                    {
                        back = getNodeFunction(n.getLeft(), i);
                    }
                }
                else// if (i >= n.getData())
                {
                    if (n.getRight() != null)
                    {
                        back = getNodeFunction(n.getRight(), i);
                    }

                }
            }

            return back;
        }
        /// <summary>
        /// return true or vales if the tree has the value
        /// </summary>
        /// <param name="i">value you search</param>
        /// <returns> true or false if the tree has </returns>
        public override Boolean hasNode(T i)
        {
            if (getNodeFunction(node, i) != null)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        /// <summary>
        /// Return the values of the tree from the lowest to the highest value
        /// </summary>
        /// <returns>String with the output of the values</returns>
        public String inOrderOutput()
        {
            return inOrderFunction(node);
        }
        /// <summary>
        /// Return the values of the tree
        /// </summary>
        /// <param name="n">aktuel node</param>
        /// <returns>String with the value of the tree</returns>
        private String inOrderFunction(Node<T> n)
        {
            String s = "";
            if (n == null)
            {
                s = "leer";
            }
            if (n.getLeft() != null)
            {
                s = inOrderFunction(n.getLeft());
            }
            s += n.getData() + " ";
            if (n.getRight() != null)
            {
                s += inOrderFunction(n.getRight());
            }
            return s;
        }
        /// <summary>
        /// insert a new node in the binary tree only a node with a new value will be insert. 
        /// </summary>
        /// <param name="i">value of the new node</param>
        public override void insert(T i)
        {
            Contract.Requires(comp((IComparable)i, (IComparable)0) > 0, "wert ungültig");
            if (node == null)
            {
                node = new Node<T>(i);
            }
            this.insertFunction(node, i);

        }
        /// <summary>
        /// insert a new node in the tree but only with a new value 
        /// </summary>
        /// <param name="n">aktuel node of the tree</param>
        /// <param name="i">value of the new node</param>
        private void insertFunction(Node<T> n, T i)
        {
            Contract.Requires(comp((IComparable)i, (IComparable)0) > 0); //i > 0
            if (n == null)
            {
                n = new Node<T>(i);
                if (node == null)
                {
                    node = n;
                }
            }
            else
            {
                if (comp((IComparable)i, (IComparable)n.getData()) < 0) //i < n.getData()
                {
                    if (n.getLeft() != null)
                    {
                        insertFunction(n.getLeft(), i);
                    }
                    else
                    {
                        n.setLeft(new Node<T>(i, n));
                    }
                }
                if (comp((IComparable)i, (IComparable)n.getData()) > 0) //i > n.getData())
                {
                    if (n.getRight() != null)
                    {
                        insertFunction(n.getRight(), i);
                    }
                    else
                    {
                        n.setRight(new Node<T>(i, n));
                    }
                }
            }
        }
        /// <summary>
        /// Delete the node with the value you want
        /// </summary>
        /// <param name="i">value of node you want to delete</param>
        /// <returns> boolean with true for delete and false not delete </returns>
        public override Boolean delete(T i)
        {
            return deleteFunction(node, i, null, false);
        }
        /// <summary>
        /// Search the node to delete
        /// </summary>
        /// <param name="n">aktuel node</param>
        /// <param name="i">value for deleting</param>
        /// <param name="father">node which is the father</param>
        /// <param name="leftFromFather">node which is left form the father</param>
        /// <returns>boolean if the node is deletet </returns>
        private Boolean deleteFunction(Node<T> n, T i, Node<T> father, Boolean leftFromFather)
        {
            Boolean back = false;
            if (n != null)
            {
                if (comp((IComparable)n.getData(), (IComparable)i) == 0) //n.getData() == i
                {
                    if ((n.getLeft() == null) && (n.getRight() == null))
                    {
                        if (father == null)
                        {
                            node = null;
                        }
                        else
                        {
                            putUnderFather(father, leftFromFather, null);
                        }
                        back = true;
                    }
                    else if ((n.getLeft() == null) && (n.getRight() != null))
                    {
                        if (father == null)
                        {
                            node = n.getRight();
                        }
                        else
                        {

                            putUnderFather(father, leftFromFather, n.getRight());

                        }
                        back = true;
                    }
                    else if ((n.getLeft() != null) && (n.getRight() == null))
                    {
                        if (father == null)
                        {
                            node = n.getLeft();
                        }
                        else
                        {
                            putUnderFather(father, leftFromFather, n.getLeft());
                        }
                        back = true;
                    }
                    else
                    {

                        Node<T> x = getLowest(n.getRight());
                        if (x != null)
                        {
                            delete(x.getData());
                            if (father == null)
                            {
                                x.setLeft(node.getLeft());
                                x.setRight(node.getRight());
                                node = x;
                            }
                            else
                            {
                                x.setLeft(n.getLeft());
                                x.setRight(n.getRight());
                                putUnderFather(father, leftFromFather, x);
                            }
                        }
                    }

                }
                if (comp((IComparable)i, (IComparable)n.getData()) < 0) //(i < n.getData())
                {

                    if (n.getLeft() == null)
                    {
                        back = false;
                    }
                    else { back = deleteFunction(n.getLeft(), i, n, true); }
                }
                else if (comp((IComparable)i, (IComparable)n.getData()) >= 0) //(i >= n.getData())
                {
                    if (n.getRight() == null)
                    {
                        back = false;
                    }
                    else { back = deleteFunction(n.getRight(), i, n, false); }

                }
            }

            return back;
        }
        /// <summary>
        /// Set the son of the deletet node under the father
        /// </summary>
        /// <param name="father">node wich is the new father</param>
        /// <param name="left">Value if the node has left a son</param>
        /// <param name="n"> aktuel node </param>
        private void putUnderFather(Node<T> father, Boolean left, Node<T> n)
        {
            if (left)
            {
                father.setLeft(n);
                if (n != null)
                {
                    n.setParent(father);
                }
            }
            else
            {
                father.setRight(n);
                if (n != null)
                {
                    n.setParent(father);
                }
            }

        }


        /// Compares two elements to determine their positions within the tree.
        public static int CompareElements(IComparable x, IComparable y)
        {
            return x.CompareTo(y);
        }
    }
}
