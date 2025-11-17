using System;
using System.Data.SqlClient;

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
    }
}
