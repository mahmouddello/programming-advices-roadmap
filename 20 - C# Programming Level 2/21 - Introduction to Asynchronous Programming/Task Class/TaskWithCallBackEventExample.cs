using System;
using System.Threading.Tasks;

namespace _21___Introduction_to_Asynchronous_Programming
{
    internal class CustomEventArgs: EventArgs
    {
        public string Parameter1 { get; }
        public int Parameter2 { get; }

        public CustomEventArgs(string parameter1, int parameter2)
        {
            Parameter1 = parameter1;
            Parameter2 = parameter2;
        }
    }

    internal class TaskWithCallBackEventExample
    {
        public delegate void CallBackEventHandler(object sender, CustomEventArgs eventArgs);

        public static event CallBackEventHandler CallBackEvent;

        static async Task Main(string[] args)
        {
            CallBackEvent += OnCallBackReceived; // Subscribe to the event

            Task performTask = PerformAsyncOperation(CallBackEvent);

            Console.WriteLine("Doing other work in the background...\n");

            // Wait for the task to finish
            await performTask;

            Console.WriteLine("\nDone!");
        }

        private static async Task PerformAsyncOperation(CallBackEventHandler callBackEvent)
        {
            // simulate real work by adding 200 ms delay
            await Task.Delay(200);

            CustomEventArgs eventArgs = new CustomEventArgs("Mahmoud", 23);

            // Check if callback event not null before invoking
            callBackEvent?.Invoke(null, eventArgs);
        }

        private static void OnCallBackReceived(object sender, CustomEventArgs eventArgs)
        {
            Console.WriteLine($"Event received:\nParameter 1: {eventArgs.Parameter1} | Parameter 2: {eventArgs.Parameter2}");
        }
    }
}
