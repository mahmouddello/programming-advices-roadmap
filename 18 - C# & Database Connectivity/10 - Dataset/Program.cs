using System;
using System.Data;

namespace _10___Dataset
{
    internal class Program
    {
        static DataTable CreateEmployeesTable()
        {
            DataTable table = new DataTable();
            table.Columns.Add("ID", typeof(int));
            table.Columns.Add("Name", typeof(string));
            table.Columns.Add("Country", typeof(string));
            table.Columns.Add("Salary", typeof(double));
            table.Columns.Add("Join Date", typeof(DateTime));

            // Add rows
            table.Rows.Add(1, "Mahmoud Dello", "Syria", 104000, new DateTime(2019, 3, 27));
            table.Rows.Add(2, "Anas Dello", "Syria", 52000, new DateTime(2013, 1, 25));
            table.Rows.Add(3, "Jawad Dello", "Iraq", 82000, new DateTime(2024, 4, 28));
            table.Rows.Add(4, "Mohammed Enjary", "Jordan", 76000, new DateTime(2022, 12, 29));
            table.Rows.Add(5, "Saria Obaid", "Syria", 28000, new DateTime(2018, 8, 23));

            return table;
        }

        static DataTable CreateDepartmentsTable()
        {
            DataTable table = new DataTable();
            table.Columns.Add("ID", typeof(int));
            table.Columns.Add("Name", typeof(string));

            // Add rows
            table.Rows.Add(1, "IT");
            table.Rows.Add(2, "Marketing");
            table.Rows.Add(3, "HR");

            return table;
        }

        static void PrintEmployeesTable(DataTable table)
        {
            foreach (DataRow row in table.Rows)
                Console.WriteLine($"ID: {row["ID"]}\t Name: {row["Name"]}\t Country: {row["Country"]}\t " +
                    $"Salary: {row["Salary"]}\t Join Date: {((DateTime)row["Join Date"]).ToShortDateString()}");
        }

        static void PrintDepartmentsTable(DataTable table)
        {
            foreach (DataRow row in table.Rows)
                Console.WriteLine($"ID: {row["ID"]}\t Name: {row["Name"]}");
        }

        static void Main(string[] args)
        {
            DataTable employeesTable = CreateEmployeesTable();
            DataTable departmentsTable = CreateDepartmentsTable();

            Console.WriteLine("Employees Table:\n");
            PrintEmployeesTable(employeesTable);

            Console.WriteLine("\nDepartments Table:\n");
            PrintDepartmentsTable(departmentsTable);
            
            // Create dataset, add the data tables
            DataSet dataSet = new DataSet();
            dataSet.Tables.Add(employeesTable);
            dataSet.Tables.Add(departmentsTable);

            Console.WriteLine("\n---------------------------------------------------------\n");

            // dataSet.Tables[0] represent the first added DataTable which is employeesTable
            foreach(DataRow row in dataSet.Tables[0].Rows)
                Console.WriteLine($"ID: {row["ID"]}\t Name: {row["Name"]}\t Country: {row["Country"]}\t " +
                $"Salary: {row["Salary"]}\t Join Date: {((DateTime)row["Join Date"]).ToShortDateString()}");
            Console.WriteLine("\n---------------------------------------------------------\n");


            // Access Datatables Inside Dataset By Name
            employeesTable.TableName = "Employees";
            departmentsTable.TableName = "Departments";
            foreach (DataRow row in dataSet.Tables["Employees"].Rows)
                Console.WriteLine($"ID: {row["ID"]}\t Name: {row["Name"]}\t Country: {row["Country"]}\t " +
                $"Salary: {row["Salary"]}\t Join Date: {((DateTime)row["Join Date"]).ToShortDateString()}");
        }
    }
}
