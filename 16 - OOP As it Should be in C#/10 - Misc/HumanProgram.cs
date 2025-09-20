using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _10___Misc
{
    internal class HumanProgram
    {
        static void Main(string[] args)
        {
            //the code of Person Class is seperated in 2 files Person1.cs and PersonPrinting.cs
            Human human = new Human();
            human.Age = 25;
            human.Birthday(); // Output: "Current age: 26"
        }
    }
}
