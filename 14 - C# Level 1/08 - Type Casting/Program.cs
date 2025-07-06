using System;
using System.Security.Policy;

namespace TypeCasting
{
    internal class Program
    {

        enum WeekDays
        {
            Monday,
            Tuesday,
            Wednesday,
            Thursday,
            Friday,
            Saturday,
            Sunday
        }

        static void Main(string[] args)
        {
            // Implicit Casting is done automatically when passing a smaller size type to a larger size type
            int myInt = 17;
            double myDouble = myInt; // Automatic casting: int to double

            Console.WriteLine(myInt); // Outputs 17
            Console.WriteLine(myDouble); // Outputs 17

            // Explicit casting must be done manually by placing the type in parentheses in front of the value.

            double myDouble2 = 17.58;
            int myInt2 = (int)myDouble2; // Manual casting: double to int

            Console.WriteLine(myDouble2); // Outputs 17.58
            Console.WriteLine(myInt2); // Outputs 17

            // Type Conversion Methods
            int myInt3 = 20;
            double myDouble3 = 7.25;
            bool myBool3 = true;

            Console.WriteLine(Convert.ToString(myInt3));    // convert int to string
            Console.WriteLine(Convert.ToDouble(myInt3));    // convert int to double
            Console.WriteLine(Convert.ToInt32(myDouble3));  // convert double to int
            Console.WriteLine(Convert.ToString(myBool3));   // convert bool to string


            // Casting Enums

            Console.WriteLine(WeekDays.Friday); //output: Friday 
            int day = (int)WeekDays.Friday; // enum to int conversion
            Console.WriteLine(day); //output: 4 

            var wd = (WeekDays)5; // int to enum conversion
            Console.WriteLine(wd);//output: Saturday 

            Console.ReadKey();
        }
    }
}
