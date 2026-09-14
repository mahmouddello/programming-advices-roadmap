using System;
using System.Data;
using System.Diagnostics;
using BusinessLayer;

namespace PresentationLayer
{
    public class Program
    {
        // Avg: +100 ms in C#, T-SQL near instant > Manual C#
        public static void UpdateSalariesInCSharp()
        {
            Stopwatch programWatch = Stopwatch.StartNew();

            // 1. Get All employees
            DataTable employees = Employee.GetAllEmployees();

            if (employees == null)
            {
                Console.WriteLine("No employees were found");
                return;
            }

            // Loop on each employee, update his salary based on performance rating, save to database
            foreach (DataRow row in employees.Rows)
            {
                Stopwatch stopwatch = Stopwatch.StartNew();
                Employee employee = new Employee
                (
                    name: Convert.ToString(row["Name"]),
                    department: Convert.ToString(row["Department"]),
                    salary: Convert.ToInt32(row["Salary"]),
                    performanceRating: Convert.ToInt32(row["PerformanceRating"])
                );

                employee.UpdateSalary();

                stopwatch.Stop();
                Console.WriteLine($"Time elapsed for {employee.Name} salary update: {stopwatch.Elapsed.TotalMilliseconds:F4} ms");
            }

            programWatch.Stop();
            Console.WriteLine($"Program took total of {programWatch.Elapsed.TotalMilliseconds} ms");
        }

        // Avg: +150 ms in C#, T-SQL near instant > Manual C#
        public static void CalculateBonusInCSharp()
        {
            Stopwatch programWatch = Stopwatch.StartNew();

            // 1. Get All employees
            DataTable employees = Employee.GetAllEmployees();

            if (employees == null)
            {
                Console.WriteLine("No employees were found");
                return;
            }

            foreach(DataRow employee in employees.Rows)
            {
                string name = employee["Name"].ToString();
                string department = employee["Department"].ToString();
                int salary = Convert.ToInt32(employee["Salary"]);
                int performanceRating = Convert.ToInt32(employee["PerformanceRating"]);

                int bonus;

                if (department == "Sales")
                {
                    if (performanceRating > 90)
                    {
                        bonus = salary * 15 / 100;
                    }
                    else if (performanceRating >= 75 && performanceRating <= 90)
                    {
                        bonus = salary * 10 / 100;
                    }
                    else
                    {
                        bonus = salary * 5 / 100;
                    }
                }
                else if (department == "HR")
                {
                    if (performanceRating > 90)
                    {
                        bonus = salary * 10 / 100;
                    }
                    else if (performanceRating >= 75 && performanceRating <= 90)
                    {
                        bonus = salary * 8 / 100;
                    }
                    else
                    {
                        bonus = salary * 4 / 100;
                    }
                }
                else
                {
                    if (performanceRating > 90)
                    {
                        bonus = salary * 8 / 100;
                    }
                    else if (performanceRating >= 75 && performanceRating <= 90)
                    {
                        bonus = salary * 6 / 100;
                    }
                    else
                    {
                        bonus = salary * 3 / 100;
                    }
                }

                Console.WriteLine($"{name} | {department} | {salary} | {performanceRating} | Bonus: {bonus}");
            }

            programWatch.Stop();
            Console.WriteLine($"\nProgram took total {programWatch.Elapsed.Milliseconds} ms to execute in C#");
        }

        public static void Main(string[] args)
        {
            CalculateBonusInCSharp();
        }
    }
}
