#include <iostream>
using namespace std;

enum enColor { Red, Green, Yellow, Blue };
enum enGender { Male, Female };
enum enMaritalStatus { Single, Married };


struct stAddress
{
    string StreetName;
    string BuildingNo;
    string POBox;
    string ZipCode;
};


struct stContactInfo
{
    string Phone;
    string Email;
    stAddress Address; // structure instance inside a structure
};


struct stPerson
{

    string FirstName;
    string LastName;

    stContactInfo ContactInfo; // again, a structure instance inside a structure

    // enum typed variables in structure
    enMaritalStatus MaritalStatues;
    enGender Gender;
    enColor FavoriteColor;

};


int main()
{

    stPerson Person1; // with one variable, we have access to every user related info

    Person1.FirstName = "Mohammed";
    Person1.LastName = "Abu-Hadhoud";

    Person1.ContactInfo.Email = "xyz@xyz.com";
    Person1.ContactInfo.Phone = "+961000000999";
    Person1.ContactInfo.Address.POBox = "7777";
    Person1.ContactInfo.Address.ZipCode = "11194";
    Person1.ContactInfo.Address.StreetName = "Queen1 Street";
    Person1.ContactInfo.Address.BuildingNo = "313";

    Person1.Gender = enGender::Male;
    Person1.MaritalStatues = enMaritalStatus::Married;
    Person1.FavoriteColor = enColor::Green;

    cout << Person1.ContactInfo.Address.StreetName << endl;


    return 0;
}