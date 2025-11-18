using System;
using System.Data;
using DataAccessLayer;

namespace BusinessLayer
{
    public class Country
    {
        public int CountryID { get; set; }
        public string CountryName { get; set; }
        public string CountryCode { get; set; }

        public string PhoneCode { get; set; }

        public enum enMode { AddNewMode = 0, UpdateMode = 1}
        enMode Mode = enMode.AddNewMode;

        private bool _AddNewCountry()
        {
            this.CountryID = CountryDataAccess.AddNewCountry(this.CountryName, this.CountryCode, this.PhoneCode);
            return this.CountryID != -1;
        }

        private bool _UpdateCountry()
        {
            return CountryDataAccess.UpdateCountry(this.CountryID, this.CountryName, this.CountryCode, this.PhoneCode);
        }

        private Country(int countryID, string countryName, string countryCode, string phoneCode) 
        {
            this.CountryID = countryID;
            this.CountryName = countryName;
            this.CountryCode = countryCode;
            this.PhoneCode = phoneCode;

            this.Mode = enMode.UpdateMode;
        }

        public Country()
        {
            this.CountryID = -1;
            this.CountryName = string.Empty;
            this.CountryCode = string.Empty;
            this.PhoneCode = string.Empty;
            
            this.Mode = enMode.AddNewMode;
        }

        public static Country FindByID(int countryID)
        {
            string countryName = string.Empty, countryCode = string.Empty, phoneCode = string.Empty;

            if (CountryDataAccess.GetCountryByID(countryID, ref countryName, ref countryCode, ref phoneCode))
                return new Country(countryID, countryName, countryCode, phoneCode);

            return null;
        }

        public static Country FindByName(string countryName)
        {
            int countryID = -1;
            string countryCode = string.Empty;
            string phoneCode = string.Empty;

            if (CountryDataAccess.GetCountryByName(ref countryName, ref countryID, ref countryCode, ref phoneCode))
                return new Country(countryID, countryName, countryCode, phoneCode);

            return null;
        }

        public static bool IsExistsByName(string countryName)
        {
            return CountryDataAccess.IsExistsByName(countryName);
        }

        public static bool IsExistsByID(int id)
        {
            return CountryDataAccess.IsExistsByID(id);
        }

        public static bool DeleteByID(int id)
        {
            return CountryDataAccess.DeleteCountry(id);
        }

        public void Info()
        {
            Console.WriteLine($"Country ID: {this.CountryID}, Country Name: {this.CountryName}");
        }

        public bool Save()
        {
            switch(this.Mode)
            {
                case enMode.AddNewMode:
                    if (this._AddNewCountry())
                    {
                        this.Mode = enMode.UpdateMode;
                        return true;
                    }
                    else
                        return false;

                case enMode.UpdateMode:
                    return this._UpdateCountry();

                default: return false;
            }
        }

        public static DataTable ListAllCountries()
        {
            return CountryDataAccess.GetAllCountries();
        }
    }
}
