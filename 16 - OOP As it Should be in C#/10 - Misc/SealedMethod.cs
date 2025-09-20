using System;

namespace _10___Misc
{
    public class Person
    {
        public virtual void Greet()
        {
            Console.WriteLine("Hello there!");
        }
    }

    public class Employee : Person
    {
        public sealed override void Greet()
        {
            Console.WriteLine("Hello, from Employee");
        }
    }

    public class Doctor : Employee
    {
        public new void Greet()
        {
            Console.WriteLine("Doctor Says Hi!");
        }
    }

    internal class SealedMethod
    {
        static void Main(string[] args)
        {
            Person person = new Person();
            person.Greet();

            Employee employee = new Employee();
            employee.Greet();

            Doctor doctor = new Doctor();
            doctor.Greet();

            Doctor doctor2 = new Doctor();
            Person p2 = doctor2;

            p2.Greet(); // shadowing loses effect when upcasting, runtime picks the most overriden version

            Person p3 = new Doctor(); // Upcasting Directly
            p3.Greet();
        }
    }
}
