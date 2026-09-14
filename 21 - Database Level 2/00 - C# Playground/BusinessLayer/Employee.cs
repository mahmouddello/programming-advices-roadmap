using DataAccessLayer;
using System;
using System.Data;

namespace BusinessLayer
{
    public class Employee
    {
        public string Name { get; private set; }
        public string Department { get; private set; }
        public int Salary { get; private set; }
        public int PerformanceRating { get; private set; }

        public Employee(string name, string department, int salary, int performanceRating)
        {
            Name = name;
            Department = department;
            Salary = salary;
            PerformanceRating = performanceRating;
        }

        public Employee()
        {
            Name = string.Empty;
            Department = string.Empty;
            Salary = 0;
            PerformanceRating = 0;
        }

        public static DataTable GetAllEmployees() => EmployeeData.GetAllEmployees();

        public static Employee Find(string employeeName)
        {
            string departmentName = string.Empty;
            int salary = 0, peformanceRating = 0;

            if (EmployeeData.GetEmployeeByName(employeeName, ref departmentName, ref salary, ref peformanceRating))
                return new Employee(employeeName, departmentName, salary, peformanceRating);

            return null;
        }

        public bool UpdateSalary()
        {
            if (PerformanceRating > 90)
                Salary = (int)Math.Round(Salary * 1.15);
            else if (PerformanceRating > 75 && PerformanceRating < 90)
                Salary = (int)Math.Round(Salary * 1.10);
            else if (PerformanceRating > 50 && PerformanceRating < 74)
                Salary = (int)Math.Round(Salary * 1.10);

            return EmployeeData.UpdateEmployeeSalary(this.Name, this.Salary);
        }
    }
}
