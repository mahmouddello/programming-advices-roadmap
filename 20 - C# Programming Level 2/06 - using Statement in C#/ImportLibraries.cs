// using here used to import a library (namespace) 
using System;

namespace _06___using_Statement_in_C_
{
    internal class ImportLibraries
    {
        static void Main(string[] args)
        {
            // Without using System;
            System.Console.WriteLine("Hello World, without using;");

            // With using System;
            Console.WriteLine("Hello World, with using;");
            Console.ReadKey();
        }
    }
}
