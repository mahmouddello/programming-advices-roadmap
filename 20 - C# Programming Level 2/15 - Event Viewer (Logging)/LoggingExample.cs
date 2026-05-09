using System;
using System.Diagnostics;

namespace _15___Event_Viewer__Logging_
{
    public class LoggingExample
    {
        static void Main(string[] args)
        {
            string sourceName = "KokoApp";

            // Create the event source if it doesn't exist
            if (!EventLog.SourceExists(sourceName))
            {
                // Change the logName based on need to (Application, Security, Setup, System)
                EventLog.CreateEventSource(sourceName, "Application");
                Console.WriteLine("Event Source Created");
            }

            // Log an Information event
            EventLog.WriteEntry(sourceName, "This is a simple information", EventLogEntryType.Information);

            // Log a Warning event
            EventLog.WriteEntry(sourceName, "This is a warning", EventLogEntryType.Warning);

            // Log an Error event
            EventLog.WriteEntry(sourceName, "This is an Error", EventLogEntryType.Error);

            Console.WriteLine("Events written to the log");
            Console.ReadKey();
        }
    }
}
