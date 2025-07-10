using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _14___Methods
{
    internal class Program
    {
        static void MyMethod()
        {
            Console.WriteLine("Hello World from MyMethod!");
        }
        static void PrintMyName()
        {
            Console.WriteLine("Mahmoud Dello");
        }

        // Method with Params
        static void PrintMyInfo(string name, byte age)
        {
            Console.WriteLine($"Name: {name}, Age: {age}");
        }

        // Method with Params and Default Value
        static void PrintMyInfo2(string name, byte age, string address = "No Address!")
        {
            Console.WriteLine($"Name: {name}, Age: {age}, Address: {address}");
        }

        // Method with return value
        static string GetMyName()
        {
            return "Mahmoud Dello";
        }

        static void MyMethod2(string child1, string child2, string child3)
        {
            Console.WriteLine("The youngest child is: " + child3);
        }

        // Method overloading
        static int Sum(int Num1, int Num2)

        {
            return Num1 + Num2;
        }

        static int Sum(int Num1, int Num2, int Num3)

        {
            return Num1 + Num2 + Num3;
        }
        static int Sum(int Num1, int Num2, int Num3, int Num4)

        {
            return Num1 + Num2 + Num3 + Num4;
        }

        static void Main(string[] args)
        {
            MyMethod();
            PrintMyName();

            PrintMyInfo("Mahmoud Dello", 23);

            PrintMyInfo2("Mahmoud Dello", 23);
            PrintMyInfo2("Mahmoud Dello", 23, "Turkey");

            Console.WriteLine(GetMyName());

            // Calling method with names arguments, order doesn't matter
            MyMethod2(child3: "Omar", child1: "Saqer", child2: "Hamza");

            //we have 3 different methods but with the same name.

            Console.WriteLine(Sum(10, 20));
            Console.WriteLine(Sum(10, 20, 30));
            Console.WriteLine(Sum(10, 20, 30, 40));

            Console.ReadKey();
        }
    }
}
