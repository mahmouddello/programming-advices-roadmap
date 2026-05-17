using System;
using System.Threading;

namespace _20___Introduction_to_Multithreading
{
    internal class SynchronizationExample
    {
        static int sharedCounter = 0;
        static object lockObj = new object();

        static void Main(string[] args)
        {
            Thread t1 = new Thread(() => IncrementCounter("T1"));
            Thread t2 = new Thread(() => IncrementCounter("T2"));

            t1.Start();
            t2.Start();

            // Wait for both threads to finish
            t1.Join();
            t2.Join();


            Console.WriteLine($"Final Counter Value = {sharedCounter}");
        }

        static void IncrementCounter(string threadName)
        {
            for (int i = 0; i < 100; i++)
            {
                // Use lock to synchronize access to the shared counter
                lock (lockObj)
                {
                    sharedCounter++;
                    Console.WriteLine($"Thread {threadName} | Counter Value: {sharedCounter}");
                }
            }
        }
    }
}
