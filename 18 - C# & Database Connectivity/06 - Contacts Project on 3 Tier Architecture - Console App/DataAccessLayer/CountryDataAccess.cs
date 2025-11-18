using System;
using System.Data;
using System.Data.SqlClient;
using System.Runtime.Remoting.Messaging;

namespace DataAccessLayer
{
    public class CountryDataAccess
    {
        public static bool GetCountryByName(ref string countryName, ref int countryID, ref string countryCode, ref string phoneCode)
        {

            bool isFound = false;

            SqlConnection connection = new SqlConnection(DataAccessSettings.connectionString);
            string query = @"SELECT * FROM Countries WHERE CountryName = @CountryName";

            SqlCommand cmd = new SqlCommand(query, connection);
            cmd.Parameters.AddWithValue("@CountryName", countryName);

            SqlDataReader reader = null;

            try
            {
                connection.Open();
                reader = cmd.ExecuteReader();

                if (reader.Read())
                {
                    isFound = true;

                    countryID = reader["CountryID"] != DBNull.Value ? (int)reader["CountryID"] : -1;
                    countryName = reader["CountryName"] != DBNull.Value ? (string)reader["CountryName"] : "";
                    countryCode = reader["CountryCode"] != DBNull.Value ? (string)reader["CountryCode"] : "";
                    phoneCode = reader["PhoneCode"] != DBNull.Value ? (string)reader["PhoneCode"] : "";
                }
            }

            catch (Exception ex)
            {
                
            }

            finally
            {
                if (connection.State == System.Data.ConnectionState.Open)
                    connection.Close();

                reader.Close();
            }

            return isFound;
        }

        public static bool GetCountryByID(int countryID, ref string countryName, ref string countryCode, ref string phoneCode)
        {
            bool isFound = false;

            SqlConnection connection = new SqlConnection(DataAccessSettings.connectionString);
            string query = @"SELECT * FROM Countries WHERE CountryID = @CountryID";

            SqlCommand cmd = new SqlCommand(query, connection);
            cmd.Parameters.AddWithValue("@CountryID", countryID);

            SqlDataReader reader = null;

            try
            {
                connection.Open();
                reader = cmd.ExecuteReader();

                if (reader.Read())
                {
                    isFound = true;
                    countryName = reader["CountryName"] != DBNull.Value ? (string)reader["CountryName"] : "";
                    countryCode = reader["CountryCode"] != DBNull.Value ? (string)reader["CountryCode"] : "";
                    phoneCode =  reader["PhoneCode"] != DBNull.Value ? (string)reader["PhoneCode"] : "";
                }
            }

            catch (Exception ex)
            {

            }

            finally
            {
                if (connection.State == System.Data.ConnectionState.Open)
                    connection.Close();

                reader.Close();
            }

            return isFound;
        }

        public static bool IsExistsByName(string countryName)
        {
            bool found = false;

            SqlConnection connection = new SqlConnection(DataAccessSettings.connectionString);
            string query = @"SELECT Found = 1 FROM Countries WHERE CountryName = @CountryName";

            SqlCommand cmd = new SqlCommand(query, connection);
            cmd.Parameters.AddWithValue("@CountryName", countryName);

            try
            {
                connection.Open();
                object result = cmd.ExecuteScalar();

                if (result != null)
                    found = true;
            }

            catch (Exception ex)
            {

            }

            finally
            {
                if (connection.State == System.Data.ConnectionState.Open)
                    connection.Close();
            }

            return found;
        }

        public static bool IsExistsByID(int countryID)
        {
            bool found = false;

            SqlConnection connection = new SqlConnection(DataAccessSettings.connectionString);
            string query = @"SELECT Found = 1 FROM Countries WHERE CountryID = @CountryID";

            SqlCommand cmd = new SqlCommand(query, connection);
            cmd.Parameters.AddWithValue("@CountryID", countryID);

            try
            {
                connection.Open();
                object result = cmd.ExecuteScalar();

                if (result != null)
                    found = true;
            }

            catch (Exception ex)
            {

            }

            finally
            {
                if (connection.State == System.Data.ConnectionState.Open)
                    connection.Close();
            }

            return found;
        }

        public static int AddNewCountry(string countryName, string countryCode, string phoneCode)
        {
            int countryID = -1;

            SqlConnection connection = new SqlConnection(DataAccessSettings.connectionString);
            string query = @"INSERT INTO Countries
                            (CountryName, CountryCode, PhoneCode)
                            VALUES (@CountryName, @CountryCode, @PhoneCode);
                            SELECT SCOPE_IDENTITY();";

            SqlCommand command = new SqlCommand(query, connection);
            command.Parameters.AddWithValue("@CountryName", countryName);
            command.Parameters.AddWithValue("@CountryCode", countryCode);
            command.Parameters.AddWithValue("@PhoneCode", phoneCode);

            try
            {
                connection.Open();
                object result = command.ExecuteScalar();

                if (result != null && int.TryParse(result.ToString(), out int insertedID))
                    countryID = insertedID;
            }

            catch (Exception ex)
            {

            }
            finally
            {
                connection.Close();
            }

            return countryID;
        }

        public static bool UpdateCountry(int countryID, string newCountryName, string newCountryCode, string newPhoneCode)
        {
            int rowsAffected = 0;
            SqlConnection connection = new SqlConnection(DataAccessSettings.connectionString);

            string query = @"UPDATE Countries 
                             SET 
                             CountryName = @CountryName,
                             CountryCode = @CountryCode,
                             PhoneCode = @PhoneCode
                             WHERE 
                                CountryID = @CountryID";
            
            SqlCommand cmd = new SqlCommand(query, connection);
            cmd.Parameters.AddWithValue("@CountryName", newCountryName);
            cmd.Parameters.AddWithValue("@CountryID", countryID);
            cmd.Parameters.AddWithValue("@CountryCode", newCountryCode);
            cmd.Parameters.AddWithValue("@PhoneCode", newPhoneCode);

            try
            {
                connection.Open();
                rowsAffected = cmd.ExecuteNonQuery();
            }

            catch (Exception ex)
            {

            }

            finally
            {
                if (connection.State == System.Data.ConnectionState.Open)
                    connection.Close();
            }

            return rowsAffected > 0;
        }

        public static bool DeleteCountry(int countryID)
        {
            int rowsAffected = 0;
            SqlConnection connection = new SqlConnection(DataAccessSettings.connectionString);

            string query = @"DELETE FROM Countries WHERE CountryID = @CountryID";

            SqlCommand cmd = new SqlCommand(query, connection);
            cmd.Parameters.AddWithValue("@CountryID", countryID);

            try
            {
                connection.Open();
                rowsAffected = cmd.ExecuteNonQuery();
            }

            catch (Exception ex)
            {

            }

            finally
            {
                if (connection.State == System.Data.ConnectionState.Open)
                    connection.Close();
            }

            return rowsAffected > 0;
        }

        public static DataTable GetAllCountries()
        {
            DataTable dt = new DataTable();
            SqlConnection connection = new SqlConnection(DataAccessSettings.connectionString);

            string query = @"SELECT * FROM Countries";
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

    }
}
