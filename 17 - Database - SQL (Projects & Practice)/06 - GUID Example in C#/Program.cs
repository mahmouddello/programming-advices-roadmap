using System;

namespace _06___GUID_Example_in_C_
{
    internal class Program
    {
        static void Main(string[] args)
        {
            for (int i = 1; i <= 10; i++) 
            {
                Guid guid = Guid.NewGuid();
                Console.WriteLine(guid);
            }

            Console.ReadKey();
        }
    }
}
