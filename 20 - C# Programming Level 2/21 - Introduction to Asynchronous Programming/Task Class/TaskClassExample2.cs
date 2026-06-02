using System;
using System.Diagnostics;
using System.Net;
using System.Threading.Tasks;

namespace _21___Introduction_to_Asynchronous_Programming
{
    public class TaskClassExample2
    {
        static async Task Main(string[] args)
        {
            Stopwatch stopwatch = Stopwatch.StartNew();
            Console.WriteLine("Starting tasks...");

            Task task1 = DownloadAndPrintAsync("https://cnn.com");
            Console.WriteLine("Task 1 Started");

            Task task2 = DownloadAndPrintAsync("https://amazon.com.tr");
            Console.WriteLine("Task 2 Started");

            Task task3 = DownloadAndPrintAsync("https://harmash.com");
            Console.WriteLine("Task 3 Started");

            Console.WriteLine();

            // Wait for all tasks to finish
            Task.WaitAll(task1, task2, task3);
            stopwatch.Stop();

            Console.WriteLine($"\nDone, all tasks finished execution\nTime consumed in seconds: {stopwatch.ElapsedMilliseconds / 1000.0}");
        }

        static async Task DownloadAndPrintAsync(string url)
        {
            string content;

            using (WebClient client = new WebClient())
            {
                // Simulate somework by adding a 1ms delay
                await Task.Delay(100);

                // Download the content of the webpage aynchronously
                content = await client.DownloadStringTaskAsync(url);
            }

            Console.WriteLine($"{url}: {content.Length} characters downloaded");
        }
    }
}
