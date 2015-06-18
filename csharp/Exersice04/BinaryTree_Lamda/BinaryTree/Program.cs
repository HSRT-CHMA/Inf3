using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryTree
{
    /// <summary>
    /// Class contains Main-Method 
    /// </summary>
    class Program
    {
        static void Main(string[] args)
        {            
            BinaryTree<float> floatTree = new BinaryTree<float>();
            FloatTest testFloatTree = new FloatTest(floatTree);
            testFloatTree.initTree(-10, 10, 20);
            testFloatTree.printTree();


            BinaryTree<string> stringTree = new BinaryTree<string>();
            StringTest testStringTree = new StringTest(stringTree);
            testStringTree.initTree(5, 10, 10);
            testStringTree.printTree();        

            Console.ReadKey();
            /// Holds the command line open 
        }
    }
}
