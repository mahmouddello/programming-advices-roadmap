using System; // instead of #include we use "using" in C#

namespace Syntax // Namespace: we can name it what ever we want, same as C++
{
    internal class Program
    {
        // main can't be written outside of class like C++, C# forces OOP
        // main is Static, so we can call it without an Object
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World :)"); // writes line to the screen
            Console.ReadKey(); // holds the console window
        }
    }
}
