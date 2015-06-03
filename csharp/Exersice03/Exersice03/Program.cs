using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exersice03
{
    class Program
    {
        static void Main(string[] args)
        {

            Tree<string> tree = new BinaryTree<string>();
            AVLTree<int> avl = new AVLTree<int>();

            tree.Add("martin");
            tree.Add("özgün");
            tree.Add("los");
            tree.Add("ende");
            tree.Add("anfang");

            tree.inOrderOutput();
            Console.WriteLine();
            Console.WriteLine(tree.Contains("los"));

            tree.Remove("los");
            tree.inOrderOutput();
            Console.WriteLine();
            Console.WriteLine(tree.Contains("los"));

            Console.WriteLine();

            avl.Add(23);
            avl.Add(4);
            avl.Add(51);
            avl.Add(2);
            avl.Add(78);
            avl.Add(100);
            avl.Add(111);

            avl.inOrderOutput();
            Console.WriteLine();
            Console.WriteLine(avl.IsBanlance(avl.Root));
            Console.WriteLine();
            Console.WriteLine(avl.ReBanlance(avl.Root));

            avl.inOrderOutput();

            Console.WriteLine();
            Console.WriteLine(tree.GetHeight());
            Console.WriteLine();
            Console.WriteLine(avl.GetHeight());
            Console.WriteLine();
            Console.WriteLine(tree.GetDepth("anfang"));
            Console.WriteLine();
            Console.WriteLine(avl.GetDepth(78));




            Console.ReadLine();


        }
    }
}
