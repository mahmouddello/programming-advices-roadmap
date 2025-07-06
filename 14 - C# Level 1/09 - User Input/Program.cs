using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UserInput
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Console.ReadLine() = cin>> in C++
            // Important: Console.ReadLine() always reads string.

            // Type your username and press enter
            Console.WriteLine("Enter username?");

            string userName = Console.ReadLine();
            Console.WriteLine($"Username is: {userName}");

            Console.WriteLine("Enter a number: ");
            int number = Convert.ToInt32(Console.ReadLine()); // convert type after reading
            Console.WriteLine($"Number is {number}");

            Console.ReadKey();

        }
    }
}
