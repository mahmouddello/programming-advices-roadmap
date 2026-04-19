using System;
using System.Linq;
using System.Reflection;

namespace _10___Reflection
{
    internal class NavigateStringLibrary
    {
        static void Main()
        {
            // Get the assembly containing the System.String type
            Assembly mscorlib = typeof(string).Assembly;

            // Get the System.String type
            Type stringType = mscorlib.GetType("System.String");

            if (stringType != null)
            {
                Console.WriteLine($"Methods of the System.String class:\n");

                // Get all public methods of the System.String class
                var stringMethods = stringType.GetMethods(BindingFlags.Public | BindingFlags.Instance)
                    .OrderBy(method => method.Name);

                Console.WriteLine((int)BindingFlags.Public);    // 16
                Console.WriteLine((int)BindingFlags.Instance);  // 4
                Console.WriteLine((int)(BindingFlags.Public | BindingFlags.Instance)); // 20

                Console.WriteLine(new string('-', 50));

                foreach (var method in stringMethods)
                {
                    Console.WriteLine($"\t{method.ReturnType} {method.Name}({GetParameterList(method.GetParameters())})");
                }
            }
            else
            {
                Console.WriteLine("System.String type not found.");
            }


            Console.ReadKey();
        }

        static string GetParameterList(ParameterInfo[] parameters)
        {
            return string.Join(", ", parameters.Select(parameter => $"{parameter.ParameterType} {parameter.Name}"));
        }
    }
}
