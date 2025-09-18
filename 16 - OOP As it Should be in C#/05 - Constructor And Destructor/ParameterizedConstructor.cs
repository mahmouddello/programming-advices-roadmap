using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConstructorAndDestructor
{
    class Employee
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Title { get; set; }

        public Employee(int Id, string Name, string Title)
        {
            this.Id = Id;
            this.Name = Name;
            this.Title = Title;
        }
    }
    internal class ParameterizedConstructor
    {
        static void Main(string[] args)
        {
            //Employee emp1 = new Employee(); // no parameter-less or default constructor -> Error
            Employee emp1 = new Employee(2, "Mahmoud Dello", "Software Engineer");

            Console.WriteLine($"ID = {emp1.Id}");
            Console.WriteLine($"Name = {emp1.Name}");
            Console.WriteLine($"Title = {emp1.Title}");

            Console.ReadKey();
        }
    }
}
