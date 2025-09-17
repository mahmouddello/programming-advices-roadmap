using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01___Class___Object
{
    class Person
    {
        // Fields
        public string firstName;
        public string lastName;

        // Methods
        public string FullName()
        {
            return firstName + ' ' + lastName;
        }
    }
    
    internal class Program
    {
        static void Main(string[] args)
        {
            Person person1 = new Person();

            Console.WriteLine("Accessing Object 1 (Person):");
            person1.firstName = "Mahmoud";
            person1.lastName = "Dello";
            Console.WriteLine(person1.FullName());

            Person person2 = new Person();
            Console.WriteLine("\nAccessing Object 2 (Person):");
            person2.firstName = "Ali";
            person2.lastName = "Maher";
            Console.WriteLine(person2.FullName());


        }
    }
}
