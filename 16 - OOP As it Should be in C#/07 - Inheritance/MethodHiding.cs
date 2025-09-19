using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _07___Inheritance
{
    using System;

    public class MyBaseClass
    {
        public virtual void MyMethod()
        {
            Console.WriteLine("Base class implementation");
        }

        public virtual void MyOtherMethod()
        {
            Console.WriteLine("Base class implementation of MyOtherMethod");
        }
    }

    public class MyDerivedClass : MyBaseClass
    {
        // Override → Replaces base implementation
        public override void MyMethod()
        {
            Console.WriteLine("Derived class implementation using override");
        }

        // New → Hides base implementation but doesn't NOT override it
        public new void MyOtherMethod()
        {
            Console.WriteLine("Derived class implementation of MyOtherMethod using new");
        }
    }

    internal class MethodHiding
    {
        static void Main(string[] args)
        {
            MyBaseClass myBaseObj = new MyBaseClass();
            Console.WriteLine("\nBase Object:\n");
            myBaseObj.MyMethod();         // Base class implementation
            myBaseObj.MyOtherMethod();    // Base class implementation of MyOtherMethod

            MyDerivedClass myDerivedObj = new MyDerivedClass();
            Console.WriteLine("\nDerived Object:\n");
            myDerivedObj.MyMethod();      // Derived class implementation using override
            myDerivedObj.MyOtherMethod(); // Derived class implementation of MyOtherMethod using new

            MyBaseClass myDerivedObjAsBase = myDerivedObj;
            Console.WriteLine("\nAfter Casting to Base:\n");
            myDerivedObjAsBase.MyMethod();      // Derived class implementation using override
            myDerivedObjAsBase.MyOtherMethod(); // Base class implementation of MyOtherMethod

            Console.ReadKey();
        }
    }
}
