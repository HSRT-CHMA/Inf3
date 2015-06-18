using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace BinaryTree
    //Shared namespace
{
    class FloatTest : RandomGenerator
        // This class inherits from RandomGenerator to fill a given tree with random float values 
    {
        BinaryTree.AbstractTree<float> floatTree;

        /// <summary>
        /// Constructor of FloatTest, receives a tree
        /// </summary>
        /// <param name="floatTree">A BinaryTree of type float to operate on</param>
        public FloatTest(BinaryTree.AbstractTree<float> floatTree)
        {
            this.floatTree = floatTree;
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
                floatTree.insert(randomFloat(min, max));
            }
        }

        /// <summary>
        /// This Method prints the outputs of the filter method with different lambdas
        /// </summary>
        public void printTree()
        {
            Console.WriteLine("\nOutput of Float-Tree :");
            Console.WriteLine("\nSmaller 5: ");
            float[] smaller = floatTree.Filter(items => items <= 5);
            foreach(float item in smaller) {
                Console.WriteLine(item);
            }
            Console.WriteLine("\nNegativ: ");
            float[] negativ = floatTree.Filter(items => items < 0);
            foreach (float item in negativ)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("\nEven: ");
            float[] even = floatTree.Filter(items => items % 2 == 0);
            foreach (float item in even)
            {
                Console.WriteLine(item);
            }  
        }
    }
}
