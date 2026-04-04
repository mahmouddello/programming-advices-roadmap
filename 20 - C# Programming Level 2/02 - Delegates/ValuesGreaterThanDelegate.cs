using System;
using System.Collections.Generic;

namespace _02___Events
{
    internal class ValuesGreaterThanDelegate
    {
        delegate bool ComparisionDel(int x, int y);

        static void Main(string[] args)
        {

            List<int> list = new List<int>() { 1, 2, 4, 6, 10, 12, 15, 19 };

            var output = GetFilteredValues(list, 10, IsGreaterThan); // method name as third param

            Console.WriteLine("Values greater than 10:");
            foreach (var i in output)
                Console.Write($"{i} ");

            var output2 = GetFilteredValues(list, 10, IsLessThan);
            Console.WriteLine("\n\nValues less than 10:");
            foreach (var i in output2)
                Console.Write($"{i} ");

            Console.WriteLine();
        }

        static List<int> GetFilteredValues(List<int> list, int m, ComparisionDel operation)
        {
            List<int> result = new List<int>();

            foreach (int item in list)
            {
                if (operation(item, m))
                    result.Add(item);
            }

            return result;
        }

        private static bool IsLessThan(int x, int y)
        {
            return x < y;
        }

        private static bool IsGreaterThan(int x, int y)
        {
            return x > y;
        }

    }
}
