using dotenv.net;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.IO;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;

namespace _01___DBConnection___SimpleQueries
{
    internal class FindSingleContact
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

        static bool FindContactByID(int ContactID, ref stContact ContactInfo)
        {
            bool isFound = false;

            SqlConnection connection = new SqlConnection(connectionString);
            SqlDataReader reader = null;

            string query = "SELECT * FROM Contacts WHERE ContactID = @ContactID";

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@ContactID", ContactID);

            try
            {
                connection.Open();
                reader = command.ExecuteReader();

                if (reader.Read())
                {

                    // The record was found
                    isFound = true;
                    ContactInfo.ID = (int)reader["ContactID"];
                    ContactInfo.FirstName = (string)reader["FirstName"];
                    ContactInfo.LastName = (string)reader["LastName"];
                    ContactInfo.Email = (string)reader["Email"];
                    ContactInfo.Phone = (string)reader["Phone"];
                    ContactInfo.Address = (string)reader["Address"];
                    ContactInfo.CountryID = (int)reader["CountryID"];

                }
                else
                {
                    // The record was not found
                    isFound = false;
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
            }

            finally
            {
                reader.Close();
                connection.Close();
            }

            return isFound;

        }
        public struct stContact
        {
            public int ID { get; set; }
            public string FirstName { get; set; }
            public string LastName { get; set; }
            public string Email { get; set; }
            public string Phone { get; set; }
            public string Address { get; set; }
            public int CountryID { get; set; }
        }

        public static void Main()
        {

            stContact ContactInfo = new stContact();

            if (FindContactByID(1, ref ContactInfo))
            {

                Console.WriteLine($"\nContact ID: {ContactInfo.ID}");
                Console.WriteLine($"Name: {ContactInfo.FirstName} {ContactInfo.LastName}");
                Console.WriteLine($"Email: {ContactInfo.Email}");
                Console.WriteLine($"Phone: {ContactInfo.Phone}");
                Console.WriteLine($"Address: {ContactInfo.Address}");
                Console.WriteLine($"Country ID: {ContactInfo.CountryID}");

            }
            else
            {
                Console.WriteLine("Contact is not found");
            }
            Console.ReadKey();
        }
    }
}
