using DataAccessLayer;
using System;

namespace BusinessLayer
{
    public class Contact
    {
        public int ID { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Email { get; set; }
        public string Phone { get; set; }
        public string Address { get; set; }
        public DateTime DateOfBirth { get; set; }
        public int CountryID { get; set; }
        public string ImagePath { get; set; }

        private Contact(int contactID, string firstName, string lastName, string email,
                string phone, string address, DateTime dateOfBirth, int countryID, string imagePath)
        {
            this.ID = contactID;
            this.FirstName = firstName;
            this.LastName = lastName;
            this.Email = email;
            this.Phone = phone;
            this.Address = address;
            this.DateOfBirth = dateOfBirth;
            this.CountryID = countryID;
            this.ImagePath = imagePath;
        }

        public static Contact Find (int contactID)
        {
            string firstName = "", lastName = "", email = "", phone = "", address = "";
            DateTime dateOfBirth = DateTime.Now; int countryID = -1; string imagePath = "";

            if (ContactDataAccess.GetContactInfoByID(contactID, ref firstName, ref lastName, ref email,
                ref phone, ref address, ref dateOfBirth, ref countryID, ref imagePath))
            {
                return new Contact(
                    contactID, firstName, lastName, email, phone, address, dateOfBirth, countryID, imagePath
                );
            }

            return null;
        }

    }
}
