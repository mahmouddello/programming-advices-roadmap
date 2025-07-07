using System;

namespace ControlFlow
{
    internal class WhileLoop
    {
        static void Main(string[] args)
        {

            int i = 1;
            while (i <= 5)
            {
                Console.WriteLine("C# while Loop: Iteration {0}", i);
                i++;
            }

            Console.ReadKey();

        }
    }
}
