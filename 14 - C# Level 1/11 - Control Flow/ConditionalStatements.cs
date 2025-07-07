 using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ControlFlow
{
    internal class ConditionalStatements
    {
        static void Main(string[] args)
        {
            int x = 10; int y = 20;

            //if then statement
            if (x == 10 && y <= 20)
            {
                Console.WriteLine("yes x = 10 and y<=20");
            }

            //if then else statement
            if (x == 11)
            {
                Console.WriteLine("yes x = 11 ");
            }
            else
            {
                Console.WriteLine("yes x != 11 ");
            }

            //if else if statement
            int number = 12;

            if (number < 5)
            {
                Console.WriteLine("{0} is less than 5", number);
            }
            else if (number > 5)
            {
                Console.WriteLine("{0} is greater than 5", number);
            }
            else
            {
                Console.WriteLine("{0} is equal to 5");
            }


            Console.ReadKey();
        }
    }
}
