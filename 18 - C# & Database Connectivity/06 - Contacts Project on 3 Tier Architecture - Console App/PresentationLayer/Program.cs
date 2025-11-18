using BusinessLayer;
using System;
using System.Data;

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

        static void ListContacts()
        {
            DataTable dt = Contact.GetAllContacts();
            Console.WriteLine("Contacts Data:\n");

            foreach (DataRow row in dt.Rows)
            {
                Console.WriteLine($"{row["ContactID"]}, {row["FirstName"]}, {row["LastName"]}");
            }
        }

        static void testIsCountryIsExistsById(int id)
        {
            if (Country.IsExistsByID(id))
                Console.WriteLine($"Country with id {id} exists!");
            else
                Console.WriteLine($"Country with id {id} exists!");
        }

        static void testFindCountryByID(int id)
        {
            Country country = Country.FindByID(id);

            if (country != null)
                country.Info();
            else
                Console.WriteLine($"Country with id \"{id}\" wasn't found!");
        }

        static void testFindCountryByName(string name)
        {
            Country country = Country.FindByName(name);

            if (country != null)
                country.Info();
            else
                Console.WriteLine($"Country with name \"{name}\" wasn't found!");
        }

        static void testCountryIsExistsByName(string name)
        {
            if (Country.IsExistsByName(name))
                Console.WriteLine($"Country with name \"{name}\" exists");
            else
                Console.WriteLine($"Country with name \"{name}\" doesn't exists!");
        }

        static void testAddNewCountry(string newCountryName)
        {
            Country country = new Country();

            country.CountryName = newCountryName;

            if (country.Save())
            {
                Console.WriteLine($"Country Added Successfully, with ID: {country.CountryID}");
                country.Info();
            }
            else
                Console.WriteLine("Country Addition failed!");

        }

        static void testUpdateCountryByID(int countryID, string newCountryName)
        {
            Country country = Country.FindByID(countryID);

            if (country != null)
            {
                country.CountryName = newCountryName;

                if (country.Save())
                {
                    Console.WriteLine("Country updated!");
                    country.Info();
                }
                else
                    Console.WriteLine("Country Found but update failed!");
            }
            else
                Console.WriteLine("Country not found!");
        }

        static void testDeleteCountryByID(int countryID)
        {
            if (Country.DeleteByID(countryID))
                Console.WriteLine("Deleted Successfully");
            else
                Console.WriteLine("Delete Failed");
        }

        static void testListCountries()
        {
            DataTable dt = Country.ListAllCountries();
            Console.WriteLine("Countries Data");
            foreach (DataRow row in dt.Rows)
            {
                Console.WriteLine($"{row["CountryID"]}, {row["CountryName"]}");
            }
        }

        static void Main(string[] args)
        {
            //testFindContact(2);
            //testAddNewContact();
            //testUpdateContact(1);

            //testDeleteContact(15);
            //ListContacts();

            testIsCountryIsExistsById(1);
            testIsCountryIsExistsById(100);
            Console.WriteLine("------------------------------------------------");


            testFindCountryByID(1);
            testFindCountryByID(100);
            Console.WriteLine("------------------------------------------------");

            testFindCountryByName("United States");
            testFindCountryByName("Syrian Arab Republic");
            Console.WriteLine("------------------------------------------------");

            testCountryIsExistsByName("United States");
            testCountryIsExistsByName("Syrian Arab Republic");
            Console.WriteLine("------------------------------------------------");

            //testAddNewCountry("Syria");
            //testUpdateCountryByID(9, "Austria");

            //testDeleteCountryByID(9);

            testListCountries();
        }
    }
}
