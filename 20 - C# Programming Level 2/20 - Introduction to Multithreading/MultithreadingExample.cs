using System;
using System.Threading;

namespace _20___Introduction_to_Multithreading
{
    internal class MultithreadingExample
    {
        static void Main(string[] args)
        {
            // Note that your program is the main thread.

            // Create a new thread and start it
            Thread t = new Thread(ThreadMethod1);
            t.Start();


            // Main thread continues its execution
            for (int i = 1; i <= 20; i++)
            {
                Console.WriteLine("Main Thread: " + i);
                Thread.Sleep(1000); // Sleep for 1 second
            }
            Console.ReadKey();
        }

        private static void ThreadMethod1()
        {
            for (int i = 1; i <= 10; i++)
            {
                Console.WriteLine("Thread Method1: " + i);
                Thread.Sleep(1000);
            }
        }
    }
}
