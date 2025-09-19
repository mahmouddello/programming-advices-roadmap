using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _08___Abstract_Class___Abstract_Methods
{
    public abstract class Person
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }

        public abstract void Introduce();

        public void SayGoodbye()
        {
            Console.WriteLine("Goodbye!");
        }
    }

    public class Employee : Person
    {
        public int Id   { get; set; }
        
        // forced to implement abstract method by overriding it
        public override void Introduce()
        {
            Console.WriteLine($"Hi, my name is {FirstName} {LastName}, and my employee id is {Id}");
        }
    }


    internal class Program
    {
        static void Main(string[] args)
        {
            Employee emp = new Employee();

            emp.FirstName = "Mahmoud";
            emp.LastName = "Dello";
            emp.Id = 123;

            emp.Introduce();
            emp.SayGoodbye();

        }
    }
}
