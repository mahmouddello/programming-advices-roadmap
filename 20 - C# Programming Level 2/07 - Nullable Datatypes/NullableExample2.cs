using System;

namespace _07___Nullable_Datatypes
{
    internal class NullableExample2
    {
        static void Proedure1(string name, int? age)
        {
            Console.WriteLine(name);

            if (age.HasValue)
                Console.WriteLine(age);
            else
                Console.WriteLine("Age is null");
        }

        static void Proedure2(string name, Nullable<int> age)
        {
            Console.WriteLine(name);

            if (age.HasValue)
                Console.WriteLine(age);
            else
                Console.WriteLine("Age is null");
        }

        static void Main(string[] args)
        {
            Proedure1("Mahmoud", 35);
            Proedure1("Anas", null);

            Proedure2("Mahmoud", null);
            Proedure2("Anas", 24);
        }
    }
}
