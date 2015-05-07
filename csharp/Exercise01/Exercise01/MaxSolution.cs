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
        protected int max;

        /*
         * Getter for Variable Max
         */
        public int GetMax()
        {
            return max;
        }

        /*
         * Setter for Variable Max
         * Return Value is Max
         */
        protected internal void SetMax(int max)
        {
            this.max = max;
        }
    }
}
