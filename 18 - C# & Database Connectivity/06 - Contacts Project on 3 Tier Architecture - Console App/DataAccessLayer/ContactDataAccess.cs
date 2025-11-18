using System;
using System.Data.SqlClient;
using System.Data;

namespace DataAccessLayer
{
    public class ContactDataAccess
    {
        public static bool GetContactInfoByID(int ID, ref string firstName, ref string lastName,
            ref string email, ref string phone, ref string address, 
            ref DateTime dateOfBirth, ref int countryID, ref string imagePath)
        {
            bool isFound = false;

            SqlConnection connection = new SqlConnection(DataAccessSettings.connectionString);
            string query = @"SELECT * FROM Contacts WHERE ContactID = @ContactID";

            SqlCommand cmd = new SqlCommand(query, connection);
            cmd.Parameters.AddWithValue("@ContactID", ID);

            SqlDataReader dataReader = null;

            try
            {
                connection.Open();
                dataReader = cmd.ExecuteReader();

                if (dataReader.Read())
                {
                    isFound = true;

                    firstName = dataReader["FirstName"] != DBNull.Value ? (string)dataReader["FirstName"] : "";
                    lastName = dataReader["LastName"] != DBNull.Value ? (string)dataReader["LastName"] : "";
                    email = dataReader["Email"] != DBNull.Value ? (string)dataReader["Email"] : "";
                    phone = dataReader["Phone"] != DBNull.Value ? (string)dataReader["Phone"] : "";
                    address = dataReader["Address"] != DBNull.Value ? (string)dataReader["Address"] : "";
                    dateOfBirth = dataReader["DateOfBirth"] != DBNull.Value ? (DateTime)dataReader["DateOfBirth"] : DateTime.MinValue;
                    countryID = dataReader["CountryID"] != DBNull.Value ? (int)dataReader["CountryID"] : -1;
                    imagePath = dataReader["ImagePath"] != DBNull.Value ? (string)dataReader["ImagePath"] : "";
                }
            }

            catch (Exception ex) 
            {
                isFound = false;
            }

            finally
            {
                if (connection.State == System.Data.ConnectionState.Open)
                    connection.Close();

                dataReader.Close();
            }

            return isFound;
        }

        public static int AddNewContact(string firstName, string lastName,
            string email, string phone, string address,
            DateTime dateOfBirth, int countryID, string imagePath)
        {
            int contactID = -1;

            SqlConnection connection = new SqlConnection(DataAccessSettings.connectionString);

            string query = @"INSERT INTO Contacts (FirstName, LastName, Email, Phone, Address,DateOfBirth, CountryID,ImagePath)
                             VALUES (@FirstName, @LastName, @Email, @Phone, @Address,@DateOfBirth, @CountryID,@ImagePath);
                             SELECT SCOPE_IDENTITY();";

            SqlCommand command = new SqlCommand(query, connection);
            command.Parameters.AddWithValue("@FirstName", firstName);
            command.Parameters.AddWithValue("@LastName", lastName);
            command.Parameters.AddWithValue("@Email", email);
            command.Parameters.AddWithValue("@Phone", phone);
            command.Parameters.AddWithValue("@Address", address);
            command.Parameters.AddWithValue("@DateOfBirth", dateOfBirth);
            command.Parameters.AddWithValue("@CountryID", countryID);

            if (imagePath != "")
                command.Parameters.AddWithValue("@ImagePath", imagePath);
            else
                command.Parameters.AddWithValue("@ImagePath", DBNull.Value);

            try
            {
                connection.Open();

                object result = command.ExecuteScalar();


                if (result != null && int.TryParse(result.ToString(), out int insertedID))
                {
                    contactID = insertedID;
                }
            }

            catch (Exception ex)
            {
                //Console.WriteLine("Error: " + ex.Message);

            }

            finally
            {
                connection.Close();
            }

            return contactID;
        }

        public static bool UpdateContact(int contactID, string firstName, string lastName,
            string email, string phone, string address,
            DateTime dateOfBirth, int countryID, string imagePath)
        {
            int rowsAffected = 0;
            SqlConnection connection = new SqlConnection(DataAccessSettings.connectionString);

            string query = @"UPDATE  Contacts  
                            SET FirstName = @FirstName, 
                                LastName = @LastName, 
                                Email = @Email, 
                                Phone = @Phone, 
                                Address = @Address, 
                                DateOfBirth = @DateOfBirth,
                                CountryID = @CountryID,
                                ImagePath =@ImagePath
                            WHERE 
                                ContactID = @ContactID";

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@ContactID", contactID);
            command.Parameters.AddWithValue("@FirstName", firstName);
            command.Parameters.AddWithValue("@LastName", lastName);
            command.Parameters.AddWithValue("@Email", email);
            command.Parameters.AddWithValue("@Phone", phone);
            command.Parameters.AddWithValue("@Address", address);
            command.Parameters.AddWithValue("@DateOfBirth", dateOfBirth);
            command.Parameters.AddWithValue("@CountryID", countryID);

            if (imagePath != "")
                command.Parameters.AddWithValue("@ImagePath", imagePath);
            else
                command.Parameters.AddWithValue("@ImagePath", DBNull.Value);

            try
            {
                connection.Open();
                rowsAffected = command.ExecuteNonQuery();
            }
            catch (Exception ex) 
            {
                // log file
                return false;
            }
            finally
            {
                if (connection.State == System.Data.ConnectionState.Open)
                    connection.Close();
            }

            return rowsAffected > 0;
        }

        public static bool DeleteContactByID(int contactID)
        {
            int rowsAffected = 0;
            SqlConnection connection = new SqlConnection(DataAccessSettings.connectionString);

            string query = @"DELETE FROM Contacts WHERE ContactID = @ContactID";
            
            SqlCommand cmd = new SqlCommand(query, connection);
            cmd.Parameters.AddWithValue("@ContactID", contactID);

            try
            {
                connection.Open();
                rowsAffected = cmd.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                // log file
                return false;
            }
            finally
            {
                if (connection.State == System.Data.ConnectionState.Open)
                    connection.Close();
            }

            return rowsAffected > 0;
        }

        public static DataTable GetAllContacts()
        {
            DataTable dt = new DataTable();
            SqlConnection connection = new SqlConnection(DataAccessSettings.connectionString);

            string query = @"SELECT * FROM Contacts";
            SqlCommand command = new SqlCommand(query, connection);

            try
            {
                connection.Open();
                SqlDataReader dataReader = command.ExecuteReader();

                if (dataReader.HasRows)
                    dt.Load(dataReader);

                dataReader.Close();
            }
            catch (Exception ex) 
            { 
            }

            finally
            {
                if (connection.State == System.Data.ConnectionState.Open)
                    connection.Close();
            }

            return dt;
        }

        public static bool IsExist(int contactID)
        {
            bool isFound = false;
            SqlConnection connection = new SqlConnection(DataAccessSettings.connectionString);

            string query = @"SELECT Found = 1 FROM Contacts WHERE ContactID = @ContactID";

            SqlCommand cmd = new SqlCommand(query, connection);
            cmd.Parameters.AddWithValue("@ContactID", contactID);

            try
            {
                connection.Open();
                object result = cmd.ExecuteScalar();

                if (result != null)
                    isFound = true;
            }

            catch (Exception ex) { }

            finally
            {
                if (connection.State == System.Data.ConnectionState.Open)
                    connection.Close();
            }

            return isFound;
        }
    }
}
