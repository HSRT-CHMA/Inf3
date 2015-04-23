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
            private Node parent;
            private int value;
            private Node left, right;

            /*
             * Constructor for Node with int value
             */
            public Node(int value)
            {
                this.value = value;
                SetLeft(left);
                SetRight(right);

                Console.WriteLine("New Node with Value: " + value);
            }

            /*
             * Setter for Node Class 
             */
            public void SetValue(int value)
            {
                this.value = value;
            }

            public void SetLeft(Node left)
            {
                Contract.Requires(left.GetValue() < this.GetValue());
                this.left = left;
                Contract.Ensures(this.GetLeft().Equals(left));
            }

            public void SetRight(Node right)
            {
                this.right = right;
            }

            public void SetParent(Node parent)
            {
                this.parent = parent;
            }

            /*
             * Getter for Node
             */
            public Node GetLeft()
            {
                Contract.Ensures(left.Equals(this.GetLeft()));
                return left;
            }

            public Node GetRight()
            {
                return right;
            }

            public int GetValue()
            {
                return value;
            }

            public Node GetParent()
            {
                return parent;
            }
        }
    }
}
