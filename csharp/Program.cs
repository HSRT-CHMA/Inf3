using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Excersice1
    {

        private static double[] original;
        private static double sum;
        private static double average;
        private static double[] reverseList;
        private static double[] sortedList;
        private static double[] palindrome;


        /*
         * This method receives a string array, content of which is specified via
         * Run > Run Configurations > Arguments, and modify it by calling all other
         * methods. Main-Method can be written with or without string[]- parameter which 
         * contains Comandlinearguments. Those can be choosen in Projektmappen-Explorer > 
         * Properties > Debuggen > Befehlszeilenargumente 
         * 
         * @param args
         *            String-Array of arguments
         */
        static void Main(string[] args)
        {

            original = Modify(args);
            Console.WriteLine("Original List : ");
            PrintArray(original);
            sum = SumOfNumbers(original);
            Console.WriteLine("\nSum : " + sum);
            average = Average(original);
            Console.WriteLine("Average : " + average);
            reverseList = Reverse(original);
            Console.WriteLine("Reverse : ");
            PrintArray(reverseList);
            palindrome = Palindrome(original);
            Console.WriteLine("\nPalindrome : ");
            PrintArray(palindrome);
            sortedList = Sort(original);
            Console.WriteLine("\nSorted List : ");
            PrintArray(sortedList);
        }



        /*
         * This method casts a string array into a double array by changing letters
         * into ASCII-values and sum them
         * 
         * @param args
         *            String-Array of arguments
         * @return result double-Array of modified arguments
         */
        public static double[] Modify(string[] args)
        {
            double[] result = new double[args.Length];

            for (int i = 0; i < args.Length; i++)
            {
                string word = args[i];
                double ascii = 0;
                int start = 0;
                int length = 1;

                while (start < word.Length)
                {
                    string letter = word.Substring(start, length);

                    if (!(letter.Equals("0") | letter.Equals("1")
                        | letter.Equals("2") | letter.Equals("3")
                        | letter.Equals("4") | letter.Equals("5")
                        | letter.Equals("6") | letter.Equals("7")
                        | letter.Equals("8") | letter.Equals("9") | letter.Equals(".") | letter.Equals("+") | letter.Equals("-") | letter.Equals(",")))
                    {
                        char[] oneLetter = letter.ToCharArray();
                        int res = (int)oneLetter[0];
                        ascii += res;  
                        args[i] = System.Convert.ToString(ascii);
                    }

                    result[i] = Double.Parse(args[i]);
                    start++;
                }
            }
            return result;
        }

        /*
        * This method prints a given array
        * 
        * @param numbers
        *            double array
        */
        public static void PrintArray(double[] numbers)
        {
            for (int i = 0; i < numbers.Length; i++)
            {
                Console.Write(numbers[i] + " | ");
            }
        }


        /*
         * This method returns the sum of a given array
         * 
         * @param numbers
         *            double array
         * @return sum The sum of numbers
         */
        public static double SumOfNumbers(double[] numbers)
        {
            double sum = 0;
            for (int i = 0; i < numbers.Length; i++)
            {
                sum += numbers[i];
            }

            return sum;
        }


        /*
         * This method returns the average of all digits in a given array
         * 
         * @param numbers
         *            double array
         * @return average The average-value of numbers
         */
        public static double Average(double[] numbers)
        {
            double s = SumOfNumbers(numbers);
            double average = s / numbers.Length;
            return average;
        }


        /*
         * This method reverses a given array
         * 
         * @param numbers
         *            double array
         * @return reverse The reversed array of numbers
         */
        public static double[] Reverse(double[] numbers)
        {
            double[] reverse = new double[numbers.Length];
            int index = numbers.Length;
            for (int i = 0; i < numbers.Length; i++)
            {
                index--;
                reverse[i] = numbers[index];
            }
            return reverse;
        }

        /*
         * This method sorts a given array by using bubblesort
         * 
         * @param numbers
         *            double array
         * @return numbers The sorted version of numbers
         */
        public static double[] Sort(double[] numbers)
        {
            double tmp = 0;
            for (int n = numbers.Length; n > 1; n--)
            {
                for (int i = 0; i < n - 1; i++)
                {
                    if (numbers[i] > numbers[i + 1])
                    {
                        tmp = numbers[i];
                        numbers[i] = numbers[i + 1];
                        numbers[i + 1] = tmp;
                    }
                }
            }
            return numbers;
        }

        /**
         * This method creates a palindrome of a given array
         * 
         * @param numbers
         *            double array
         * @return result The palindrome of numbers
         */
        public static double[] Palindrome(double[] numbers)
        {
            double[] result = new double[numbers.Length * 2];
            double[] rev = new double[numbers.Length];
            rev = Reverse(numbers);
            int index = 0;

            for (int i = 0; i < numbers.Length; i++)
            {
                result[i] = numbers[i];
            }

            for (int i = numbers.Length; i < result.Length; i++)
            {
                result[i] = rev[index];
                index++;
            }

            return result;

        }





    }
}
