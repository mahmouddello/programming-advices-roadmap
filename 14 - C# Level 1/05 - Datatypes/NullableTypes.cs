using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Datatypes
{
    /*
        As you know, a value type cannot be assigned a null value. 
        For example, int i = null will give you a compile time error.
        C# 2.0 introduced nullable types that allow you to assign null to value type variables. 
        You can declare nullable types using Nullable<t> where T is a type.
     */
    internal class NullableTypes
    {
        static void Main(string[] args)
        {
            // example, Nullable<int> can be assigned any value from -2147483648 to 2147483647, or a null value.
            Nullable<int> i = null;
            Console.WriteLine(i);

            int? y = null; // Same as Nullable<int> y = null;
            Console.WriteLine(y);
        }
    }
}
