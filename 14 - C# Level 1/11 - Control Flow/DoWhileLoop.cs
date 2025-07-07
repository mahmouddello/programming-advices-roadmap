using System;

namespace ControlFlow
{
    internal class DoWhileLoop
    {
        static void Main(string[] args)
        {

            int i = 1;
            do
            {
                Console.WriteLine("C# do while Loop: Iteration {0}", i);
                i++;

            } while (i <= 5);

            Console.ReadKey();
        }
    }
}
