using System;
using System.Runtime.InteropServices;

namespace Output
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // WriteLine() = cout in C++, automatically inserts new line after end of statement
            Console.WriteLine("Hello World!");
            Console.WriteLine("My Name is Mahmoud Dello");
            Console.WriteLine("I'm learning C#");
            Console.WriteLine("C# is much easier than C++ to learn :)");
            Console.WriteLine("Sum of 10 + 20 = " + (10 + 20)); // without parantheses, it will peform string concatenation.

            // Write() = like cout with out endl or '\n' 
            Console.Write("I'm a Junior Software Engineer");
            Console.Write(", Passionate in Back-End Development");

            // Formatted String

            // 0 -> first paramter : Welcome to, 1 -> Second Parameter: Programming Advices
            Console.WriteLine("\n{0} {1}", "Welcome to", "Programming Advices");
            Console.WriteLine("Hi MyName is: {0} I live in {1}", "Mahmoud", "Turkey");

            // Escape Characters
            Console.WriteLine("Useful Escape Characters:\n");

            //Newline
            Console.WriteLine("Newline:");
            Console.WriteLine("Welcome to \nProgrammingAvices\n");

            //Tab
            Console.WriteLine("Tab:");
            Console.WriteLine("Welcome to\tProgrammingAvices\n");

            //Backspace
            Console.WriteLine("Backspace:");
            Console.WriteLine("Welcome to \bProgrammingAvices\n");

            //Single quote
            Console.WriteLine("Single Quote:");
            Console.WriteLine("Welcome to \'ProgrammingAvices\n");

            //Double quote
            Console.WriteLine("Double Quote:");
            Console.WriteLine("Welcome to \"ProgrammingAvices\n");

            //Backslash
            Console.WriteLine("Backslash:");
            Console.WriteLine("Welcome to \\ProgrammingAvices\n");

            //Alert
            Console.WriteLine("Alert:");
            Console.WriteLine("\a");

            Console.ReadKey();

            // Single Line Comment
            /*
                Multiple Line Comment
             */
        }
    }
}
