using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _07___Inheritance
{

    public class clsPerson
    {
        // Properties
        public int ID { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Title { get; set; }

        // Read-only property
        public string FullName
        {
            get { return FirstName + " " + LastName; }
        }
    }

    public class clsEmployee : clsPerson
    {
        public float Salary { get; set; }
        public string DepartmentName { get; set; }

        public void IncreaseSalaryBy(float amount)
        {
            Salary += amount;
        }
    }
    internal class Indroduction
    {
        static void Main()
        {
            // Create object of Employee class
            clsEmployee Employee1 = new clsEmployee();

            // Inherited members from Person
            Employee1.ID = 10;
            Employee1.Title = "Mr.";
            Employee1.FirstName = "Mohammed";
            Employee1.LastName = "Abu-Hadhoud";

            // Members from Employee class
            Employee1.DepartmentName = "IT";
            Employee1.Salary = 5000;

            Console.WriteLine("ID: " + Employee1.ID);
            Console.WriteLine("Full Name: " + Employee1.FullName);
            Console.WriteLine("Department: " + Employee1.DepartmentName);
            Console.WriteLine("Salary: " + Employee1.Salary);

            Employee1.IncreaseSalaryBy(100);
            Console.WriteLine("Salary after increase: " + Employee1.Salary);
        }
    }
}
