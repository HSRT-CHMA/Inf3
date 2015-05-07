using Exercise01.System.Diagnostics.Contracts;
using System;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise01
{
    class MaxProblem : DivisibleProblem
    {
        private MaxSolution solution = null;
        private Node root = null;

        public MaxProblem()
        {
            Contract.Assert(solution == null);
            solution = new MaxSolution();
            Contract.Assert(solution != null);
        }



    }
}
