using Exercise01.System.Diagnostics.Contracts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise01
{
    class SumProblem : DivisibleProblem<SumSolution>
    {
        /*
         * Variable SumSolution Object for the 
         * Solution Value
         */
        protected SumSolution solution;

        /*
         * Default Constructor creates a new Solution
         */
        public SumProblem()
        {
            solution = new SumSolution();
        }

        public override void CheckSolvable(Node node)
        {
            int sum = 0;

            if (node.GetRight() == null && node.GetLeft() == null)
            {
                directlySolvable = true;
                sum = node.GetValue();
                solution.SetSum(node.GetValue());
            }
        }

        /*
         * Getter for Solution
         * Returns a SumSolution Object
         */
        public override SumSolution GetSolution()
        {
            return solution;
        }

        /*
         * Sum Method - Recursiv Call
         */
        protected override int Sum(Node node)
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
