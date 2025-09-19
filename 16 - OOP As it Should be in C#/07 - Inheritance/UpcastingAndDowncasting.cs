using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _07___Inheritance
{
    public class Person2
    {
        public string Name { get; set; }
        public int Age { get; set; }

        public void Greet()
        {
            Console.WriteLine($"Hi, my name is {Name} and I am {Age} years old.");
        }
    }

    public class Employee2 : Person2
    {
        public string Company { get; set; }
        public decimal Salary { get; set; }

        public void Work()
        {
            Console.WriteLine($"I work at {Company} and earn {Salary:C} per year.");
        }
    }
    internal class UpcastingAndDowncasting
    {
        static void Main(string[] args)
        {
            // Upcasting
            Employee2 employee = new Employee2 { Name = "John", Age = 30, Company = "Acme Inc.", Salary = 50000 };
            Person2 person = employee; // Upcasting
            person.Greet(); // Works fine, inherited method

            // Downcasting
            Person2 person2 = new Employee2 { Name = "Jane", Age = 25, Company = "XYZ Corp.", Salary = 60000 };
            Employee2 employee2 = (Employee2)person2; // Explicit downcast
            employee2.Work(); // Works fine, object is actually Employee

            // Invalid Downcasting → Runtime Error
            // Person person3 = new Person { Name = "Bob", Age = 40 };
            // Employee employee3 = (Employee)person3;  // InvalidCastException

            Console.ReadKey();
        }
    }
}
