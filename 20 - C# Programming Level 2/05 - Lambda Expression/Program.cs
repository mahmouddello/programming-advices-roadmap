using System;

namespace _05___Lambda_Expression
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Initiaing a delegate using named method (functions)
            Func<int, int> square = SquareMethod;
            Console.WriteLine(square(5));

            // Delegate getting assigned to an Anonymous function
            Func<int, int> square2 = delegate (int x) { return x * x; };
            Console.WriteLine(square2(5));

            // Delegate getting assigned to a lambda expression
            Func<int, int> square3 = (int x) => x * x;
            Console.WriteLine(square3(5));
        }

        static int SquareMethod(int x)
        {
            return x * x;
        }
    }
}
