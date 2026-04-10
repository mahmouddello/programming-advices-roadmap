using System;

namespace _04___More_About_Delegates.Multi_Cast_Delegate
{
    internal class MulticastDelegates
    {
        public delegate void MyDelegate(string message);

        static void Main()
        {
            MyDelegate myDelegate = Method1;
            myDelegate += Method2;


            myDelegate("Hello, world!");


            myDelegate -= Method1; // Unsubscribe
            myDelegate("Another message.");
        }

        static void Method1(string message)
        {
            Console.WriteLine("Method1: " + message);
        }

        static void Method2(string message)
        {
            Console.WriteLine("Method2: " + message);
        }
    }
}
