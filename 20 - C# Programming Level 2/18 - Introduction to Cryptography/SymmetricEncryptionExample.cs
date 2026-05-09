using System;
using System.Text;
using System.Security.Cryptography;
using System.IO;

namespace _18___Introduction_to_Cryptography
{
    internal class SymmetricEncryptionExample
    {
        static void Main()
        {
            // Original data
            string originalData = "Sensitive information";


            // Key for AES encryption (128-bit key)
            string key = "1234566789123456";


            // Encrypt the original data
            string encryptedData = Encrypt(originalData, key);


            // Decrypt the encrypted data
            string decryptedData = Decrypt(encryptedData, key);


            // Display results
            Console.WriteLine($"Original Data: {originalData}");
            Console.WriteLine($"Encrypted Data: {encryptedData}\nLength = {encryptedData.Length}");
            Console.WriteLine($"Decrypted Data: {decryptedData}");
        }
        static string Encrypt(string plainText, string key)
        {
            using (Aes aesAlg = Aes.Create())
            {
                // Set the key and IV for AES encryption
                aesAlg.Key = Encoding.UTF8.GetBytes(key);
                aesAlg.IV = new byte[aesAlg.BlockSize / 8];


                // Create an encryptor
                ICryptoTransform encryptor = aesAlg.CreateEncryptor(aesAlg.Key, aesAlg.IV);


                // Encrypt the data
                using (var msEncrypt = new MemoryStream())
                {
                    using (var csEncrypt = new CryptoStream(msEncrypt, encryptor, CryptoStreamMode.Write))
                    using (var swEncrypt = new StreamWriter(csEncrypt))
                    {
                        swEncrypt.Write(plainText);
                    }


                    // Return the encrypted data as a Base64-encoded string
                    return Convert.ToBase64String(msEncrypt.ToArray());
                }
            }
        }


        static string Decrypt(string cipherText, string key)
        {
            using (Aes aesAlg = Aes.Create())
            {
                // Set the key and IV for AES decryption
                aesAlg.Key = Encoding.UTF8.GetBytes(key);
                aesAlg.IV = new byte[aesAlg.BlockSize / 8];


                // Create a decryptor
                ICryptoTransform decryptor = aesAlg.CreateDecryptor(aesAlg.Key, aesAlg.IV);


                // Decrypt the data
                using (var msDecrypt = new MemoryStream(Convert.FromBase64String(cipherText)))
                using (var csDecrypt = new CryptoStream(msDecrypt, decryptor, CryptoStreamMode.Read))
                using (var srDecrypt = new StreamReader(csDecrypt))
                {
                    // Read the decrypted data from the StreamReader
                    return srDecrypt.ReadToEnd();
                }
            }
        }
    }
}
