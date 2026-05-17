using System;
using System.Threading;

namespace _20___Introduction_to_Multithreading
{
    internal class RaceConditionExample
    {
        static int counter = 0;

        static void Increment()
        {
            for (int i = 0; i < 100000; i++)
            {
                counter++;
            }
        }
        
        static void Main(string[] args)
        {
            Thread t1 = new Thread(Increment);
            Thread t2 = new Thread(Increment);

            t1.Start();
            t2.Start();

            t1.Join();
            t2.Join();

            Console.WriteLine(counter); // 200000 is expected, but the result is incorrect due to race condition
        }
    }
}
