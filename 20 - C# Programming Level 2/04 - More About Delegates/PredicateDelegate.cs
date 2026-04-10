using System;

namespace _04___More_About_Delegates
{
    internal class PredicateDelegate
    {
        // Define a Func delegate for squaring a number
        static Predicate<int> IsEvenPredicate = IsEven;

        // Define a method that squares a number
        static bool IsEven(int x)
        {
            return (x % 2 == 0);
        }

        static void Main()
        {
            // Use the IsEven Func to square the number 5
            bool result = IsEvenPredicate(5);

            // Print the result
            Console.WriteLine("Is Number 5  Even ?  " + result);
            Console.ReadKey();

        }
    }
}
