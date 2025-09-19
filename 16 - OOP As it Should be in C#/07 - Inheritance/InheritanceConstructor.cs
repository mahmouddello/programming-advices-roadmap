using System;

namespace _07___Inheritance
{
    public class Person
    {
        // Properties
        public int Id { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Title { get; set; }

        // Read-only property
        public string FullName
        {
            get { return $"{FirstName} {LastName}"; }
        }

        // Constructor
        public Person(int id, string firstName, string lastName, string title)
        {
            Id = id;
            FirstName = firstName;
            LastName = lastName;
            Title = title;
        }
    }

    public class Employee : Person
    {
        // Properties
        public float Salary { get; set; }
        public string DepartmentName { get; set; }

        // Constructor
        public Employee(int id, string firstName, string lastName, string title,
                        float salary, string departmentName)
            : base(id, firstName, lastName, title)
        {
            Salary = salary;
            DepartmentName = departmentName;
        }

        public void IncreaseSalaryBy(float amount)
        {
            if (amount > 0)
                Salary += amount;
        }
    }

    internal class InheritanceConstructor
    {
        static void Main(string[] args)
        {
            // Create an object of Employee
            Employee employee1 = new Employee(10, "Mahmoud", "Dello", "Software Engineer", 22000, "Software Development");
            Console.WriteLine($"ID: {employee1.Id}");
            Console.WriteLine($"Full Name: {employee1.FullName}");
            Console.WriteLine($"Title: {employee1.Title}");
            Console.WriteLine($"Department Name: {employee1.DepartmentName}");
            Console.WriteLine($"Salary: {employee1.Salary} TRY");

            employee1.IncreaseSalaryBy(100);
            Console.WriteLine($"\nSalary after increasing is: {employee1.Salary} TRY");

            Console.ReadKey();
        }
    }
}
