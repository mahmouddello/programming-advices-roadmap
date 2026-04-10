using System;
using System.IO;

namespace _04___More_About_Delegates.Logger_Example
{
    internal class Logger
    {
        // Define a delegate with void return type, string param (Singature)
        public delegate void LogAction(string message);

        // The log action that will be invoked
        private LogAction _logAction;

        public Logger(LogAction logAction)
        {
            _logAction = logAction;
        }

        public void Log(string message)
        {
            _logAction(message);
        }
    }

    internal class LoggerRunner
    {
        static void LogToScreen(string message)
        {
            Console.WriteLine(message);
        }

        static void LogToFile(string message)
        {
            string fileName = "log.txt";
            using (StreamWriter sw = new StreamWriter(fileName, true))
            {
                sw.WriteLine(message);
            }
        }

        static void Main(string[] args)
        {
            // Objects from class Logger, where the method's signature matches the delegate signature
            Logger screenLogger = new Logger(LogToScreen);
            Logger fileLogger = new Logger(LogToFile);

            screenLogger.Log("This message will get logged to the screen: Hello World!");
            fileLogger.Log("This message will get logged to the file: Hello World!");

            // You can easily switch the logger type, by changing the passed argument (Method)
        }
    }
}
