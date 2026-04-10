using System;

namespace _04___More_About_Delegates
{
    internal class ActionDelegate
    {
        private static void ActionWithMultipleParameterMethod(string arg1, int arg2)
        {
            Console.WriteLine($"Hello {arg1}, {arg2} times!");
        }

        private static void ParameterlessMethod()
        {
            Console.WriteLine("Just a normal method :)");
        }

        private static void ActionWithIntParameterMethod(int obj)
        {
            Console.WriteLine($"I think you are {obj} years old");
        }
  
        static void Main(string[] args)
        {
            Action parameterlessAction = ParameterlessMethod;
            Action<int> actionWithIntParameter = ActionWithIntParameterMethod;
            Action<string, int> actionWithMultipleParameters = ActionWithMultipleParameterMethod;

            // Invoking the actions
            parameterlessAction();
            actionWithIntParameter(45);
            actionWithMultipleParameters("Mahmoud", 22);

            Console.ReadKey();
        }
    }
}
