using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;

namespace RealLifeApplication
{
    class Person
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int Age { get; set; }

        public Person(int Id, string Name, int Age)
        {
            this.Id = Id;
            this.Name = Name;
            this.Age = Age;
        }

        public static Person Find(int Id)
        {
            // We simulate the process for now, later on we will use database
            if (Id == 10)
                return new Person(10, "Mahmoud Dello", 22);

            return null;
        }

        public static Person Find(string Username, string Password)
        {
            // We simulate the process for now, later on we will use database
            if (Username == "user1" && Password == "1234")
                return new Person(11, "Hamdi Alkadi", 22);

            return null;
        }
    }
    
    internal class Program
    {
        static void Main(string[] args)
        {
            // Person person1 = new Person(); -> Object with no params not allowed!
            Person person2 = new Person(11, "Jawad Dello", 14);

            Console.WriteLine("Finding Person by ID");
            
            Person person3 = Person.Find(Id: 10);
            if (person3 != null)
            {
                Console.WriteLine($"ID = {person3.Id}");
                Console.WriteLine($"Name = {person3.Name}");
                Console.WriteLine($"Age = {person3.Age}");
            }
            else
                Console.WriteLine("Couldn't find the specfied person by given Id.");

            Console.WriteLine("\nFinding Person by username and password");

            Person person4 = Person.Find(Username: "user1", Password: "1234");
            if (person3 != null)
            {
                Console.WriteLine($"ID = {person4.Id}");
                Console.WriteLine($"Name = {person4.Name}");
                Console.WriteLine($"Age = {person4.Age}");
            }
            else
                Console.WriteLine("Couldn't find the specfied person by given username and password.");
        }
    }
}

