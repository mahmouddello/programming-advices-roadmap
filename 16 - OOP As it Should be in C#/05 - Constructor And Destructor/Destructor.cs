using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConstructorAndDestructor
{
    using System;

    class clsPerson3
    {
        // Constructor: Called when object is created
        public clsPerson3()
        {
            Console.WriteLine("Constructor called.");
        }

        // Destructor: Called when object is destroyed
        ~clsPerson3()
        {
            Console.WriteLine("Destructor called.");
        }
    }

    internal class Destructor
    {
        public static void Main(string[] args)
        {
            // Create object
            clsPerson3 p1 = new clsPerson3();

            // Destructor will be called automatically
            // when object is garbage collected (after program ends or scope finishes)
            Console.ReadKey();
        }
    }
}
