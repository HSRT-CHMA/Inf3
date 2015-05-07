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
            MaxProblem max = new MaxProblem();
            SumProblem sum = new SumProblem();
            
            max.SetBinaryTree(tree);
            max.ComputeSolution();
            Console.WriteLine("MaxSolution:" + max.GetSolution().GetMax());

            sum.SetBinaryTree(tree);
            sum.ComputeSolution();
            Console.WriteLine("SumSolution:" + sum.GetSolution().GetSum());

            /*
             * That the console output is visible
             */
            Console.ReadKey();
        }
    }
}