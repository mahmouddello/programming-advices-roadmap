using System;

namespace _02___AccessModifiers
{
    class clsC
    {
        public int x1;            // Instance field → separate for each object
        public static int x2;     // Static field → shared by all objects

        public int Method1()
        {    // Non-static → can access both
            return x1 + x2;
        }

        public static int Method2()
        {  // Static → only static members
            return x2;
        }
    }

    internal class StaticMembers
    {
        static void Main()
        {

            //Create an object of Employee class.
            clsC objA1 = new clsC();
            clsC objA2 = new clsC();


            objA1.x1 = 7;
            objA2.x1 = 10;
            //x2 is shared for all object because it's on the class level, you can access it 
            //using the class name.
            clsC.x2 = 100;


            Console.WriteLine("objA1.x1:={0}", objA1.x1);
            Console.WriteLine("objA2.x1:={0}", objA2.x1);
            Console.WriteLine("objA1.method1 results:={0}", objA1.Method1());
            Console.WriteLine("objA2.method1 results:={0}", objA2.Method1());


            //Method 2 cannot be accessed through object, only through the class itself.
            //  Console.WriteLine(objA1.Method2());
            Console.WriteLine("static method2 results:={0}", clsC.Method2());

            Console.WriteLine("static x2:={0}", clsC.x2);
            Console.ReadLine();
        }
    }
}
