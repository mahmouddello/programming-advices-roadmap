using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _02___AccessModifiers
{

    class clsA
    {
        public int x1 = 10;
        private int x2 = 20;
        protected int x3 = 30;

        public int fun1()
        {
            return 100;
        }

        private int fun2()
        {
            return 200;
        }

        protected int fun3()
        {
            return 300;
        }
    }

    class clsB : clsA
    {
        public int fun4()
        {
            //x1 is public and x3 is protected in the base class so you can access them.
            //You cannot access any private members of the base class.
            return x1 + x3;
        }

    }

    internal class Program
    {
        static void Main(string[] args)
        {
            //Create object from class
            clsA A = new clsA();

            //all public members are accessable and internal 
            Console.WriteLine("All public members are accessable");
            Console.WriteLine("x1={0}", A.x1);
            Console.WriteLine("result of fun1={0}", A.fun1());

            //you cannot access private members in the follwing line.
            //Console.WriteLine("x2={0}", A.x2);

            //you cannot access protected members in the follwing line.
            // Console.WriteLine("x3={0}", A.x3);

            //you cannot access private members in the follwing line.
            //Console.WriteLine("result of fun2={0}", A.fun2());

            //you cannot access protected members in the follwing line.
            //Console.WriteLine("result of fun3={0}", A.fun3());

            clsB B = new clsB();
            Console.WriteLine("\nObjects from class B expose all public members from the base class");
            Console.WriteLine("x1={0}", B.x1);
            Console.WriteLine("result of fun1={0}", B.fun1());

            //you cannot access private members in the follwing line.
            //Console.WriteLine("x2={0}", B.x2);
            //Console.WriteLine("result of fun1={0}", B.fun2());

            //you cannot access protected members in the follwing line.
            //Console.WriteLine("x3={0}", B.x3);
            //Console.WriteLine("result of fun3={0}", B.fun3());

            Console.ReadKey();
        }
    }
}
