using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise01{
    /*
     * Class for Binary Tree with Integer Values
     */
    class BinaryTree{
        private Node root = null;

        /*
         * Default Constructor for BinaryTree
         */
        public BinaryTree(int value){
            root = new Node(value, null);
        }
        public void insert(int value){
            /*
             * Check if root null
             */
            if(root == null){
                root = new Node(value, null);
            }

            /*
             * Check if Value is smaller
             */
            else if (root.getValue() < value){
             
            }
            /*
             * Check Left Tree Side
             */

            
            /*
             * Check Right Tree Side
             */
            

        }
        public void delete(int value){
            
        }
    }
}
