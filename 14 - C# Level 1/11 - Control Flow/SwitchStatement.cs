using System;
using System.Net.NetworkInformation;

namespace ControlFlow
{
    internal class SwitchStatement
    {
        static void Main(string[] args)
        {

            // Example 1: Switch
            char ch;
            Console.WriteLine("Enter a letter?");
            ch = Convert.ToChar(Console.ReadLine());

            switch (Char.ToLower(ch))
            {
                case 'a':
                    Console.WriteLine("Vowel");
                    break;
                case 'e':
                    Console.WriteLine("Vowel");
                    break;
                case 'i':
                    Console.WriteLine("Vowel");
                    break;
                case 'o':
                    Console.WriteLine("Vowel");
                    break;
                case 'u':
                    Console.WriteLine("Vowel");
                    break;
                default:
                    Console.WriteLine("Not a vowel");
                    break;
            }

            // Example 2 grouped cases
            switch (Char.ToLower(ch))
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    Console.WriteLine("Vowel");
                    break;
                default:
                    Console.WriteLine("Not a vowel");
                    break;
            }

            //Example 3 Simple Calculator
            char op;
            double first, second, result;

            Console.Write("Enter first number: ");
            first = Convert.ToDouble(Console.ReadLine());
            Console.Write("Enter second number: ");
            second = Convert.ToDouble(Console.ReadLine());
            Console.Write("Enter operator (+, -, *, /): ");
            op = (char)Console.Read();

            switch (op)
            {
                case '+':
                    result = first + second;
                    Console.WriteLine($"{first} + {second} = {result}");
                    break;

                case '-':
                    result = first - second;
                    Console.WriteLine($"{first} - {second} = {result}");
                    break;

                case '*':
                    result = first * second;
                    Console.WriteLine($"{first} * {second} = {result}");
                    break;

                case '/':
                    result = first / second;
                    Console.WriteLine($"{first} / {second} = {result}");
                    break;

                default:
                    Console.WriteLine("Invalid Operator");
                    break;

            }

            // Example 4 Strings
            string Name = "Mohammed";

            //You can compare string as well using switch
            switch (Name.ToLower())
            {
                case "mohammed":

                    Console.WriteLine("Yes Mohammed");
                    break;

                case "ali":

                    Console.WriteLine("Yes ALi");
                    break;

                default:
                    Console.WriteLine("No Name Matched!");
                    break;

            }

            Console.ReadKey();
        }
    }
}
