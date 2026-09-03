using System;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;

namespace _26___Calling_Stored_Procedures_in_C_
{
    internal class Call_SP_CheckPersonExists
    {
        public static ConnectionStringSettings Settings = ConfigurationManager.ConnectionStrings["DVLD"];

        static void Main(string[] args)
        {
            try
            {
                string connectionString = Settings?.ConnectionString;

                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    using (SqlCommand command = new SqlCommand("SP_CheckPersonExists", connection))
                    {
                        command.CommandType = CommandType.StoredProcedure;

                        command.Parameters.AddWithValue("@PersonID", (object)1028 ?? DBNull.Value);

                        SqlParameter returnParameter = new SqlParameter("@ReturnVal", SqlDbType.Int)
                        {
                            Direction = ParameterDirection.ReturnValue
                        };

                        command.Parameters.Add(returnParameter);
                        connection.Open();
                        command.ExecuteNonQuery();

                        bool personExists = (int)returnParameter.Value == 1;

                        Console.WriteLine($" Person Exist: {personExists}");

                        connection.Close();

                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
        }
    }
}
