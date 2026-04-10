using System;

namespace _05___Lambda_Expression
{
    internal class PGAdvices
    {
        static void Main(string[] args)
        {
            // Lambda Expression
            Action parameterLessAction = () => Console.WriteLine("This is a parameterless action");
            Action<int> actionWithIntParameter = (x) => Console.WriteLine($"I think you are {x} years old");
            Action<string, int> actionWithMultipleParameters = (x, y) => Console.WriteLine($"Hello {x}, {y} times!");

            parameterLessAction();
            actionWithIntParameter(23);
            actionWithMultipleParameters("Mahmoud", 23);
        }
    }
}
