using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _10___Misc
{
    public partial class Human
    {
        public int Age { get; set; }

        partial void PrintAge();

        public void Birthday()
        {
            Age++;
            PrintAge();
        }
    }
}
