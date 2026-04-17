#define TRACE_ENABLED

using System;
using System.Diagnostics;

public class TraceExample
{
    [Conditional("TRACE_ENABLED")]
    public static void LogTrace(string message)
    {
        Console.WriteLine($"[TRACE] {message}");
    }

    public static void Main()
    {
        LogTrace("This trace message will only be included if TRACE_ENABLED is defined.");
        Console.WriteLine("Rest of the program.");

        Console.ReadLine();
    }
}
