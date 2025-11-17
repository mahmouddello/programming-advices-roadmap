using System;
using BusinessLayer;

namespace PresentationLayer
{
    internal class Program
    {
        static void testFindContacat(int id)
        {
            Contact contact = Contact.Find(id);
            
            if (contact != null)
            {
                Console.WriteLine(contact.FirstName + " " + contact.LastName);
                Console.WriteLine(contact.Email);
                Console.WriteLine(contact.Phone);
                Console.WriteLine(contact.Address);
                Console.WriteLine(contact.DateOfBirth);
                Console.WriteLine(contact.CountryID);
                Console.WriteLine(contact.ImagePath);
            }
            else
            {
                Console.WriteLine("Contact [" + id + "] Not found!");
            }
        }
        static void Main(string[] args)
        {
            testFindContacat(2);
        }
    }
}
