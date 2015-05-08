using Exercise01.System.Diagnostics.Contracts;
using System;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise01
{
    class MaxProblem
    {
        /*
         * Variable MaxSolution Object
         */
        protected MaxSolution solution = null;
        protected Node root = null;

        /*
         * Default Constructor creates a new Problem Object
         */
        public MaxProblem(Node root)
        {
            this.root = root;
            solution = new MaxSolution();
            GetSolution().SetSolutionValue(Max(root));

        }

        /*
         * Max Method which detects the biggest Value
         * of the BinaryTree
         */
        protected int Max(Node node)
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

        /*
         * Getter for Solution
         * Returns a MaxSolution Object
         */
        public MaxSolution GetSolution()
        {
            return solution;
        }
    }
}
