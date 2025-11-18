using BusinessLayer;
using System;
using System.Diagnostics.Contracts;

namespace PresentationLayer
{
    internal class Program
    {
        static void testFindContact(int id)
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

        static void testAddNewContact()
        {
            Contact contact2 = new Contact();

            contact2.FirstName = "Fadi";
            contact2.LastName = "Maher";
            contact2.Email = "A@a.com";
            contact2.Phone = "010010";
            contact2.Address = "address1";
            contact2.DateOfBirth = new DateTime(1977, 11, 6, 10, 30, 0);
            contact2.CountryID = 1;
            contact2.ImagePath = "";

            if (contact2.Save())
                Console.WriteLine($"Contact Added with id: {contact2.ID}");
            else
                Console.WriteLine("Contact Add failed");
        }

        static void testUpdateContact(int id)
        {
            Contact contact2 = Contact.Find(id);

            if (contact2 != null) 
            {
                contact2.FirstName = "Hamdi";
                contact2.LastName = "Alwawi";
                contact2.Email = "h@a.com";
                contact2.Phone = "010010";
                contact2.Address = "address7";
                contact2.DateOfBirth = new DateTime(1979, 11, 6, 10, 30, 0);
                contact2.CountryID = 1;
                contact2.ImagePath = "";
            }

            if (contact2.Save())
            {
                Console.WriteLine("Updated the contact sucessfully");
                testFindContact(id);
            }
        }

        static void testDeleteContact(int id)
        {
            if (Contact.Delete(id))
                Console.WriteLine("Contact Deleted Sucessfully");
            else
                Console.WriteLine("Contact Deletion failed");
        }
        static void Main(string[] args)
        {
            //testFindContact(2);
            //testAddNewContact();
            //testUpdateContact(1);

            testDeleteContact(15);
        }
    }
}
