using System;
using System.Collections.Generic;
using System.Net;
using System.Threading;
using System.Threading.Tasks;

namespace _21___Introduction_to_Asynchronous_Programming.Parallel_Class
{
    public class ParallelForEach
    {
        static List<string> urls = new List<string>
        {
                "https://ProgrammingAdvices.com",
                "https://Amazon.com.tr",
                "https://CNN.com"
        };

        static void Main(string[] args)
        {
            // Use Parallel.ForEach to download the webpages concurrenctly
            Parallel.ForEach(urls, url => DownloadContent(url));

            Console.WriteLine("\nDone!");
        }

        private static void DownloadContent(string url)
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
