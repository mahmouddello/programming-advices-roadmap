using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _07___Inheritance
{
    using System;

    public class clsA
    {
        // Virtual method in base class
        public virtual void Print()
        {
            Console.WriteLine("Hi, I'm the print method from the base class A");
        }
    }

    public class clsB : clsA
    {
        // Override method in derived class
        public override void Print()
        {
            Console.WriteLine("Hi, I'm the print method from the derived class B");

            // Call base class method using base keyword
            base.Print();
        }
    }

    internal class MethodOverriding
    {
        static void Main(string[] args)
        {
            // Create object of derived class
            clsB ObjB = new clsB();

            // Call Print() method
            ObjB.Print();

            Console.ReadKey();
        }
    }
}
