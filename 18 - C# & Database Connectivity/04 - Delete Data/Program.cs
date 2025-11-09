using System;
using System.Data.SqlClient;
using System.IO;
using dotenv.net;

namespace _04___Delete_Data
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

        static void DeleteContactByID(int ContactID)
        {
            SqlConnection connection = new SqlConnection(connectionString);
            string query = @"DELETE FROM Contacts WHERE ContactID = @ContactID";

            SqlCommand cmd = new SqlCommand(query, connection);
            cmd.Parameters.AddWithValue("@ContactID", ContactID);

            try
            {
                connection.Open();
                int rowsAffected = cmd.ExecuteNonQuery();

                if (rowsAffected > 0)
                    Console.WriteLine("Record deleted successfully!");
                else
                    Console.WriteLine("Deletion failed!");
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
            DeleteContactByID(14);
            Console.ReadKey();
        }
    }
}
