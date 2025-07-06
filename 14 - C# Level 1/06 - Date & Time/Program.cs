using System;

namespace DateAndTime
{
    internal class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine("Datetime MinValue = " + DateTime.MinValue);
            Console.WriteLine("Datetime MaxValue = " + DateTime.MaxValue);

            //assigns default value 01/01/0001 00:00:00
            DateTime dt1 = new DateTime();

            //assigns year, month, day
            DateTime dt2 = new DateTime(2023, 12, 31);

            //assigns year, month, day, hour, min, seconds
            DateTime dt3 = new DateTime(2023, 12, 31, 5, 10, 20);

            //assigns year, month, day, hour, min, seconds, UTC timezone
            DateTime dt4 = new DateTime(2023, 12, 31, 5, 10, 20, DateTimeKind.Utc);

            Console.WriteLine(dt1);
            Console.WriteLine(dt2);
            Console.WriteLine(dt3);
            Console.WriteLine(dt4);

            // you can get the current date time using :
            DateTime now = new DateTime();
            now = DateTime.Now;
            Console.WriteLine(now);

            Console.ReadKey();

        }
    }
}
