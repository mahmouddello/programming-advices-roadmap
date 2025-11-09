using dotenv.net;
using System;
using System.Data.SqlClient;
using System.IO;

namespace _01___DBConnection___SimpleQueries
{
    internal class ParametrizedQueryWithLike
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
        static void SearchContactsStartsWith(string StartsWith)
        {

            SqlConnection connection = new SqlConnection(connectionString);

            string query = "SELECT * FROM Contacts WHERE FirstName LIKE '' + @StartsWith +'%'";


            SqlCommand command = new SqlCommand(query, connection);
            command.Parameters.AddWithValue("@StartsWith", StartsWith);

            try
            {
                connection.Open();

                SqlDataReader reader = command.ExecuteReader();

                while (reader.Read())
                {
                    int contactID = (int)reader["ContactID"];
                    string firstName = (string)reader["FirstName"];
                    string lastName = (string)reader["LastName"];
                    string email = (string)reader["Email"];
                    string phone = (string)reader["Phone"];
                    string address = (string)reader["Address"];
                    int countryID = (int)reader["CountryID"];

                    Console.WriteLine($"Contact ID: {contactID}");
                    Console.WriteLine($"Name: {firstName} {lastName}");
                    Console.WriteLine($"Email: {email}");
                    Console.WriteLine($"Phone: {phone}");
                    Console.WriteLine($"Address: {address}");
                    Console.WriteLine($"Country ID: {countryID}");
                    Console.WriteLine();
                }

                reader.Close();
                connection.Close();

            }


            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
            }


        }

        static void SearchContactsEndsWith(string EndsWith)
        {

            SqlConnection connection = new SqlConnection(connectionString);

            string query = "SELECT * FROM Contacts WHERE FirstName LIKE '%' + @EndsWith + ''";


            SqlCommand command = new SqlCommand(query, connection);
            command.Parameters.AddWithValue("@EndsWith", EndsWith);

            try
            {
                connection.Open();

                SqlDataReader reader = command.ExecuteReader();

                while (reader.Read())
                {
                    int contactID = (int)reader["ContactID"];
                    string firstName = (string)reader["FirstName"];
                    string lastName = (string)reader["LastName"];
                    string email = (string)reader["Email"];
                    string phone = (string)reader["Phone"];
                    string address = (string)reader["Address"];
                    int countryID = (int)reader["CountryID"];

                    Console.WriteLine($"Contact ID: {contactID}");
                    Console.WriteLine($"Name: {firstName} {lastName}");
                    Console.WriteLine($"Email: {email}");
                    Console.WriteLine($"Phone: {phone}");
                    Console.WriteLine($"Address: {address}");
                    Console.WriteLine($"Country ID: {countryID}");
                    Console.WriteLine();
                }

                reader.Close();
                connection.Close();

            }


            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
            }


        }

        static void SearchContactsContains(string Contains)
        {

            SqlConnection connection = new SqlConnection(connectionString);

            string query = "SELECT * FROM Contacts WHERE FirstName LIKE '%' + @Contains + '%'";


            SqlCommand command = new SqlCommand(query, connection);
            command.Parameters.AddWithValue("@Contains", Contains);

            try
            {
                connection.Open();

                SqlDataReader reader = command.ExecuteReader();

                while (reader.Read())
                {
                    int contactID = (int)reader["ContactID"];
                    string firstName = (string)reader["FirstName"];
                    string lastName = (string)reader["LastName"];
                    string email = (string)reader["Email"];
                    string phone = (string)reader["Phone"];
                    string address = (string)reader["Address"];
                    int countryID = (int)reader["CountryID"];

                    Console.WriteLine($"Contact ID: {contactID}");
                    Console.WriteLine($"Name: {firstName} {lastName}");
                    Console.WriteLine($"Email: {email}");
                    Console.WriteLine($"Phone: {phone}");
                    Console.WriteLine($"Address: {address}");
                    Console.WriteLine($"Country ID: {countryID}");
                    Console.WriteLine();
                }

                reader.Close();
                connection.Close();

            }


            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
            }


        }

        public static void Main()
        {

            Console.WriteLine("--------Contacts starts with 'j'");

            SearchContactsStartsWith("j");

            Console.WriteLine("-------Contacts Ends with 'ne'");
            SearchContactsEndsWith("ne");

            Console.WriteLine("-------Contacts Contains with 'ae'");
            SearchContactsContains("ae");

            Console.ReadKey();
        }
    }
}
