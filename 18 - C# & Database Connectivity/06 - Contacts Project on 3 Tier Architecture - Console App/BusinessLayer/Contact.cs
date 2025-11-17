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

        public enum enMode { AddNew = 0, Update = 1}
        public enMode Mode = enMode.AddNew;

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

            Mode = enMode.Update; // when finding an object, the mode should be update (we're not gonna add)
        }

        public Contact() 
        {
            this.ID = -1;
            this.FirstName = "";
            this.LastName = "";
            this.Email = "";
            this.Phone = "";
            this.Address = "";
            this.DateOfBirth = DateTime.Now;
            this.CountryID = -1;
            this.ImagePath = "";

            Mode = enMode.AddNew; // When creating an object with default constructor, mode should be add
        }

        private bool _AddNewContact()
        {
            // call DataAcessLayer
            this.ID = ContactDataAccess.AddNewContact(this.FirstName, this.LastName, this.Email, this.Phone,
                this.Address, this.DateOfBirth, this.CountryID, this.ImagePath);

            return (this.ID != -1);
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

        public bool Save()
        {
            switch (this.Mode)
            {
                case enMode.AddNew:
                    if (this._AddNewContact())
                    {
                        Mode = enMode.Update;
                        //when contact is added, switch mode to update, so in case a wrong call happens it adds the record again
                        return true;
                    }
                    else
                        return false;

                default: return false;
            }
        }
    }
}
