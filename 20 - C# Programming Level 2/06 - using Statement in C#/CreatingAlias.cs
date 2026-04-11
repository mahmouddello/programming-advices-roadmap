using System;
using Koko = System.Console;

namespace _06___using_Statement_in_C_
{
    internal class CreatingAlias
    {
        static void Main(string[] args)
        {
            // using Koko alias instead of System.Console
            Koko.WriteLine("Hello World!");
            Koko.ReadKey();
        }
    }
}
