using System;
using System.Diagnostics;
using System.Text;

namespace _17___String_Builder
{
    internal class Program
    {
        static void ConcatWithString(int iterations)
        {
            string result = "";

            for (int i = 0; i < iterations; i++)
                result += "a";
        }

        static void ConcatWithStringBuilder(int iterations)
        {
            StringBuilder stringBuilder = new StringBuilder();

            for (int i = 0; i < iterations; i++)
                stringBuilder.Append("a");

            string result = stringBuilder.ToString();
        }

        static void Main(string[] args)
        {
            int iterations = 300000;

            // Normal String
            Stopwatch stopwatch1 = new Stopwatch();
            stopwatch1.Start();
            ConcatWithString(iterations);
            stopwatch1.Stop();
            Console.WriteLine($"Total Time for normal string (Milliseconds): {stopwatch1.Elapsed.Milliseconds}");

            // String Builder
            Stopwatch stopwatch2 = new Stopwatch();
            stopwatch2.Start();
            ConcatWithStringBuilder(iterations);
            stopwatch2.Stop();
            Console.WriteLine($"Total Time for string builder (Milliseconds): {stopwatch2.Elapsed.Milliseconds}");
        }
    }
}
