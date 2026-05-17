using System;
using System.Net;
using System.Threading;

namespace _20___Introduction_to_Multithreading
{
    public class DownloadAndPrintsExample
    {
        static void Main(string[] args)
        {
            Thread t1 = new Thread(() => DownloadAndPrint("https://youtube.com"));
            t1.Start();
            Console.WriteLine("Thread 1 Started...");

            Thread t2 = new Thread(() => DownloadAndPrint("https://cnn.com"));
            t2.Start();
            Console.WriteLine("Thread 2 Started...");

            Thread t3 = new Thread(() => DownloadAndPrint("https://programmingadvices.com"));
            t3.Start();
            Console.WriteLine("Thread 3 Started...");

            Console.WriteLine();

            t1.Join();
            t2.Join();
            t3.Join();

            Console.WriteLine("\nAll threads finished");
        }

        public static void DownloadAndPrint(string url)
        {
            string content;

            using (WebClient webClient = new WebClient())
            {
                webClient.Headers.Add("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 Chrome/120 Safari/537.36");

                Thread.Sleep(100);
                content = webClient.DownloadString(url);
            }

            Console.WriteLine($"{url} finished downloading, total characters: {content.Length}");
        }
    }
}
