using System;

namespace _13___MathLibrary
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Max of 5, 10 is: {0}", Math.Max(5, 10));
            Console.WriteLine("Min of 5, 10 is: {0}", Math.Min(5, 10));
            Console.WriteLine("Square Root of 64 is: {0}", Math.Sqrt(64));
            Console.WriteLine("Absolute (positive) value of  -4.7 is: {0}", Math.Abs(-4.7));
            Console.WriteLine("Round of 9.99 is: {0}", Math.Round(9.99));
            Console.WriteLine($"Power of 2^5 = {Math.Pow(2, 5)}");
            Console.WriteLine($"Floor of 3.14 = {Math.Floor(3.14)}");
            Console.WriteLine($"Ceil of 3.14 = {Math.Ceiling(3.14)}");
            Console.WriteLine($"Sign of -20 = {Math.Sign(-20)}"); // -1 = negative
            Console.WriteLine($"Sign of 50 = {Math.Sign(50)}"); // 1 = positive

            Console.ReadKey();
        }
    }
}
