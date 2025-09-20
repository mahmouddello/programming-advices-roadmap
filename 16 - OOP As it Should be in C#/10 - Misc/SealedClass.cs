using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _10___Misc
{
    // Adding `sealed` to class clsA1 will result in error
    public class clsA1
    {

    }

    public class clsB1 : clsA1
    {

    }

    internal class SealedClass
    {
        static void Main(string[] args)
        {
            clsA1 a1 = new clsA1();
        }
    }
}
