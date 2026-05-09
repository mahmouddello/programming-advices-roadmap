using System;
using System.Security.Cryptography;
using System.Text;

namespace _18___Introduction_to_Cryptography
{
    internal class HashingExample
    {
        static void Main(string[] args)
        {
            // Input
            string name = "1234";

            // Hashing Output
            string hashedName = ComputeHash(name);

            Console.WriteLine($"Raw Name:{name}\nHashed Name: {hashedName}");
            Console.WriteLine($"Hashed Data Length: {hashedName.Length}"); // SHA256 = 256 bit / 4 = 64 Hexadecimal
        }

        private static string ComputeHash(string name)
        {
            // SHA256 produces 256 bit hash, but only 64 on screen because it's in hexadecimal
            using (SHA256 sha256 = SHA256.Create())
            {
                // compute the hash value from the UTF-8 encoded input string
                byte[] bytes = sha256.ComputeHash(Encoding.UTF8.GetBytes(name));

                // Convert the byte array to a lowercase, and replace hyphens '-' with blank ''
                return BitConverter.ToString(bytes).Replace("-", "").ToLower();
            }
        }
    }
}
