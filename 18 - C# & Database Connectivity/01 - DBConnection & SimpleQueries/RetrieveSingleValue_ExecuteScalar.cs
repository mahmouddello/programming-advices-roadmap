using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01___DBConnection___SimpleQueries
{
    // ExecuteScalar returns first column from the first row of the result set (single value)
    internal class RetrieveSingleValue_ExecuteScalar
    {
        static string connectionString = "Server=.;Database=ContactsDB;User Id=sa;Password=sa123456";

        static string GetFirstName(int contactID)
        {
            string firstName = string.Empty;
            
            SqlConnection sqlConnection = new SqlConnection(connectionString);
            string query = "SELECT FirstName FROM Contacts WHERE ContactID = @contactID";

            SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);
            sqlCommand.Parameters.AddWithValue("@contactID", contactID);

            try {
                sqlConnection.Open();
                object result = sqlCommand.ExecuteScalar();

                if (result != null)
                    firstName = result.ToString();
                else
                    firstName = string.Empty;
            }

            catch (Exception ex) {
                Console.WriteLine($"Error: {ex.Message}");
            }

            finally {

                if (sqlConnection.State == System.Data.ConnectionState.Open)
                    sqlConnection.Close();
            }

            return firstName;
        }

        static void Main(string[] args)
        {
            Console.WriteLine(GetFirstName(1));
            Console.ReadKey();
        }
    }
}
