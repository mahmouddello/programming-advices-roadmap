using System;
using System.Threading.Tasks;

namespace _21___Introduction_to_Asynchronous_Programming.Parallel_Class
{
    public class ParallelFor
    {
        static void Main(string[] args)
        {
            int numberOfIterations = 10;

            // Use Parallel.For to execute loop in Parallel
            Parallel.For(0, numberOfIterations, i =>
            {
                Console.WriteLine($"Executing itreation {i} on thread {Task.CurrentId}");
            });

            // Use Parallel.For to execute loop in Parallel
            Parallel.For(0, numberOfIterations, ProcessIteration);

            Console.WriteLine("All iterations completed!");
        }

        private static void ProcessIteration(int obj)
        {
            Console.WriteLine($"Executing iteration obj {obj} on thread {Task.CurrentId}");
        }
    }
}
