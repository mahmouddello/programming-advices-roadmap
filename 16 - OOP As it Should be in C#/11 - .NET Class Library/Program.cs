using System;
using MyFirstClassLibrary;

namespace _11__.NET_Class_Library
{
    internal class Program
    {
        static void Main(string[] args)
        {
            MyMath myMath = new MyMath();

            Console.WriteLine(myMath.Sum(1, 2));
            Console.WriteLine(myMath.Sum(1, 2, 3));

            Console.WriteLine(myMath.Multiply(7, 6));
        }
    }
}
