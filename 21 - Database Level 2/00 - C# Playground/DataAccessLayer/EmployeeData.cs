using System;
using System.Data;
using System.Data.SqlClient;

namespace DataAccessLayer
{
    public class EmployeeData
    {
        public static DataTable GetAllEmployees()
        {
            DataTable dt = new DataTable();
            string query = @"SELECT * FROM Employees2";

            using (SqlConnection connection = new SqlConnection(Settings.ConnectionString))
            {
                using (SqlCommand command = new SqlCommand(query, connection))
                {
                    try
                    {
                        connection.Open();

                        using (SqlDataReader reader = command.ExecuteReader())
                        {
                            if (reader.HasRows)
                                dt.Load(reader);
                        }
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine($"Error occurred: {ex.Message}");
                    }
                }
            }

            return dt.Rows.Count > 0 ? dt : null;
        }

        public static bool GetEmployeeByName(string name, ref string departmentName, ref int salary, ref int performanceRating)
        {
            bool isFound = false;
            string query = @"SELECT * FROM Employees2 WHERE Name = @Name";

            using (SqlConnection connection = new SqlConnection(Settings.ConnectionString))
            {
                using (SqlCommand command = new SqlCommand(query, connection))
                {
                    try
                    {
                        connection.Open();
                        command.Parameters.AddWithValue("@Name", name);

                        using (SqlDataReader reader = command.ExecuteReader())
                        {
                            if (reader.Read())
                            {
                                isFound = true;
                                departmentName = (string)reader["Department"];
                                salary = (int)reader["Salary"];
                                performanceRating = (int)reader["PerformanceRating"];
                            }
                        }
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine($"Error occurred: {ex.Message}");
                    }
                }
            }

            return isFound;
        }

        public static bool UpdateEmployeeSalary(string name, int newSalary)
        {
            int rowsAffected = 0;
            string query = @"UPDATE Employees2 SET Salary = @NewSalary WHERE Name = @Name";

            using (SqlConnection connection = new SqlConnection(Settings.ConnectionString))
            {
                using (SqlCommand command = new SqlCommand(query, connection))
                {
                    command.Parameters.AddWithValue("@Name", name);
                    command.Parameters.AddWithValue("@NewSalary", newSalary);

                    try
                    {
                        connection.Open();
                        rowsAffected = command.ExecuteNonQuery();
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine($"Exception occurred: {ex.Message}");
                    }
                }
            }

            return rowsAffected > 0;
        }
    }
}
