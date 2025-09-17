using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Properties
{

    class Employee
    {
        // private fields
        private int _id;
        private int _phoneNumber;
        private string _name = string.Empty;

        public int id
        {
            get
            {
                return _id;
            }
            set
            {
                _id = value; // value is internally defined by C#
            }
        }

        public string name
        {
            get
            {
                return _name;
            }
            set
            {
                _name = value;
            }
        }

        public int phoneNumber
        {
            get { return _phoneNumber; } // read-only property
        }

        public string departmentName { get; set; } // auto-implemented property
        internal class Program
        {
            static void Main(string[] args)
            {
                Employee emp1 = new Employee();
                emp1.id = 7; // calls set
                emp1.name = "Mahmoud"; // calls set

                Console.WriteLine(emp1.id); // calls get
                Console.WriteLine(emp1.name); // calls get

                Console.WriteLine(emp1.phoneNumber);
                // emp1.phoneNumber = 20 -> not allowed (read-only property)

                Console.ReadKey();
            }
        }
    }
}
