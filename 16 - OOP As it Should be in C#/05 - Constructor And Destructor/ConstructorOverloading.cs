using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConstructorAndDestructor
{
    class clsPerson2
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int Age { get; set; }

        // 1️- Parameterless Constructor (Default Values)
        public clsPerson2()
        {
            this.Id = -1;
            this.Name = "Empty";
            this.Age = 0;
        }

        // 2️- Parameterized Constructor (Custom Values)
        public clsPerson2(int Id, string Name, short Age)
        {
            this.Id = Id;
            this.Name = Name;
            this.Age = Age;
        }
    }
    internal class ConstructorOverloading
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Calling Parameterless Constructor:");
            clsPerson2 Person1 = new clsPerson2();  // Calls constructor #1
            Console.WriteLine("ID:= {0}", Person1.Id);
            Console.WriteLine("Name:= {0}", Person1.Name);
            Console.WriteLine("Age:= {0}", Person1.Age);

            Console.WriteLine("\nCalling Parameterized Constructor:");
            clsPerson2 Person2 = new clsPerson2(10, "Mohammed Abu-Hadhoud", 45);  // Calls constructor #2
            Console.WriteLine("ID:= {0}", Person2.Id);
            Console.WriteLine("Name:= {0}", Person2.Name);
            Console.WriteLine("Age:= {0}", Person2.Age);

            Console.ReadKey();
        }
    }
}
