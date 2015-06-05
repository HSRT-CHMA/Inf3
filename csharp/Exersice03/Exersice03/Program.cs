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

            BinaryTree<string> tree = new BinaryTree<string>();

            tree.Add("martin");
            tree.Add("özgün");
            tree.Add("los");
            tree.Add("ende");
            tree.Add("anfang");

            tree.inOrder();
            Console.WriteLine();
            Console.WriteLine("The height of the Binary Tree is: " + tree.GetHeight());
            Console.WriteLine();
            Console.WriteLine(tree.Contains("özgün"));
            tree.Remove("özgün");
            tree.inOrder();
            Console.WriteLine();
            Console.WriteLine(tree.Contains("özgün"));


            Console.WriteLine();
            Console.WriteLine();

            
          

            AVLTree<int> avl = new AVLTree<int>();

            for (int i = 0; i < 5; i++)
            {
                avl.Add(IntegerRandomizer());
            }
            /*avl.Add(14);
            avl.Add(4);
            avl.Add(62);
            avl.Add(2);
            avl.Add(89);
            avl.Add(100);
            avl.Add(111);*/

            Console.WriteLine();
            avl.inOrder();
            Console.WriteLine();
            Console.WriteLine("The not rotatet Tree has the height: " + avl.GetHeight());
            Console.WriteLine();
            avl.BalanceTree(avl.Root);
            Console.WriteLine("The rotatet Tree has the height: " + avl.GetHeight());
            Console.WriteLine();
            Console.ReadLine();


        }
    }
}
