using System;
using System.Threading;

namespace _20___Introduction_to_Multithreading
{
    public class ParameterizedThread
    {
        static void Main(string[] args)
        {
            // Note: The program is the main thread

            // Create a new thread and use a lambda expression to pass function with parameters (delegation)
            Thread t1 = new Thread(() => Method1("Thread1"));
            t1.Start();

            Thread t2 = new Thread(() => Method2("Thread2"));
            t2.Start();

            // Blocks the caller thread until these threads are done
            t1.Join();
            t2.Join();

            for (int i = 1; i <= 10; i++)
            {
                Console.WriteLine($"Main Thread: {i}");
                Thread.Sleep(500);
            }
        }

        private static void Method1(string threadName)
        {
            for (int i = 1; i <= 10; i++)
            {
                Console.WriteLine($"{threadName} Method 2: {i}");
                Thread.Sleep(500);
            }
        }

        private static void Method2(string threadName)
        {
            for (int i = 1; i <= 10; i++)
            {
                Console.WriteLine($"{threadName} Method 2: {i}");
                Thread.Sleep(500);
            }
        }
    }
}
