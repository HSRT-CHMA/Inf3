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
            //--------------------Float--------------------------------
            BinaryTree<float> floatTree = new BinaryTree<float>();
            FloatTest testFloatTree = new FloatTest(floatTree);
            testFloatTree.initTree(-10, 10, 50);
            testFloatTree.printTree();

            //---------------------String--------------------------------
            BinaryTree<string> stringTree = new BinaryTree<string>();
            StringTest testStringTree = new StringTest(stringTree);
            testStringTree.initTree(-10, 10, 50);
            testStringTree.printTree();        

            Console.ReadKey();
            /// Holds the command line open 
        }
    }
}
