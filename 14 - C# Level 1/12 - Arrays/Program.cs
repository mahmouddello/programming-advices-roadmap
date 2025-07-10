using System;
using System.Linq;

namespace Arrays
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // declare an array, and allocate memory (heap)
            int[] age = new int[5];

            // Array Initialization 
            int[] numbers = { 1, 2, 3, 4, 5 }; // C# automatically specifies the size

            // Element Access

            //access first element
            Console.WriteLine("Element in first index : " + numbers[0]);

            //access second element
            Console.WriteLine("Element in second index : " + numbers[1]);

            //access third element
            Console.WriteLine("Element in third index : " + numbers[2]);

            //through loop
            Console.WriteLine("\nAccess array using loop:\n");
            for (int i = 0; i < numbers.Length; i++)
            {
                Console.WriteLine("Element in index {0} : {1} ", i, numbers[i]);
            }

            //initializing 2D array
            int[,] numbers2D = { { 12, 13 }, { 55, 77 } };

            // access first element from the first row
            Console.WriteLine("Element at index [0, 0] : " + numbers2D[0, 0]);

            // access first element from second row
            Console.WriteLine("Element at index [1, 0] : " + numbers2D[1, 0]);

            char[] gender = { 'm', 'f', 'm', 'm', 'm', 'f', 'f', 'm', 'm', 'f' };
            int male = 0, female = 0;

            foreach (char g in gender)
            {
                if (g == 'm')
                    male++;
                else if (g == 'f')
                    female++;
            }

            Console.WriteLine("Number of male = {0}", male);
            Console.WriteLine("Number of female = {0}", female);

            char[] myArray = { 'H', 'e', 'l', 'l', 'o' };

            foreach (char ch in myArray)
            {
                Console.WriteLine(ch);
            }

            // LINQ Operations

            // get the minimum element
            Console.WriteLine("Smallest  Element: " + numbers.Min());

            // Max() returns the largest number in array
            Console.WriteLine("Largest Element: " + numbers.Max());


            // compute Count
            Console.WriteLine("Count : " + numbers.Count());

            // compute Sum
            Console.WriteLine("Sum : " + numbers.Sum());

            // compute the average
            Console.WriteLine("Average: " + numbers.Average());

            Console.ReadKey();
        }
    }
}
