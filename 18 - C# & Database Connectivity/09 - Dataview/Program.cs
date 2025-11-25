using System;
using System.Data;

namespace _09___Dataview
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

        static void PrintDataView(DataView dataView)
        {
            for (int i = 0; i < dataView.Count; i++)
                Console.WriteLine($"{dataView[i][0]}, {dataView[i][1]}, {dataView[i][2]}, {dataView[i][3]}");
        }

        static void Main(string[] args)
        {
            DataTable employees = CreateEmployeesTable();
            DataView employeesDateView1 = new DataView(employees); // 1st dataview

            Console.WriteLine("Employees list from dataview:\n");
            PrintDataView(employeesDateView1);

            // Create a second view and filter data
            DataView employeesDataView2 = new DataView(employees); // 2nd dataview
            employeesDataView2.RowFilter = "Country ='Jordan' OR Country = 'Iraq'";

            Console.WriteLine("\nEmployees list from dataview (Filter Country Jordan OR Iraq):\n");
            PrintDataView(employeesDataView2);

            // Create a third view and sort data
            DataView employeesDataView3 = new DataView(employees); // 3rd dataview
            employeesDataView3.Sort = "Name ASC";

            Console.WriteLine("\nEmployees list from dataview (Sort by Name ASC):\n");
            PrintDataView(employeesDataView3);

            Console.ReadKey();
        }
    }
}
