using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _11___DataAdapter
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string connectionString =
             "Server=.;Database=HR_Database;User Id=sa;Password=sa123456;";

            // Create a new DataSet
            DataSet dataSet = new DataSet();

            // Create a new DataAdapter with a SELECT query and the connection string
            string query = "SELECT * FROM Employees;";
            SqlDataAdapter dataAdapter = new SqlDataAdapter(query, connectionString);

            // Open the connection
            SqlConnection connection = new SqlConnection(connectionString);

            connection.Open();

            // Set the SelectCommand of the DataAdapter to the connection
            dataAdapter.SelectCommand.Connection = connection;

            // Fill the DataSet with data from the data source
            dataAdapter.Fill(dataSet, "Employees");

            connection.Close();

            // Display the data from the DataSet
            DataTable customersTable = dataSet.Tables["Employees"];
            foreach (DataRow row in customersTable.Rows)
            {
                Console.WriteLine("Customer ID: {0}, Name: {1}, LastName: {2}", row["ID"], row["FirstName"], row["LastName"]);
            }

            // Make changes to the DataSet (add, modify, or delete rows)
            //
            //
            ///

            // Update the data source with the changes made to the DataSet
            connection.Open();

            // Set the UpdateCommand of the DataAdapter to the connection
            SqlCommandBuilder commandBuilder = new SqlCommandBuilder(dataAdapter);

            // Update the data source with the changes
            dataAdapter.Update(dataSet, "Employees");

            connection.Close();
        }
    }
}
