using dotenv.net;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01___DBConnection___SimpleQueries
{
    // ExecuteScalar returns first column from the first row of the result set (single value)
    internal class RetrieveSingleValue_ExecuteScalar
    {
        private static string _connectionString;

        static string connectionString
        {
            get
            {
                if (_connectionString == null)
                {
                    // Get the absolute path to your .env file (4 levels up from /bin/Debug)
                    string baseDir = AppDomain.CurrentDomain.BaseDirectory;
                    string envPath = Path.GetFullPath(Path.Combine(baseDir, @"..\..\..\.env"));

                    Console.WriteLine("Loading .env from: " + envPath);

                    DotEnv.Load(new DotEnvOptions(
                        envFilePaths: new[] { envPath },
                        overwriteExistingVars: true
                    ));

                    _connectionString = Environment.GetEnvironmentVariable("ContactsDB");
                }

                return _connectionString;
            }
        }

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
