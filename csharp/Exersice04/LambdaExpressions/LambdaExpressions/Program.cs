using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestBaum
{
    class Program
    {
        static Random rnd = new Random();
        /// creates random values from the whole Integerspace
        private static int IntegerRandomizer()
        {
            int value = rnd.Next(int.MinValue, int.MaxValue);
            return value;
        }

        static void Main(string[] args)
        {

            //-------------------------------------------------------------------------------------------------------------------------------------------
            
            BinaryTree<string> tree = new BinaryTree<string>();
            //Creation of String Binary Tree

            tree.Add("bcde");
            tree.Add("bc");
            tree.Add("bcd");
            tree.Add("defg");
            tree.Add("g");
            tree.Add("def");
            tree.Add("ghij");
            tree.Add("ah");
            tree.Add("ijkl");
            tree.Add("jk");
            tree.Add("a");

            tree.inOrder();
            Console.WriteLine();
            Console.WriteLine("The height of the Binary Tree is: " + tree.GetHeight());
            Console.WriteLine();
            Console.WriteLine(tree.Contains("g"));
            tree.Remove("g");
            tree.inOrder();
            Console.WriteLine();
            Console.WriteLine(tree.Contains("g"));

            //-------------------------------------------------------------------------------------------------------------------------------------------

            BinaryTree<string> treeV = new BinaryTree<string>("e");
            //Creation of String Binary Tree

            treeV.Add("bcde");
            treeV.Add("bc");
            treeV.Add("bcd");
            treeV.Add("defg");
            treeV.Add("ge");
            treeV.Add("def");
            treeV.Add("ghij");
            treeV.Add("ah");
            treeV.Add("ijkl");
            treeV.Add("jk");
            treeV.Add("a");

            treeV.inOrder();
            Console.WriteLine();
            Console.WriteLine("The height of the Binary Tree is: " + treeV.GetHeight());
            Console.WriteLine();
            Console.WriteLine(treeV.Contains("ge"));
            treeV.Remove("ge");
            treeV.inOrder();
            Console.WriteLine();
            Console.WriteLine(treeV.Contains("ge"));

            //-------------------------------------------------------------------------------------------------------------------------------------------

            BinaryTree<int> treeI = new BinaryTree<int>(30);

            treeI.Add(20);
            treeI.Add(40);
            treeI.inOrder();

            BinaryTree<double> treeD = new BinaryTree<double>(5.3);

            treeD.Add(6.89);
            treeD.Add(9.5);
            treeD.inOrder();

            //BinaryTree<float> treeF = new BinaryTree<float>(5.5);



            //-------------------------------------------------------------------------------------------------------------------------------------------
            
            
            Console.Read();
            //Holds the command line open



        }
    }
}