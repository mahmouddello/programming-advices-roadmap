using System;

namespace DateAndTime
{
    internal class Ticks
    {
        static void Main(string[] args)
        {

            //number of 100-nanosecond intervals that have elapsed
            //since January 1, 0001, at 00:00:00.000 in the Gregorian calendar. 

            DateTime dt = new DateTime();
            Console.WriteLine(DateTime.MinValue.Ticks);  //min value of ticks
            Console.WriteLine(DateTime.MaxValue.Ticks); // max value of ticks

            Console.WriteLine(dt);

            Console.ReadKey();
        }
    }
}

