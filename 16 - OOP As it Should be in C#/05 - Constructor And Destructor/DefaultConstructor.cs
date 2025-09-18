using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConstructorAndDestructor
{
    class clsPerson
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int Age { get; set; }

    }
    internal class DefaultConstructor
    {
        static void Main(string[] args)
        {
            clsPerson Person1 = new clsPerson();
            Console.WriteLine("ID = {0}", Person1.Id);
            Console.WriteLine("Name = {0}", Person1.Name);
            Console.WriteLine("Age = {0}", Person1.Age);

            Console.ReadKey();

        }
    }
}
