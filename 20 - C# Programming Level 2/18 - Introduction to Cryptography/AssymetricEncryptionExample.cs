using System;
using System.Security.Cryptography;
using System.Text;

namespace _18___Introduction_to_Cryptography
{
    public class AssymetricEncryptionExample
    {
        static void Main()
        {
            try
            {
                // Generate public and private key pair
                using (RSACryptoServiceProvider rsa = new RSACryptoServiceProvider())
                {
                    /*
                     Get the public key
                     When exporting the public key, ToXmlString(false) is used with the argument set 
                     to false to indicate that only the public parameters should be included in the XML string.
                     */
                    string publicKey = rsa.ToXmlString(includePrivateParameters: false);


                    // Get the private key
                    string privateKey = rsa.ToXmlString(includePrivateParameters: true);


                    // Original message
                    string originalMessage = "Hello, this is a secret message!";


                    // Encrypt using the public key
                    string encryptedMessage = Encrypt(originalMessage, publicKey);


                    // Decrypt using the private key
                    string decryptedMessage = Decrypt(encryptedMessage, privateKey);


                    // Display the results
                    Console.WriteLine($"Public Key:\n {publicKey}");
                    Console.WriteLine($"\n\nPrivate Key:\n {privateKey}");
                    Console.WriteLine($"\nOriginal Message:\n {originalMessage}");
                    Console.WriteLine($"\nEncrypted Message:\n {encryptedMessage}");
                    Console.WriteLine($"\nDecrypted Message:\n {decryptedMessage}");


                    // Wait for user input before closing the console window
                    Console.WriteLine("\nPress any key to exit...");
                    Console.ReadKey();
                }
            }
            catch (CryptographicException ex)
            {
                Console.WriteLine($"Encryption/Decryption error: {ex.Message}");
                Console.ReadKey();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"An unexpected error occurred: {ex.Message}");
                Console.ReadKey();
            }
        }

        static string Encrypt(string plainText, string publicKey)
        {
            try
            {
                using (RSACryptoServiceProvider rsa = new RSACryptoServiceProvider())
                {
                    rsa.FromXmlString(publicKey);


                    byte[] encryptedData = rsa.Encrypt(Encoding.UTF8.GetBytes(plainText), false);
                    return Convert.ToBase64String(encryptedData);
                }
            }
            catch (CryptographicException ex)
            {
                Console.WriteLine($"Encryption error: {ex.Message}");
                throw; // Rethrow the exception to be caught in the Main method
            }
        }

        static string Decrypt(string cipherText, string privateKey)
        {
            try
            {
                using (RSACryptoServiceProvider rsa = new RSACryptoServiceProvider())
                {
                    rsa.FromXmlString(privateKey);


                    byte[] encryptedData = Convert.FromBase64String(cipherText);
                    byte[] decryptedData = rsa.Decrypt(encryptedData, false);


                    return Encoding.UTF8.GetString(decryptedData);
                }
            }
            catch (CryptographicException ex)
            {
                Console.WriteLine($"Decryption error: {ex.Message}");
                throw; // Rethrow the exception to be caught in the Main method
            }
        }
    }
}