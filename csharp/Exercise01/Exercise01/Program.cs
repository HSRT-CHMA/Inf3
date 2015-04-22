using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise01{
    /*
     * Initial Start Program
     */
    class Program{
        static void Main(string[] args){
            //Creating Binary Object with Values: 
            BinaryTree tree = new BinaryTree(4);
            tree.insert(3);
            tree.insert(5);
            tree.insert(-2);
            tree.insert(33);
            
            //Creating GPS Object with Values: 
            GPS pSolver = new GPS();
        }
    }
}
