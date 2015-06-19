using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryTree
{
    class RandomGenerator
    {

        Random ra = new Random();
        //Random-Object for Generation random values


        /// <summary>
        /// The Method generates a random String by using 2 random values for looping and indexing
        /// </summary>
        /// <param name="min">The smallest value for Generating</param>
        /// <param name="max">The greatest value for Generating</param>
        /// <returns>A randomly generated String</returns>
        protected String randomString(int min, int max)
        {

            String content = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
            int raCounter = ra.Next(1, max + 1);

            String raString = "";

            for (int i = 0; i <= raCounter; i++)
            {
                int raIndex = randomInteger(0, content.Length);
                raString += content[raIndex];

            }
            return raString;
        }

        /// <summary>
        /// This Method generates a random int value between two received values and returns it
        /// </summary>
        /// <param name="min">The smallest value for Generating</param>
        /// <param name="max">The greatest value for Generating</param>
        /// <returns>Random int value</returns>
        protected int randomInteger(int min, int max)
        {
            return ra.Next(min, max);
        }


        /// <summary>
        /// This Method generates a random float value between two received values, 
        /// rounds it up and returns it
        /// </summary>
        /// <param name="min">The smallest value for Generating</param>
        /// <param name="max">The greatest value for Generating</param>
        /// <returns>Random float value</returns>
        protected float randomFloat(int min, int max)
        {
            float rand = randomInteger(min, max);
            rand += (float)ra.NextDouble();
            float roundRa = (float)Math.Round(rand, 3);
            return roundRa;
        }
    }
}
