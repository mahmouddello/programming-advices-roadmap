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
    internal class ParametrizedQuery
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

        static void PrintAllContactsWithFirstName(string firstNameP)
        {
            SqlConnection sqlConnection = new SqlConnection(connectionString);
            string query = "SELECT * FROM Contacts WHERE FirstName = @firstNameP";

            SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);
            sqlCommand.Parameters.AddWithValue("@firstNameP", firstNameP);

            SqlDataReader dataReader = null;

            // always use try-catch with database connection
            try
            {
                sqlConnection.Open();
                dataReader = sqlCommand.ExecuteReader();

                while (dataReader.Read())
                {
                    int contactID = (int)dataReader["ContactID"];
                    string firstName = (string)dataReader["FirstName"];
                    string lastName = (string)dataReader["LastName"];
                    string email = (string)dataReader["Email"];
                    string phone = (string)dataReader["Phone"];
                    string address = (string)dataReader["Address"];
                    int countryID = (int)dataReader["countryID"];

                    Console.WriteLine($"ContactID: {contactID}");
                    Console.WriteLine($"Name: {firstName} {lastName}");
                    Console.WriteLine($"Email: {email}");
                    Console.WriteLine($"Phone: {phone}");
                    Console.WriteLine($"Address: {address}");
                    Console.WriteLine($"CountryID: {countryID}");
                    Console.WriteLine("\n------------------------\n");
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }

            finally
            {
                // Always close in finally
                if (dataReader != null && !dataReader.IsClosed)
                    dataReader.Close();

                if (sqlConnection.State == System.Data.ConnectionState.Open)
                    sqlConnection.Close();
            }
        }

        static void PrintAllContactsWithFirstNameAndCountryID(string firstNameP, int countryIDp)
        {
            SqlConnection sqlConnection = new SqlConnection(connectionString);
            string query = "SELECT * FROM Contacts WHERE FirstName = @firstNameP AND CountryID = @countryIDp";

            SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);
            sqlCommand.Parameters.AddWithValue("@firstNameP", firstNameP);
            sqlCommand.Parameters.AddWithValue("@countryIDp", countryIDp);

            SqlDataReader dataReader = null;

            // always use try-catch with database connection
            try
            {
                sqlConnection.Open();
                dataReader = sqlCommand.ExecuteReader();

                while (dataReader.Read())
                {
                    int contactID = (int)dataReader["ContactID"];
                    string firstName = (string)dataReader["FirstName"];
                    string lastName = (string)dataReader["LastName"];
                    string email = (string)dataReader["Email"];
                    string phone = (string)dataReader["Phone"];
                    string address = (string)dataReader["Address"];
                    int countryID = (int)dataReader["countryID"];

                    Console.WriteLine($"ContactID: {contactID}");
                    Console.WriteLine($"Name: {firstName} {lastName}");
                    Console.WriteLine($"Email: {email}");
                    Console.WriteLine($"Phone: {phone}");
                    Console.WriteLine($"Address: {address}");
                    Console.WriteLine($"CountryID: {countryID}");
                    Console.WriteLine("\n------------------------\n");
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }

            finally
            {
                // Always close in finally
                if (dataReader != null && !dataReader.IsClosed)
                    dataReader.Close();

                if (sqlConnection.State == System.Data.ConnectionState.Open)
                    sqlConnection.Close();
            }
        }


        static void Main(string[] args)
        {
            //PrintAllContactsWithFirstName("jane");
            PrintAllContactsWithFirstNameAndCountryID("jane", 1);
            Console.ReadKey();
        }
    }
}
