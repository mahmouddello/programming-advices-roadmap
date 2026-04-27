using System;

namespace _13___Generics
{
    public class Utility
    {
        public static void Swap<T>(ref T first, ref T second)
        {
            T temp = first;
            first = second;
            second = temp;
        }
    }

    public class GenericMethods
    {
        static void Main()
        {
            // Usage with integers
            int a = 5, b = 10;
            Console.WriteLine($"Before swap: a = {a}, b = {b}");
            Utility.Swap(ref a, ref b);
            Console.WriteLine($"After swap: a = {a}, b = {b}");
            Console.WriteLine();


            // Usage with strings
            string x = "Hello", y = "World";
            Console.WriteLine($"Before swap: x = {x}, y = {y}");
            Utility.Swap(ref x, ref y);
            Console.WriteLine($"After swap: x = {x}, y = {y}");
        }
    }
}
