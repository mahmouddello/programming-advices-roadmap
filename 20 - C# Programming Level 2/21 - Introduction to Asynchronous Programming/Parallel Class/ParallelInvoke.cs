using System;
using System.Threading.Tasks;

namespace _21___Introduction_to_Asynchronous_Programming.Parallel_Class
{
    public class ParallelInvoke
    {
        static void Main(string[] args)
        {
            // Lambda Expressions
            Parallel.Invoke(
           () => Console.WriteLine($"Action 1 on thread {Task.CurrentId}"),
           () => Console.WriteLine($"Action 2 on thread {Task.CurrentId}"),
           () => Console.WriteLine($"Action 3 on thread {Task.CurrentId}")
           );

            // Regular Methods
            Console.WriteLine("Starting...\n");
            Parallel.Invoke(Function1, Function2, Function3);

            Console.WriteLine("\nAll methods finished execution!");
        }

        static void Function1()
        {
            Console.WriteLine("Starting Function1...");
            Task.Delay(1000).Wait();
            Console.WriteLine("Function1 finished!");
        }

        static void Function2()
        {
            Console.WriteLine("Starting Function2...");
            Task.Delay(1000).Wait();
            Console.WriteLine("Function2 finished!");
        }

        static void Function3()
        {
            Console.WriteLine("Starting Function3...");
            Task.Delay(1000).Wait();
            Console.WriteLine("Function3 finished!");
        }
    }
}
