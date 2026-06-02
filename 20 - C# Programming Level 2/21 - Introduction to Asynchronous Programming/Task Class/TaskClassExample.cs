using System;
using System.Threading.Tasks;

namespace _21___Introduction_to_Asynchronous_Programming
{
    public class TaskClassExample
    {
        private static async Task Main(string[] args)
        {
            // Create and run an asynchronous task
            Task<int> taskResult = PerformAsyncOperation();
            Console.WriteLine("Doing other work while performing calculation...");

            int result = await taskResult; // Wait for the task to complete and retrieve the result
            Console.WriteLine("Result = " + result);
        }

        private static async Task<int> PerformAsyncOperation()
        {
            // Simulate an asynchronous operation
            await Task.Delay(2000);

            // Return a result
            return 42;
        }
    }
}
