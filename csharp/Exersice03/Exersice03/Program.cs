using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System;
using System.Security.Cryptography;

namespace TestBaum
{
    class Program
    {
        static Random rnd = new Random();
        /// creates random values from the whole Integerspace
        private static int IntegerRandomizer()
        {
            int value = rnd.Next(0, 1000);
            return value;
        }

        public static string RandomString(int maxSize)
        {
            char[] chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890".ToCharArray();
            byte[] data = new byte[1];
            RNGCryptoServiceProvider crypto = new RNGCryptoServiceProvider();
            crypto.GetNonZeroBytes(data);
            data = new byte[maxSize];
            crypto.GetNonZeroBytes(data);
            StringBuilder result = new StringBuilder(maxSize);
            foreach (byte b in data)
            {
                result.Append(chars[b % (chars.Length - 1)]);
            }
            return result.ToString();
        }

        static void Main(string[] args)
        {

            BinaryTree<string> tree = new BinaryTree<string>();

            /*for (int i = 0; i < 5; i++)
            {
                tree.Add(RandomString(IntegerRandomizer()));
            }*/

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


            Console.WriteLine("__________________________________________________________________________");

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
