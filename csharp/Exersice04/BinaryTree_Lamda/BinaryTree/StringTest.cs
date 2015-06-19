using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace BinaryTree
{
    class StringTest : RandomGenerator
    // This class inherits from RandomGenerator to fill a given tree with random string values 
    {        
        BinaryTree.AbstractTree<string> stringTree;

        /// <summary>
        /// Constructor of StringTree, receives a tree
        /// </summary>
        /// <param name="floatTree">A BinaryTree of type String to operate on</param>
        public StringTest(BinaryTree.AbstractTree<string> stringTree)
        {
            this.stringTree = stringTree;            
        }

        /// <summary>
        /// This Method checks the given parameters and fills tha Tree-Object with random float values
        /// </summary>
        /// <param name="min">The min value</param>
        /// <param name="max">The max value</param>
        /// <param name="size">the amount of elements that the tree should be filled with</param>
        public void initTree(int min, int max, int size)
        {
            if (min > max)
            {
                TextWriter errorWriter = Console.Error;
                errorWriter.WriteLine("Minimum value must not be greater than the maximum value!");
                return;
            }
            if (size < 1)
            {
                TextWriter errorWriter = Console.Error;
                errorWriter.WriteLine("The Number of Items must not be smaller then 0!");
                return;
            }
            for (int i = 0; i < size; i++)
            {
                stringTree.insert(randomString(min, max));
            }
        }

        /// <summary>
        /// This Method prints the outputs of the filter method with different lambdas
        /// </summary>
        public void printTree()
        {
            Console.WriteLine("\nOutput of String-Tree :");
            Console.WriteLine("\nElements with a length greater/equal than 3: ");
            string[] smallerString = stringTree.Filter(items => items.Length >= 3);
            //Writes all matches on the console
            foreach (string item in smallerString)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("\nElements that contains 's': ");
            string[] matchString = stringTree.Filter(items => items.Contains("s"));
            //Writes all matches on the console
            foreach (string item in matchString)
            {
                Console.WriteLine(item);
            }
        }
    }
}
