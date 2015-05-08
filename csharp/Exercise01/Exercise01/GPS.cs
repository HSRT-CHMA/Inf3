using Exercise01.System.Diagnostics.Contracts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise01{
    /*
     * Class for General Problem Solver
     */
    class GPS{
        /*
         * GPS has a BinaryTree where the operations
         * should be executed
         */
        BinaryTree tree = null;
        MaxProblem max = null;
        SumProblem sum = null;

        /*
         * Default Constructor of General Problem Solver
         */
        public GPS(BinaryTree tree){
            
            /*
             * Initialization of Variables
             * tree - BinaryTree Object
             * max - MaxProblem Object
             * sum - SumProblem Object
             */
            this.tree = tree;
            this.max = new MaxProblem(tree.GetRoot());
            this.sum = new SumProblem(tree.GetRoot());
        }

        /*
         * Getter for Max Value
         * from GetSolution
         */
        public int GetMax()
        {
            return max.GetSolution().GetMax();
        }

        /*
         * Getter for Sum Value
         * from GetSolution
         */
        public int GetSum()
        {
            return sum.GetSolution().GetSumValue();
        }
    }
}