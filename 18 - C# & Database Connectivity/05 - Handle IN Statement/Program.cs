using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.IO;
using dotenv.net;

namespace _05___Handle_IN_Statement
{
    internal class Program
    {
        private static string _connectionString;

        static string connectionString
        {
            get
            {
                if (_connectionString == null)
                {
                    // Get the absolute path to your .env file (3 levels up from /bin/Debug)
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

        static void DeleteContacts(int[] ContactIDs)
        {
            SqlConnection connection = new SqlConnection(connectionString);

            string query = $@"DELETE FROM Contacts WHERE ContactID IN ({string.Join(",", ContactIDs)})";
            SqlCommand cmd = new SqlCommand(query, connection);

            try
            {
                connection.Open();
                int rowsAffected = cmd.ExecuteNonQuery();

                if (rowsAffected > 0)
                    Console.WriteLine("Record(s) deleted successfully!");
                else
                    Console.WriteLine("Delete failed!");
            }

            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
            }

            finally
            {

                if (connection.State == System.Data.ConnectionState.Open)
                    connection.Close();
            }
        }

        static void Main(string[] args)
        {
            int[] idsToDelete = { 8, 9, 10, 11, 12 };
            DeleteContacts(idsToDelete);

            Console.ReadKey();
        }
    }
}
