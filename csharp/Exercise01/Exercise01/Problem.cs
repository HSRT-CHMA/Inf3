using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise01
{
    abstract class Problem<Solution>
    {
        /*
         * Abstract Method from the abstract
         * Class Problem with the Return
         * Parameter Solution
         */
        public abstract Solution GetSolution();
    }
}
