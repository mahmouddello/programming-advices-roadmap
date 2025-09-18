using System;

namespace ConstructorAndDestructor
{
    class Settings
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

        private Settings()
        {
        }
    }

    class PrivateConstructor
    {
        static void Main(string[] args)
        {
            // ❌ Not allowed → Error
            // Settings obj = new Settings();

            // ✅ Access static members directly using class name
            Console.WriteLine(Settings.DayNumber);
            Console.WriteLine(Settings.DayName);
            Settings.ProjectPath = @"C:\MyProjects\";
            Console.WriteLine(Settings.ProjectPath);
        }
    }
}
