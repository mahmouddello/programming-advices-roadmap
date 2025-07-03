using System;

namespace Datatypes
{
    internal class Enums
    {
        /*
            enums : Enums in C# is the Same as C++
            however you can specify a type for Enum :-)
            see the code to understand them.
         */
        enum enWeekDays
        {
            Monday,     // 0
            Tuesday,    // 1
            Wednesday,  // 2
            Thursday,   // 3
            Friday,     // 4
            Saturday,   // 5
            Sunday      // 6
        }

        //if you set a value , it will auto number everything after it.
        enum enCategories
        {
            Electronics,    // 0
            Food,           // 1
            Automotive = 6, // 6
            Arts,           // 7
            BeautyCare,     // 8
            Fashion         // 9
        }

        enum enCategories2 : byte
        {
            Electronics = 1,
            Food = 5,
            Automotive = 6,
            Arts = 10,
            BeautyCare = 11,
            Fashion = 15
        }

        //Enum can have any numarical data type byte, sbyte, short, ushort, int, uint, long, or ulong
        //but not string
        static void Main(string[] args)
        {
            Console.WriteLine("\n--------- Enums ------------\n");
            enWeekDays WeekDays;

            WeekDays = enWeekDays.Friday;
            Console.WriteLine(WeekDays);
            string day = Enum.GetName(typeof(enWeekDays), 2); // "Wednesday"
            Console.WriteLine(day);

            enWeekDays WeekDays2 = enWeekDays.Thursday;
            Console.WriteLine((int)WeekDays2);//3

            Console.ReadKey();
        }
    }
}
