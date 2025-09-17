using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Properties
{

    static class Settings
    {

        public static int DayNumber
        {
            get { return DateTime.Today.Day; }
        }
        
        public static string DayName
        {
            get { return DateTime.Today.DayOfWeek.ToString(); }
        }

        public static string ProjectPath { get; set; }

        internal class StaticPropertiesAndStaticClass
        {
            static void Main(string[] args)
            {
                // Read the static properties
                Console.WriteLine(Settings.DayNumber);
                Console.WriteLine(Settings.DayName);

                // Change the value of static property
                Settings.ProjectPath = @"D:\ProgrammingAdvices\roadmap\16 - OOP As it Should be in C#";
                Console.WriteLine(Settings.ProjectPath);

                Console.ReadKey();
            }
        }
    }
}
