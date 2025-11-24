using System;
using System.Data;
using System.Linq;

namespace _07___DataTables
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

        static void PrintEmployees(DataTable table)
        {
            foreach (DataRow row in table.Rows)
                Console.WriteLine($"ID: {row["ID"]}\t Name: {row["Name"]}\t Country: {row["Country"]}\t " +
                    $"Salary: {row["Salary"]}\t Join Date: {((DateTime)row["Join Date"]).ToShortDateString()}");
        }

        static void PrintStatistics(DataTable table)
        {
            int employeesCount = 0;
            double totalSalaries = 0, averageSalary = 0, minSalary = 0, maxSalary = 0;

            employeesCount = table.Rows.Count;
            totalSalaries = Convert.ToDouble(table.Compute("SUM(Salary)", string.Empty));
            averageSalary = Convert.ToDouble(table.Compute("AVG(Salary)", string.Empty));
            minSalary = Convert.ToDouble(table.Compute("MIN(Salary)", string.Empty));
            maxSalary = Convert.ToDouble(table.Compute("MAX(Salary)", string.Empty));

            Console.WriteLine($"\nEmployees Count: {employeesCount}");
            Console.WriteLine($"Total Salaries: {totalSalaries}");
            Console.WriteLine($"Average Salary: {averageSalary}");
            Console.WriteLine($"Min Salary: {minSalary}");
            Console.WriteLine($"Max Salary: {maxSalary}");
        }

        static DataTable FilterByCountry(DataTable table, string country)
        {
            DataRow[] resultRows = table.Select($"Country='{country}'");

            return resultRows.Any() ? resultRows.CopyToDataTable() : table.Clone();
        }

        static void SortByQuery(ref DataTable table, string query)
        {
            table.DefaultView.Sort = query;
            table = table.DefaultView.ToTable();
        }

        static void DeleteRowByID(DataTable table, int id, bool acceptChanges = false)
        {
            // First filter for Employee ID.
            // NOTE: Select() returns references to the actual rows inside the original DataTable.
            // It does NOT create copies.
            DataRow[] resultSet = table.Select($"ID={id}");

            foreach (DataRow row in resultSet)
                row.Delete();

            // AcceptChanges() marks all pending row changes (Added, Modified, Deleted) as "Committed".
            // Usually we call this AFTER successfully updating the database.
            // It is similar to finalizing changes.
            if (acceptChanges)
                table.AcceptChanges();
        }

        // Update capable of name and salary just for demonstration purpose, you can extend this as you want.
        static void UpdateRowByID(DataTable table, int id, string name, double salary)
        {
            DataRow[] resultSet = table.Select($"ID={id}");

            foreach (DataRow row in resultSet)
            {
                row["Name"] = name;
                row["Salary"] = salary;
            }
        }

        static DataColumn CreateDataColumn
        (
           Type dataType,
           string columnName,
           bool autoIncrement = false,
           int autoIncSeed = 1,
           int autoIncStep = 1,
           string caption = "",
           bool unique = false,
           bool readOnly = false,
           bool allowNull = false
        )
        {
            DataColumn dataColumn = new DataColumn
            {
                DataType = dataType,
                ColumnName = columnName,
                AutoIncrement = autoIncrement,
                Unique = unique,
                ReadOnly = readOnly,
                AllowDBNull = allowNull
            };

            if (autoIncrement)
            {
                dataColumn.AutoIncrementSeed = autoIncSeed;
                dataColumn.AutoIncrementStep = autoIncStep;
            }

            if (!string.IsNullOrWhiteSpace(caption))
                dataColumn.Caption = caption;

            return dataColumn;
        }

        static void Main(string[] args)
        {

            // Example 1: Create Offline Data Table and ListData
            DataTable employeesDataTable = CreateEmployeesTable();
            Console.WriteLine("Employees List:\n");
            PrintEmployees(employeesDataTable);

            // Example 2: Aggregate functions (Count, Sum, Avg, Min, Max)
            PrintStatistics(employeesDataTable);
            Console.WriteLine("\n------------------------------------\n");

            // Example 3 (Filter Data and List)
            DataTable filteredData = FilterByCountry(employeesDataTable, "Syria");
            Console.WriteLine("Employees List (Filtered by Country Syria):\n");
            PrintEmployees(filteredData);
            PrintStatistics(filteredData);
            Console.WriteLine("\n------------------------------------\n");
            
            // Example 4 (Sorting)

            // Sort by ID descending
            Console.WriteLine("Employees List (Sorted by ID DESC):\n");
            SortByQuery(ref employeesDataTable, "ID DESC");
            PrintEmployees(employeesDataTable);
            Console.WriteLine("\n------------------------------------\n");

            // Sort by Name ascending
            Console.WriteLine("Employees List (Sorted by Name ASC):\n");
            SortByQuery(ref employeesDataTable, "Name ASC");
            PrintEmployees(employeesDataTable);
            Console.WriteLine("\n------------------------------------\n");

            // Example 5 (Delete row(s))
            Console.WriteLine("Employees List after deleting the ID = 4:\n");
            DeleteRowByID(employeesDataTable, 4);
            PrintEmployees(employeesDataTable);
            Console.WriteLine("\n------------------------------------\n");

            // Example 6 (Update row(s))
            Console.WriteLine("Employees List after updating the ID = 5:\n");
            UpdateRowByID(employeesDataTable, 5, "Fares AL-Ahmad", 82000);
            PrintEmployees(employeesDataTable);

            // Example 7 (Clear)
            // To clear all data(delete all records in the Datatable) you simply use.Clear method.
            //employeesDataTable.Clear();

            // Example 8 (Set PrimaryKey(s))
            DataColumn[] pkCols = new DataColumn[1];
            pkCols[0] = employeesDataTable.Columns["ID"];
            employeesDataTable.PrimaryKey = pkCols;

            try
            {
                employeesDataTable.Rows.Add(5, "Ahmad Khalil", "Qatar", 18000, new DateTime(2020, 3, 1));
            }
            catch (Exception ex) 
            {
                Console.WriteLine($"\nError: {ex.Message}");
            }

            Console.WriteLine("\n------------------------------------\n");

            // Example 9 (Autoincrement & Advanced column creation)
            DataTable employeesDataTable_v2 = new DataTable();
            DataColumn dataColumn;

            dataColumn = CreateDataColumn(dataType: typeof(int), columnName: "ID", autoIncrement: true, caption: "Employee ID");
            employeesDataTable_v2.Columns.Add(dataColumn);

            dataColumn = CreateDataColumn(dataType: typeof(string), columnName: "Name", autoIncrement: false, caption: "Name");
            employeesDataTable_v2.Columns.Add(dataColumn);

            dataColumn = CreateDataColumn(dataType: typeof(string), columnName: "Country", autoIncrement: false, caption: "Country");
            employeesDataTable_v2.Columns.Add(dataColumn);

            dataColumn = CreateDataColumn(dataType: typeof(double), columnName: "Salary", autoIncrement: false, caption: "Salary");
            employeesDataTable_v2.Columns.Add(dataColumn);

            dataColumn = CreateDataColumn(dataType: typeof(DateTime), columnName: "Date", autoIncrement: false, caption: "Date");
            employeesDataTable_v2.Columns.Add(dataColumn);
        }
    }
}
