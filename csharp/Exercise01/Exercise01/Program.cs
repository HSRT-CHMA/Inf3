using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics.Contracts;

namespace Exercise01
{

    namespace System.Diagnostics.Contracts
    {
        /*
         * Initial Start Program
         */
        class Program
        {
            static void Main(string[] args)
            {
                //Creating Binary Object with Values: 
                Console.WriteLine("Welcome ");
                BinaryTree tree = new BinaryTree(4);
                tree.Insert(3);
                tree.Insert(5);
                tree.Insert(-2);
                tree.Insert(33);
                Console.WriteLine("   " + tree.HasValue(3));
                Console.WriteLine("   " + tree.HasValue(5));
                Console.WriteLine("   " + tree.HasValue(199));
                Console.ReadLine();

                //Creating GPS Object with Values: 
                GPS pSolver = new GPS();
            }
        }
    }

}
