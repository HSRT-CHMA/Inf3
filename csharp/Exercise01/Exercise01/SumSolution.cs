using Exercise01.System.Diagnostics.Contracts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise01
{
    class SumSolution
    {
        /*
         * Variable of Sum Value
         */
        protected int sum;

        /*
         * Getter for Sum Value
         */
        public int GetSum()
        {
            return sum;
        }

        /*
         * Setter for Sum Value
         * Return Value is Sum
         */
        protected internal void SetSum(int sum)
        {
            this.sum = sum;
        }
    }
}
