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
                /*
                 * Create BinaryTree with Root 4
                 * and the Values: 3,5,-2,33
                 */
                BinaryTree tree = new BinaryTree(4);
                tree.Insert(3);
                tree.Insert(5);
                tree.Insert(-2);
                tree.Insert(33);

                /*
                 * Test of Has Method for the Values
                 * 3 -> true
                 * 5 -> true
                 * 199 -> false
                 */
                Console.WriteLine("   " + tree.HasValue(3));
                Console.WriteLine("   " + tree.HasValue(5));
                Console.WriteLine("   " + tree.HasValue(199));
                
                /*
                 * Test of Delete Method for the Value 5
                 * Has Method should now be false
                 */
                tree.DeleteAll(5);
                Console.WriteLine("   " + tree.HasValue(5));

                /*
                 * Test of GetSmallest and GetBiggest Method
                 * Smallest Value is -2
                 * Biggest Value is 33
                 */
                Console.WriteLine("   " + tree.GetBiggest().GetValue());
                Console.WriteLine("   " + tree.GetSmallest().GetValue());
                 
                
                /*
                 * That the console output is visible
                 */
                Console.ReadLine();

                /*
                 * Creating test for the General Problem Solver
                 */
                GPS pSolver = new GPS(tree);
            }
        }
    }

}
