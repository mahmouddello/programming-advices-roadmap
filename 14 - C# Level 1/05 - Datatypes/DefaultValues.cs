using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Datatypes
{
    internal class DefaultValues
    {
        //
        static void Main(string[] args)
        {
            Console.WriteLine("\n--------- Default Value ------------\n");


            //get default value using default(type)
            int i1 = default(int); // 0
            float f12 = default(float);// 0
            decimal d12 = default(decimal);// 0
            bool b12 = default(bool);// false
            char c12 = default(char);// '\0'

            // C# 7.1 onwards
            //get default value using default
            int i2 = default; // 0
            float f21 = default;// 0
            decimal d21 = default;// 0
            bool b21 = default;// false
            char c21 = default;// '\0


            Console.WriteLine("{0,-10} | {1,-15} | {2,-10}", "Type", "Default (explicit)", "Default (implicit)");
            Console.WriteLine(new string('-', 42));

            Console.WriteLine("{0,-10} | {1,-15} | {2,-10}", "int", i1, i2);
            Console.WriteLine("{0,-10} | {1,-15} | {2,-10}", "float", f12, f21);
            Console.WriteLine("{0,-10} | {1,-15} | {2,-10}", "decimal", d12, d21);
            Console.WriteLine("{0,-10} | {1,-15} | {2,-10}", "bool", b12, b21);
            Console.WriteLine("{0,-10} | {1,-15} | {2,-10}", "char", c12 == '\0' ? "\\0" : c12.ToString(), 21 == '\0' ? "\\0" : c21.ToString());

            Console.ReadKey();
        }
    }
}
