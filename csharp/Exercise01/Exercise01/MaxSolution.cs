using Exercise01.System.Diagnostics.Contracts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise01
{
    class MaxSolution
    {
        /*
         * Variable for Maximum Value
         */
        protected int solutionValue;
        /*
         * Getter for Variable Max
         */
        public int GetMax()
        {
            return solutionValue;
        }

        /*
         * Setter for Variable Max
         * Return Value is Max
         */
        public void SetSolutionValue(int solutionValue)
        {
            this.solutionValue = solutionValue;
        }
    }
}
