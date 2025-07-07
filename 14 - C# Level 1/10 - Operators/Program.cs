using System;

namespace Operators
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Unary Operators 
            int number = 10, result;
            bool flag = true;

            result = +number;
            Console.WriteLine("+number = " + result);

            result = -number;
            Console.WriteLine("-number = " + result);

            result = ++number;
            Console.WriteLine("++number = " + result);

            result = --number;
            Console.WriteLine("--number = " + result);

            Console.WriteLine("!flag = " + (!flag));

            Console.WriteLine((number++));
            Console.WriteLine((number));

            Console.WriteLine((++number));
            Console.WriteLine((number));

            // Ternary Operators
            int number2 = 12;
            string result2;

            result2 = (number2 % 2 == 0) ? "Even Number" : "Odd Number";
            Console.WriteLine("{0} is {1}", number, result2);

            // Bitwise Shifts
            int number3 = 4;
            // 0000 0000 0000 0000 0100

            // right shift: adds "number" of bits from left and deletes that number of bits from right
            // left shift: adds "number" of bits from right and deletes that number of bits from left

            Console.WriteLine(number3 >> 1); // 0000 0000 0000 0010
            Console.WriteLine(number3 << 1); // 0000 0000 0000 1000

            Console.ReadKey();
        }
    }
}
