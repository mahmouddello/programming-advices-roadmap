using System;

namespace _12____Mutable___Immutable_Types
{
    public class Program
    {
        static void Main(string[] args)
        {
            // Mutable example
            MutablePerson person1 = new MutablePerson { Name = "Alice", Age = 30 };
            person1.Age = 31; // Mutable state change


            // Immutable example
            ImmutablePerson person2 = new ImmutablePerson("Bob", 25);
            // person2.Age = 26; // Compiler error - immutable type
            ImmutablePerson newPerson = new ImmutablePerson(person2.Name, 26); // Creating a new instance with the desired change
        }
    }
}
