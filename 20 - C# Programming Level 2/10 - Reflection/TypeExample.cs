using System;

namespace _10___Reflection
{
    public class TypeExample
    {
        static void Main(string[] args)
        {
            Type myType = typeof(string);

            Console.WriteLine("--- TYPE INFORMATION ---");
            Console.WriteLine($"Name: {myType.Name}");
            Console.WriteLine($"Full Name: {myType.FullName}");
            Console.WriteLine($"Is Class: {myType.IsClass}");

            Console.ReadLine();
        }
    }
}
