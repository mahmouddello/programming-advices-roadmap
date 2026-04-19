using System;

namespace _10___Reflection
{
    [AttributeUsage(AttributeTargets.Property)]
    public class RangeAttribute : Attribute
    {
        public int Min { get; }
        public int Max { get; }
        public string ErrorMessage { get; }

        public RangeAttribute(int min, int max, string errorMessage)
        {
            Min = min;
            Max = max;
            ErrorMessage = errorMessage;
        }
    }

    public class Person
    {
        public string Name { get; set; }

        [Range(18, 99, "Age must be between 18 and 99")]
        public int Age { get; set; }

        [Range(5, 10, "Experience must be between 5 and 10 years")]
        public int Experience { get; set; }
    }

    public class CustomAttributeValidationExample
    {
        static void Main(string[] args)
        {
            Person person = new Person { Name = "Mahmoud", Age = 17, Experience = 3 };

            if (ValidatePerson(person))
                Console.WriteLine("Person details are valid");
            else
                Console.WriteLine("Person details are invalid");

            Console.ReadKey();
        }

        static bool ValidatePerson(Person person)
        {
            Type type = person.GetType(); // get the type using reflection
            bool flag = true;

            // loop over each property in the person object
            foreach(var property in type.GetProperties())
            {
                // If there's a range attribute defined to a property
                if (Attribute.IsDefined(property, typeof(RangeAttribute)))
                {
                    var rangeAttribute = (RangeAttribute)Attribute.GetCustomAttribute(property, typeof(RangeAttribute));
                    int value = (int)property.GetValue(person);

                    if (value < rangeAttribute.Min || value > rangeAttribute.Max)
                    {
                        flag = false;
                        Console.WriteLine($"Validation failed for attribute: '{property.Name}':\n" +
                            $"Property Value: {value}\nError Message: {rangeAttribute.ErrorMessage}");
                        Console.WriteLine(new string('-', 25));
                    }
                }
            }

            return flag;
        }
    }
}
