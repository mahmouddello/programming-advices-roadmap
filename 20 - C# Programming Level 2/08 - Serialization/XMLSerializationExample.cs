using System;
using System.IO;
using System.Xml.Serialization;

namespace _08___Serialization
{
    internal class XMLSerializationExample
    {
        static void Main(string[] args)
        {
            // Create the object
            Person person = new Person { Name = "Mahmoud", Age = 23 };

            // XML Serializer initiate
            XmlSerializer serializer = new XmlSerializer(typeof(Person));
            using (TextWriter writer = new StreamWriter("person.xml"))
            {
                serializer.Serialize(writer, person);
            }

            // Deserialize the object back
            using (TextReader reader = new StreamReader("person.xml"))
            {
                Person deserializedPerson = (Person)serializer.Deserialize(reader);
                Console.WriteLine($"Name: {deserializedPerson.Name}, Age: {deserializedPerson.Age}");
            }

            Console.ReadKey();
        }
    }
}
