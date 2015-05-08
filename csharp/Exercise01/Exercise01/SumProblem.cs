using Exercise01.System.Diagnostics.Contracts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise01
{
    class SumProblem
    {
        /*
         * Variable SumSolution Object for the 
         * Solution Value
         */
        protected SumSolution solution = null;
        protected Node root = null;
        
        /*
         * Default Constructor creates a new Solution
         */
        public SumProblem(Node root)
        {
            this.root = root;
            solution = new SumSolution();
            GetSolution().SetSolutionValue(Sum(root));
        }

        /*
         * Getter for Solution
         * Returns a SumSolution Object
         */
        public SumSolution GetSolution()
        {
            return solution;
        }

        /*
         * Sum Method - Recursiv Call
         */
        protected int Sum(Node node)
        {
            /*
             * Check if Node is null and end of recursion
             */
            if (node == null)
            {
                return 0;
            }
            return node.GetValue() + Sum(node.GetLeft()) + Sum(node.GetRight());
        }
    }
}
