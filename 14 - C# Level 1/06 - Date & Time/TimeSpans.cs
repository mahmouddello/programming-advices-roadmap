using System;

namespace DateAndTime
{
    internal class TimeSpans
    {
        static void Main(string[] args)
        {

            DateTime dt = new DateTime(2023, 2, 21);

            // Hours, Minutes, Seconds
            TimeSpan ts = new TimeSpan(49, 25, 34);
            Console.WriteLine(ts);
            Console.WriteLine(ts.Days); // 2
            Console.WriteLine(ts.Hours); // 49 hours contains 2 days, so hours left are 1
            Console.WriteLine(ts.Minutes); // 25
            Console.WriteLine(ts.Seconds); // 34

            //this will add time span to the date.
            DateTime newDate = dt.Add(ts); // Add 2 days, 1 hour, 25 min and 34 seconds to (2023, 2, 21) : 12:00 AM

            Console.WriteLine(newDate);

            // Subtraction of two dates results in TimeSpan
            DateTime dt1 = new DateTime(2023, 2, 21);
            DateTime dt2 = new DateTime(2023, 2, 25);
            TimeSpan result = dt2.Subtract(dt1);

            Console.WriteLine(result);


            Console.ReadKey();

        }
    }
}
