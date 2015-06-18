using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics.Contracts;
using System.Collections;

namespace BinaryTree
{
    class Node<T> 
        //Organises single Node-Objects in a given Tree
    {
        private T value = default(T);
        private Node<T> left = null;
        private Node<T> right = null;
        private Node<T> parent = null;

        /// <summary>
        /// First node of the binarytree will be initalize
        /// </summary>
        /// <param name="value">value of the first node</param>
        public Node(T value)
        {
            this.setData(value);
            this.setParent(null);
        }
        /// <summary>
        /// Initalize further nodes of the binary tree
        /// </summary>
        /// <param name="value">Value of the node</param>
        /// <param name="n">Parent of the node</param>
        public Node(T value, Node<T> n)
        {
            this.setData(value);
            this.setParent(n);
        }
        /// <summary>
        /// Return the Value of the node
        /// </summary>
        /// <returns>Value of the node</returns>
        public T getData()
        {
            return value;
        }
        /// <summary>
        /// Set the Value of the node
        /// </summary>
        /// <param name="value">new Value of the node</param>
        public void setData(T value)
        {
            //Contract.Requires(value > 0);
            this.value = value;
            //Contract.Ensures(this.value > 0);
        }
        /// <summary>
        /// get the node which is left
        /// </summary>
        /// <returns>node which is left</returns>
        public Node<T> getLeft()
        {
            return left;
        }
        /// <summary>
        /// get the node which is right
        /// </summary>
        /// <returns>node which is right</returns>
        public Node<T> getRight()
        {
            return right;
        }
        /// <summary>
        /// Set the parent of the node
        /// </summary>
        /// <param name="n">node which is the parent</param>
        public void setParent(Node<T> n)
        {
            this.parent = n;
        }
        /// <summary>
        /// get the parent of the node
        /// </summary>
        /// <returns>Node which is the parent</returns>
        public Node<T> getParent()
        {
            Contract.Requires(parent != null);
            return parent;



        }
        /// <summary>
        /// set the node which is left
        /// </summary>
        /// <param name="n">the node which is left</param>
        public void setLeft(Node<T> n)
        {
            this.left = n;
        }
        /// <summary>
        /// set the node which is right
        /// </summary>
        /// <param name="n">the node which is right</param>
        public void setRight(Node<T> n)
        {
            this.right = n;
        }
        /// <summary>
        /// return the vale of the node as String
        /// </summary>
        /// <returns>String with the value of the node</returns>
        public override String ToString()
        {
            return "" + getData();
        }
    }
}
