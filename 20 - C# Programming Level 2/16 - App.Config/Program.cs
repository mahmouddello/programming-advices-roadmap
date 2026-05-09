using System;
using System.Configuration;

namespace _16___App.Config
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string logLevel = ConfigurationManager.AppSettings["LogLevel"];
            string kokoValue = ConfigurationManager.AppSettings["MyKoko"];

            Console.WriteLine("Log Level: " + logLevel);
            Console.WriteLine("My Koko Value: " + kokoValue);
        }
    }
}
