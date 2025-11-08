using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _02___Insert_Data
{
    internal class Program
    {
        public struct stContact
        {
            public string FirstName { get; set; }
            public string LastName { get; set; }
            public string Email { get; set; }
            public string Phone { get; set; }
            public string Address { get; set; }
            public int CountryID { get; set; }
        }

        static string connectionString = "Server=.;Database=ContactsDB;User Id=sa;Password=sa123456";

        static void AddNewContact(stContact newContact)
        {
            SqlConnection connection = new SqlConnection(connectionString);
            string query = @"INSERT INTO Contacts  (FirstName, LastName, Email, Phone, Address, CountryID)
                            VALUES (@FirstName, @LastName, @Email, @Phone, @Address, @CountryID)";

            SqlCommand cmd = new SqlCommand(query, connection);

            cmd.Parameters.AddWithValue("@FirstName", newContact.FirstName);
            cmd.Parameters.AddWithValue("@LastName", newContact.LastName);
            cmd.Parameters.AddWithValue("@Email", newContact.Email);
            cmd.Parameters.AddWithValue("@Phone", newContact.Phone);
            cmd.Parameters.AddWithValue("@Address", newContact.Address);
            cmd.Parameters.AddWithValue("@CountryID", newContact.CountryID);

            try
            {
                connection.Open();
                int rowsAffected = cmd.ExecuteNonQuery();

                if (rowsAffected > 0)
                    Console.WriteLine("Record inserted successfully");
                else
                    Console.WriteLine("Record insertion failed");
            }

            catch (Exception ex)
            { 
                Console.WriteLine(ex.ToString()); 
            }

            finally
            {
               if (connection.State == System.Data.ConnectionState.Open)
                    connection.Close();
            }
        }

        static void AddNewContactAndGetID(stContact newContact)
        {
            SqlConnection connection = new SqlConnection(connectionString);
            string query = @"INSERT INTO Contacts  (FirstName, LastName, Email, Phone, Address, CountryID)
                            VALUES (@FirstName, @LastName, @Email, @Phone, @Address, @CountryID);
                            SELECT SCOPE_IDENTITY();";

            SqlCommand cmd = new SqlCommand(query, connection);
            cmd.Parameters.AddWithValue("@FirstName", newContact.FirstName);
            cmd.Parameters.AddWithValue("@LastName", newContact.LastName);
            cmd.Parameters.AddWithValue("@Email", newContact.Email);
            cmd.Parameters.AddWithValue("@Phone", newContact.Phone);
            cmd.Parameters.AddWithValue("@Address", newContact.Address);
            cmd.Parameters.AddWithValue("@CountryID", newContact.CountryID);

            try
            {
                connection.Open();
                object result = cmd.ExecuteScalar();

                if (result != null && int.TryParse(result.ToString(), out int insertedID))
                    Console.WriteLine($"Newly inserted record's ID: {insertedID}");
                else
                    Console.WriteLine("Failed to retrieve last inserted record's ID");
            }

            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }

            finally
            {
                if (connection.State == System.Data.ConnectionState.Open)
                    connection.Close();
            }
        }


        static void Main(string[] args)
        {
            stContact contact = new stContact
            {
                FirstName = "Mahmoud",
                LastName = "Dello",
                Email = "mahmoddello68@gmail.com",
                Phone = "123-456-789",
                Address = "123 Main Street Mannhaten",
                CountryID = 1
            };

            AddNewContact(contact);
            AddNewContactAndGetID(contact);
            Console.ReadKey();
        }
    }
}
