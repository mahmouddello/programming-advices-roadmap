using System;
using static System.Math;

namespace _06___using_Statement_in_C_
{
    internal class StaticDirectives
    {
        public static void Main(string[] args)
        {
            // using the class name Math
            double n = Sqrt(9);
            Console.WriteLine("Square root of 9 is " + n);
        }
    }
}
