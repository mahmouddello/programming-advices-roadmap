using System;

namespace ControlFlow
{
    internal class BreakAndContinueStatements
    {
        static void Main(string[] args)
        {

            int i = 1;
            do
            {

                Console.WriteLine("C# while Loop: Iteration {0}", i);

                if (i == 3)
                    break;

                i++;

            } while (i <= 5);

            // continue
            for (int j = 1; j <= 5; ++j)
            {

                if (j == 3)
                {
                    continue;
                }

                Console.WriteLine(j);
            }

            Console.ReadKey();

        }
    }
}
