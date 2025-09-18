using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConstructorAndDestructor
{
    class Person
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int Age { get; set; }

        // Paramter-Less Constructor
        public Person()
        {
            Id = -1;
            Name = "Empty";
            Age = 0;
        }

        internal class ParameterLessConstructor
        {
            static void Main(string[] args)
            {
                Person person1 = new Person(); // Constructor Invoked when object is created

                Console.WriteLine($"ID = {person1.Id}");
                Console.WriteLine($"Name = {person1.Name}");
                Console.WriteLine($"Age = {person1.Age}");
            }
        }
    }
}
