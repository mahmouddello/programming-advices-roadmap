using System;

namespace _07___Nullable_Datatypes
{
    internal class NullableExample
    {
        

        static void Main()
        {
            // Declare a nullable int using Nullable<T>
            Nullable<int> nullableInt1 = null;

            // Shorthand notation using int?
            int? nullableInt2 = null;

            // Check if the nullable ints have values
            if (nullableInt1.HasValue)
            {
                Console.WriteLine("nullableInt1 has a value: " + nullableInt1.Value);
            }
            else
            {
                Console.WriteLine("nullableInt1 is null.");
            }


            if (nullableInt2.HasValue)
            {
                Console.WriteLine("nullableInt2 has a value: " + nullableInt2.Value);
            }
            else
            {
                Console.WriteLine("nullableInt2 is null.");
            }


            // Using the null-coalescing operator
            int result = nullableInt2 ?? 0;
            Console.WriteLine("Using null-coalescing operator: " + result);


            // Using the null-conditional operator
            string stringValue = nullableInt2?.ToString();
            Console.WriteLine("String representation: " + (stringValue ?? "null"));

            Console.ReadKey();
        }
    }
}
