using System;

namespace _04___More_About_Delegates.Func_Delegate
{
    internal class FuncDelegate
    {
        static readonly Func<int, int> square = Square;

        private static int Square(int x)
        {
            return x * x;
        }

        static void Main(string[] args)
        {
            int result = square(5);
            Console.WriteLine($"The square of 5 = {result}");

            Console.ReadLine();
        }
    }
}