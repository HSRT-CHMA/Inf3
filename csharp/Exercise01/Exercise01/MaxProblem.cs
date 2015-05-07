using Exercise01.System.Diagnostics.Contracts;
using System;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise01
{
    class MaxProblem : DivisibleProblem<MaxSolution>
    {
        /*
         * Variable MaxSolution Object
         */
        protected MaxSolution solution;

        /*
         * Default Constructor creates a new Problem Object
         */
        public MaxProblem()
        {
            solution = new MaxSolution();

        }
        /*
         * Overwritten Method
         */
        public override void checkSolvable(Node node)
        {
            int max = 0;

            if (node.GetRight() == null && node.GetLeft() == null)
            {
                /*
                 * If there are no nodes, Root will be the Maximum Value
                 */
                directlySolvable = true;
                max = node.GetValue();
                solution.SetMax(max);
            }
        }
        protected override int Max(Node node)
        {
            int max = node.GetValue();

            if (node.GetLeft() != null)
            {
                max = Math.Max(max, Max(node.GetLeft()));
            }
            if (node.GetRight() != null)
            {
                max = Math.Max(max, Max(node.GetRight()));
            }
            return max;
        }

        public override MaxSolution GetSolution()
        {
            return solution;
        }
    }
}
