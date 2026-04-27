using System;
using Microsoft.Win32;

namespace _14___Windows_Registry
{
    public class Program
    {
        private static readonly string CURRENT_USER_PATH = @"HKEY_CURRENT_USER\SOFTWARE\";
        private static readonly string LOCAL_MACHINE_PATH = @"HKEY_LOCAL_MACHINE\SOFTWARE\";

        static void WriteToRegistry(string keyPath, string valueName, string valueData)
        {
            try
            {
                // Write the value to the Registry
                Registry.SetValue(keyPath, valueName, valueData, RegistryValueKind.String);
                Console.WriteLine($"Value {valueName} successfully written to the Registry.");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"An error occurred: {ex.Message}");
            }
        }

        static void ReadFromRegistry(string keyPath, string valueName)
        {
            try
            {
                // Read the value from the Registry
                string value = Registry.GetValue(keyPath, valueName, null) as string;

                if (value != null)
                {
                    Console.WriteLine($"The value of {valueName} is: {value}");
                }
                else
                {
                    Console.WriteLine($"Value {valueName} not found in the Registry.");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"An error occurred: {ex.Message}");
            };
        }

        static void Main(string[] args)
        {
            string koko = string.Concat(CURRENT_USER_PATH, "Koko");
            //WriteToRegistry(koko, "MyKoko", "MyKokoValue");

            //Console.WriteLine(new string('-', 50));
            //ReadFromRegistry(koko, "MyKoko");

            string koko2 = string.Concat(LOCAL_MACHINE_PATH, "Koko");
            WriteToRegistry(koko2, "MyKoko3", "koko3");
        }
    }
}
