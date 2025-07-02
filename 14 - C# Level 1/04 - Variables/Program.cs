using System;
using System.ComponentModel;

namespace Vairables
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // datatype variableName = value
            string name = "Mahmoud Dello";
            Console.WriteLine(name);

            int x = 10; int y = 20;
            Console.WriteLine("x = " +x);
            Console.WriteLine("y = " +y);

            Console.WriteLine("x + y = " + x + y); // Wrong answer, will do concatenation
            Console.WriteLine("x + y = " + (x + y)); // Right Answer

            // other common datatypes
            double MyDouble = 25.8D; // D is a suffix to indicate the variable type
            char MyLetter = 'M';
            bool MyBool = true;

            // Rules of naming variables: Notes in Notion

            /* Implicitly typed variables
             Alternatively in C#, we can declare a variable without knowing 
             its type using `var` keyword. 
             Such variables are called implicitly typed local variables.

             Variables declared using var keyword must be initialized at the time of declaration.
            */

            var a = 10;
            var b = 10.5;
            var c = "Mohammed";

            Console.WriteLine("a={0}, b={1}, c={2}", a, b, c);

            Console.ReadKey();
        }
    }
}
