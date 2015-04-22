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
         * Constructor for Node
         */
        public Node(int value, Node parent){
            this.value = value;
            setLeft(left);
            setRight(right);
            setParent(parent);
        }

        /*
         * Setter for Node Class 
         */
        public void setValue(int value){
            this.value = value;
        }

        public void setLeft(Node left){
            this.left = left;
        }

        public void setRight(Node right){
            this.right = right;
        }

        public void setParent(Node parent){ 
            this.parent = parent;
        }

        /*
         * Getter for Node
         */
        public Node getLeft(){
            return left;
        }

        public Node getRight(){
            return right;
        }

        public int getValue(){
            return value;
        }
        
        public Node getParent(){
            return parent;
        }
    }
}
