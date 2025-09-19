using System;

public interface IPerson
{
    string FirstName { get; set; }
    string LastName { get; set; }
    void Introduce();
    void Print();
    string To_String();
}

public abstract class Person : IPerson
{
    public string FirstName { get; set; }
    public string LastName { get; set; }

    // Abstract method from interface
    public abstract void Introduce();

    // Regular methods
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

    public void SendEmail()
    {
        Console.WriteLine("Email Sent :-)");
    }
}

public class Employee : Person
{
    public int EmployeeId { get; set; }

    // Must implement abstract method from Person (and thus IPerson)
    public override void Introduce()
    {
        Console.WriteLine($"Hi, my name is {FirstName} {LastName}, and my employee ID is {EmployeeId}.");
    }
}

public class Program
{
    public static void Main()
    {
        // Cannot create IPerson directly → only via class implementation
        Employee employee = new Employee
        {
            FirstName = "Mohammed",
            LastName = "Abu-Hadhoud",
            EmployeeId = 123
        };

        employee.Introduce();    // Implemented method
        employee.Print();        // From interface, implemented in Person
        employee.SendEmail();     // Custom method
        employee.SayGoodbye();   // Inherited from Person
        Console.WriteLine(employee.To_String());

        Console.ReadKey();
    }
}
