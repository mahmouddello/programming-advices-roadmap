using System;

namespace ConstructorAndDestructor
{
    static class Settings2
    {
        public static int DayNumber
        {
            get
            {
                return DateTime.Today.Day;
            }
        }

        public static string DayName
        {
            get
            {
                return DateTime.Today.DayOfWeek.ToString();
            }
        }

        public static string ProjectPath { get; set; }

        // 1️- Static Constructor: Called automatically once
        static Settings2()
        {
            Console.WriteLine("Static Constructor has been Invoked!");
            ProjectPath = @"C:\MyProjects\";
        }
    }

    class StaticConstructor
    {
        static void Main()
        {
            // No object creation possible because class is static
            // Settings obj = new Settings(); ❌ Not allowed

            // Static constructor is called automatically before first use
            Console.WriteLine(Settings2.DayNumber);
            Console.WriteLine(Settings2.DayName);
            Console.WriteLine(Settings2.ProjectPath);

            Console.ReadKey();
        }
    }
}