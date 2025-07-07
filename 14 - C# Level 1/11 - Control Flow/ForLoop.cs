using System;

namespace ControlFlow
{
    internal class ForLoop
    {
        static void Main(string[] args)
        {

            Console.WriteLine("\nForward For Loop:");
            //forward loop
            for (int i = 1; i <= 10; i++)
            {

                Console.WriteLine(i);

            }

            Console.WriteLine("\nBackword For Loop:");
            //backword loop
            for (int i = 10; i >= 1; i--)
            {

                Console.WriteLine(i);

            }

            Console.WriteLine("\nNested For Loops:");
            //forward loop
            for (int i = 1; i <= 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    Console.WriteLine("i={0} and j={1}", i, j);

                }
            }

            Console.ReadKey();

        }
    }
}
