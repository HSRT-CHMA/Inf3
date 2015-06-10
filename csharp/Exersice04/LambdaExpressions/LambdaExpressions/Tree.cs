using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestBaum
{
    /// Tree data structure
    abstract class Tree<T>
        where T : IComparable
    {


        /// abstract method Add dont have a return v
        /// <param name="Value"></param>
        public abstract void Add(T Value);


        /// avtract method Contains returns a bool
        /// <param name="Value"></param>
        /// <returns></returns>
        public abstract bool Contains(T Value);


        /// abstract method Remove returns a bool
        /// <param name="Value"></param>
        /// <returns></returns>
        public abstract bool Remove(T Value);
    }
}