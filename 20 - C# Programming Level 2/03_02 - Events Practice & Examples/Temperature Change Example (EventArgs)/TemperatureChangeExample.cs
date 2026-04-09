using System;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace _03_02___Temperature_Change_Event_Example
{
    public class TemperatureChangedEventArgs : EventArgs
    {
        public double OldTemperatrue { get; }
        public double NewTemperatrue { get; }
        public double Difference { get; }

        public TemperatureChangedEventArgs(double oldTemperatrue, double newTemperatrue)
        {
            OldTemperatrue = oldTemperatrue;
            NewTemperatrue = newTemperatrue;
            Difference = NewTemperatrue - OldTemperatrue;
        }
    }

    public class Thermostat
    {
        public event EventHandler<TemperatureChangedEventArgs> TemperatureChanged;

        public double OldTemperature;
        public double CurrentTemperature;

        public void SetTemperature(double newTemperature)
        {
            if (newTemperature != CurrentTemperature)
            {
                OldTemperature = CurrentTemperature;
                CurrentTemperature = newTemperature;
                OnTemperatureChanged(OldTemperature, CurrentTemperature);
            }
        }

        private void OnTemperatureChanged(double oldTemperature, double currentTemperature)
        {
            OnTemperatureChanged(new TemperatureChangedEventArgs(oldTemperature, currentTemperature));
        }

        protected virtual void OnTemperatureChanged(TemperatureChangedEventArgs e)
        {
            TemperatureChanged?.Invoke(this, e); // e has all the data we need
        }
    }

    public class Display
    {
        public void Subscribe(Thermostat thermostat)
        {
            thermostat.TemperatureChanged += HandleTemperatureChange; // saves the method address to invoke it
        }

        // Notice: Signature of the method matches the signature of the event -> TemperatureChanged?.Invoke(this, e);
        // this: object, TemperatureChangedEventArgs: e
        private void HandleTemperatureChange(object sender, TemperatureChangedEventArgs e)
        {
            Console.WriteLine("\n\nTemperature Changed\n");
            Console.WriteLine($"Old Temperature: {e.OldTemperatrue}");
            Console.WriteLine($"New Temperature: {e.NewTemperatrue}");
            Console.WriteLine($"Difference: {e.Difference}");
        }
    }

    public class TemperatureChangeExample
    {
        private static Random random = new Random();

        static double GetRandomDouble(int min, int max)
        {
            return random.NextDouble() * (max - min) + min;
        }

        static void Main(string[] args)
        {

            Thermostat thermostat = new Thermostat();
            Display display = new Display();

            display.Subscribe(thermostat);

            // Change the temperature to a random double each 3 seconds in for loop and watch terminal
            for (int i = 0; i < 5; i++)
            {
                thermostat.SetTemperature(Math.Round(GetRandomDouble(10, 30)));
                System.Threading.Thread.Sleep(3000);
            }
        }
    } 
}
