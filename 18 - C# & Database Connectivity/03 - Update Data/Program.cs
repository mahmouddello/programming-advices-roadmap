using System;
using System.Data.SqlClient;

namespace _03___Update_Data
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

        static void UpdateContact(int contactID,  stContact newContact)
        {
            SqlConnection connection = new SqlConnection(connectionString);
            string query = @"UPDATE Contacts
                            SET 
                                FirstName = @FirstName,
                                LastName = @LastName,
                                Email = @Email,
                                Phone = @Phone,
                                Address = @Address,
                                CountryID = @CountryID
                            WHERE
                                ContactID = @ContactID";

            SqlCommand cmd = new SqlCommand(query, connection);

            cmd.Parameters.AddWithValue("@FirstName", newContact.FirstName);
            cmd.Parameters.AddWithValue("@LastName", newContact.LastName);
            cmd.Parameters.AddWithValue("@Email", newContact.Email);
            cmd.Parameters.AddWithValue("@Phone", newContact.Phone);
            cmd.Parameters.AddWithValue("@Address", newContact.Address);
            cmd.Parameters.AddWithValue("@CountryID", newContact.CountryID);
            cmd.Parameters.AddWithValue("@ContactID", contactID);

            try
            {
                connection.Open();
                int rowsAffected = cmd.ExecuteNonQuery();

                if (rowsAffected > 0)
                    Console.WriteLine("Record updated successfully");
                else
                    Console.WriteLine("Record update failed");
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
                FirstName = "Anas",
                LastName = "Dello",
                Email = "anas@email.com",
                Phone = "123-456-789",
                Address = "123 Main Street Damascus",
                CountryID = 2
            };

            UpdateContact(1, contact);
            Console.ReadKey();
        }
    }
}
