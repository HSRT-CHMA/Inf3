using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise01{
    class Node{
        
        /*
         * Private Variables for Node Class
         */
        private int value;
        private Node left, right;

        /*
         * Constructor for Node
         */
        public Node(int value){
            this.value = value;
        }

        /*
         * Setter for Node Class 
         */
        private setValue(int value){
            this.value = value;
        }

        private setLeft(Node left){
            this.left = left;
        }

        private setRight(Node right){
            this.right = right;
        }
    }
}
