using System;
using System.Configuration;
using System.Data.SqlClient;
using System.Data;

namespace _26___Calling_Stored_Procedures_in_C_
{
    internal class Call_SP_AddNewPerson2
    {
        public static ConnectionStringSettings Settings = ConfigurationManager.ConnectionStrings["DVLD"];

        static void Main(string[] args)
        {
            string connectionString = Settings?.ConnectionString;

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                using (SqlCommand command = new SqlCommand("SP_AddNewPerson2", connection))
                {
                    command.CommandType = CommandType.StoredProcedure;
                    command.Parameters.AddWithValue("@NationalNo", "4004A");
                    command.Parameters.AddWithValue("@FirstName", "John");
                    command.Parameters.AddWithValue("@SecondName", "Alexander");
                    command.Parameters.AddWithValue("@LastName", "Doe");
                    command.Parameters.AddWithValue("@DateOfBirth", new DateTime(1999, 1, 1));
                    command.Parameters.AddWithValue("@Gender", 0);
                    command.Parameters.AddWithValue("@Address", "Washignton, USA");
                    command.Parameters.AddWithValue("@Phone", "+1 234-567-89");
                    command.Parameters.AddWithValue("@NationalityCountryID", 185);

                    SqlParameter outputIdParam = new SqlParameter("@NewPersonID", SqlDbType.Int)
                    {
                        Direction = ParameterDirection.Output
                    };

                    command.Parameters.Add(outputIdParam);

                    // Execute
                    connection.Open();
                    command.ExecuteNonQuery();

                    // Retrieve the ID of the new person
                    int newPersonID = (int)command.Parameters["@NewPersonID"].Value;
                    Console.WriteLine($"New Person ID: {newPersonID}");
                }
            }
        }
    }
}
