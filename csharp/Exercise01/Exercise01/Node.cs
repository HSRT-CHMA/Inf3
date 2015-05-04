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
         * Node Class for BinaryTree
         */
        class Node
        {
            /*
             * Design by Contract Definition
             */
            [ContractInvariantMethod]
            protected void ObjectInvariant()
            {
                
                /**
                 * Invariants of Node
                 * -> Left must be smaller than the Right Node
                 * -> Right must be bigger or equals than the root
                 * -> The Values of Right and Left must be not equal
                 */
                Contract.Invariant(this.GetLeft().GetValue() < this.GetRight().GetValue());
                Contract.Invariant(this.GetLeft().GetValue() >= this.GetRight().GetValue());
                Contract.Invariant(this.GetLeft().GetValue() != this.GetRight().GetValue());
            }

            /*
             * Private Variables for Node Class
             */
            private Node parent=null;
            private Node left=null;
            private Node right=null;
            private int value;

            /*
             * Constructor for Node with int value
             */
            public Node(int value, Node parent)
            {
                this.value = value;
                this.parent = parent;

                if(parent == null)
                {
                    Console.WriteLine("New Tree with Root " + value + " was created.");
                }
                else
                {
                    Console.WriteLine("New Node with Value: " + value);
                }
            }

            /*
             * Setter for Node Class 
             * Setter for the Value of the Node
             */
            public void SetValue(int value)
            {
                this.value = value;
                Contract.Ensures(value == this.GetValue());
            }

            /*
             * Set Left Node from the actual Node
             * Default intialization is set with null
             */
            public void SetLeft(Node left)
            {
                Contract.Requires(left.GetValue() < this.GetValue());
                this.left = left;
                Contract.Ensures(this.GetLeft().Equals(left));
            }

            /*
             * Set Right Node from the actual Node
             * Default intialization is set with null
             */
            public void SetRight(Node right)
            {
                Contract.Requires(right.GetValue() >= this.GetValue());
                this.right = right;
                Contract.Ensures(this.GetRight().Equals(right));
            }

            /*
             * Set the Parent Node where the Node is born from
             * Is set at the Constructor of Node to the "root"
             */
            public void SetParent(Node parent)
            {
                this.parent = parent;
                Contract.Ensures(this.GetParent().Equals(parent));
            }

            /*
             * Getter for Node
             * Getter for Left Node
             */
            public Node GetLeft()
            {
                Contract.Ensures(left.Equals(this.GetLeft()));
                return left;
            }

            /*
             * Getter for the Right Node
             */
            public Node GetRight()
            {
                Contract.Ensures(right.Equals(this.GetRight()));
                return right;
            }

            /*
             * Getter for the Value of the Node
             */
            public int GetValue()
            {
                Contract.Ensures(value == this.GetValue());
                return value;
            }

            /*
             * Getter for the Parent of the Node
             */
            public Node GetParent()
            {
                Contract.Ensures(parent.Equals(this.GetParent()));
                return parent;
            }
        }
    }
}
