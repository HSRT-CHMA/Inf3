using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise01{
    /*
     * Node Class for BinaryTree
     */
    class Node{
        
        /*
         * Private Variables for Node Class
         */
        private Node parent;
        private int value;
        private Node left, right;

        /*
         * Constructor for Node with int value
         */
        public Node(int value) {
            this.value = value;
            SetLeft(left);
            SetRight(right);

            Console.WriteLine("New Node with Value: " + value);
        }

        /*
         * Setter for Node Class 
         */
        public void SetValue(int value){
            this.value = value;
        }

        public void SetLeft(Node left){
            this.left = left;
        }

        public void SetRight(Node right){
            this.right = right;
        }

        public void SetParent(Node parent){ 
            this.parent = parent;
        }

        /*
         * Getter for Node
         */
        public Node GetLeft(){
            return left;
        }

        public Node GetRight(){
            return right;
        }

        public int GetValue(){
            return value;
        }
        
        public Node GetParent(){
            return parent;
        }
    }
}
