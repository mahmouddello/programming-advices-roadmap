using System;
using System.Net;
using System.Threading.Tasks;

namespace _21___Introduction_to_Asynchronous_Programming
{
    public class TaskClassWithDelegates
    {
        delegate void DetailsDel(string x, string y);

        private static void PrintDownloadPretty(string url, string content)
        {
            Console.WriteLine($"URL: {url}\nDownloaded Characters: {content.Length}");
            Console.WriteLine(new string('-', 25));
            Console.WriteLine();
        }

        private static void PrintDownloadMessy(string url, string content)
        {
            Random rng = new Random();

            Console.WriteLine(url + " : ");

            for (int i = 0; i < 10; i++)
            {
                int start = rng.Next(0, Math.Max(1, content.Length - 50));
                int length = rng.Next(20, 80);

                string chunk = content.Substring(start, Math.Min(length, content.Length - start));
                Console.WriteLine(chunk);
            }
        }

        private static async Task Main(string[] args)
        {
            Console.WriteLine("Starting tasks...");

            Task task1 = DownloadAsync("https://programmingadvices.com", PrintDownloadPretty);
            Console.WriteLine("Task 1 started...");

            Task task2 = DownloadAsync("https://youtube.com", PrintDownloadPretty);
            Console.WriteLine("Task 2 started...");

            Task task3 = DownloadAsync("https://cnn.com", PrintDownloadMessy);
            Console.WriteLine("Task 3 started...\n");

            // Wait for all tasks to complete
            await Task.WhenAll(task1, task2, task3);

            Console.WriteLine("\nDone, all tasks finished execution.");
        }

        private static async Task DownloadAsync(string url, DetailsDel printOperation)
        {
            string content;

            using (WebClient webClient = new WebClient())
            {
                webClient.Headers.Add("User-Agent", "Mozilla/5.0");
                content = await webClient.DownloadStringTaskAsync(url);
            }

            printOperation(url, content);
        }
    }
}