using System;

public interface IPerson2
{
    string FirstName { get; set; }
    string LastName { get; set; }

    void Introduce();

    void Print();

    string To_String();
}

public interface ICommunicate2
{

    void CallPhone();

    void SendEmail(string Title, string Body);

    void SendSMS(string Title, string Body);

    void SendFax(string Title, string Body);

}

public abstract class Person2 : IPerson2, ICommunicate2

{

    public string FirstName { get; set; }
    public string LastName { get; set; }
    public abstract void Introduce();


    public void SayGoodbye()
    {
        Console.WriteLine("Goodbye!");
    }


    public void Print()
    {
        Console.WriteLine("Hi I'm the print method");
    }

    public string To_String()
    {
        return "Hi this is the complete string....";
    }

    public void CallPhone()
    {
        Console.WriteLine("Calling Phone... :-)");
    }

    public void SendEmail(string Title, string Body)
    {
        Console.WriteLine("Email Sent :-)");
    }

    public void SendSMS(string Title, string Body)
    {
        Console.WriteLine("SMS Sent :-)");
    }

    public void SendFax(string Title, string Body)
    {
        Console.WriteLine("Fax Sent :-)");
    }
}


public class Employee2 : Person2
{
    public int EmployeeId { get; set; }

    public override void Introduce()
    {
        Console.WriteLine($"Hi, my name is {FirstName} {LastName}, and my employee ID is {EmployeeId}.");
    }
}

public class ImplementMultipleInterfaces
{
    public static void Main()
    {
        //You cannot create an object of an Interface, you can only Implement it.
        // IPerson Person1 = new IPerson();

        Employee2 employee = new Employee2();
        employee.FirstName = "Mohammed";
        employee.LastName = "Abu-Hadhoud";
        employee.EmployeeId = 123;
        employee.Introduce(); // Output: "Hi, my name is John Doe, and my employee ID is 123."
        employee.SayGoodbye(); // Output: "Goodbye!"
        employee.Print();
        employee.CallPhone();
        employee.SendEmail("hi", "Body");
        employee.SendSMS("hi", "Body");
        employee.SendFax("hi", "Body");

        Console.ReadKey();


    }
}