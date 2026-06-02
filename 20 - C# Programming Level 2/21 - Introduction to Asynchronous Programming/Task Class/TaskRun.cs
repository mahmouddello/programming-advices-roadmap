using System;
using System.Threading;
using System.Threading.Tasks;
namespace _21___Introduction_to_Asynchronous_Programming
{
    internal class TaskRun
    {
        static async Task Main(string[] args)
        {
            // Define long-running tasks
            Task task1 = Task.Run(() => DownloadFile("Downloading File 1"));

            Task task2 = Task.Run(() => DownloadFile("Downloading File 2"));

            // Wait for both tasks to finish
            await Task.WhenAll(task1, task2);

            // Display execution time for each task
            Console.WriteLine($"Task 1 and 2 completed");
            Console.ReadKey();

        }

        static void DownloadFile(string TaskName)
        {
            Console.WriteLine($"{TaskName}: Started!");
            Thread.Sleep(5000); // Simulate long-running operation
            Console.WriteLine($"{TaskName}: Completed!");
        }
    }
}
