using System;

namespace _19___Operator_Overloading
{

    public class Program
    {
        static void Main(string[] args)
        {


            int x = 10, y = 20;
            string s1 = "Mohammed", s2 = "Abu-Hadhoud";


            //The '+' operator is used for normal addition
            int z = x + y;


            //The '+' operator is used for concatonation
            string s3 = s1 + ' ' + s2;

            Console.WriteLine($"The '+' operator is used for normal addition resulting z = {z}");
            Console.WriteLine($"The '+' operator is used for concatonation rsulting s3 = {s3}");

            Console.ReadKey();
        }
    }
}
