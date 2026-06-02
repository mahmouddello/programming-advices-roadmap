using System;
using System.Diagnostics;
using System.Threading.Tasks;

namespace _21___Introduction_to_Asynchronous_Programming.Parallel_Class
{
    internal class RegularForVsParallelFor
    {
        static void Main(string[] args)
        {
            int numberOfIteration = 1000000;
            Stopwatch sw = new Stopwatch();

            Console.WriteLine("Calculation Starting ");

            // -- Using Regular for loop --//
            sw.Start();
            for (int i = 0; i < numberOfIteration; i++)
            {
                double d = 0;
                for (int j = 0; j < 500; j++)
                {
                    d += Math.Exp(Math.Log(i + 1) / (j + 1));
                }
            }
            sw.Stop();
            long ElapsedTimeForRegularLoop = sw.ElapsedMilliseconds;

            sw.Reset();

            // -- Using Parallel for loop --//
            sw.Start();
            Parallel.For(0, numberOfIteration, i =>
            {
                double d = 0;
                for (int j = 0; j < 500; j++)
                {
                    d += Math.Exp(Math.Log(i + 1) / (j + 1));
                }
            });

            sw.Stop();
            long ElapsedTimeForParallelLoop = sw.ElapsedMilliseconds;
            sw.Reset();

            Console.WriteLine($"The Elapsed Time using regular for loop : {ElapsedTimeForRegularLoop}");
            Console.WriteLine($"The Elapsed Time Parallel for loop : {ElapsedTimeForParallelLoop}");
            Console.ReadKey();
        }
    }
}
