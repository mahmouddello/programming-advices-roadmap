using System;
using System.IO;
using System.Runtime.Serialization.Json;

namespace _08___Serialization
{
    internal class JsonSerializationExample
    {
        static void Main(string[] args)
        {
            // Create the object
            Person person = new Person { Name = "Mahmoud", Age = 23 };

            // Json: Serialize the object
            DataContractJsonSerializer jsonSerializer = new DataContractJsonSerializer(typeof(Person));
            using (MemoryStream stream = new MemoryStream())
            {
                // Saves the json object in memory
                jsonSerializer.WriteObject(stream, person);
                string jsonString = System.Text.Encoding.UTF8.GetString(stream.ToArray());

                // Opetional: Save the json string to a file
                File.WriteAllText("person.json", jsonString);
            }

            // Deserialization process
            using (FileStream fileStream = new FileStream(("person.json"), FileMode.Open))
            {
                Person deserializedPerson = (Person)jsonSerializer.ReadObject(fileStream);
                Console.WriteLine($"Name: {deserializedPerson.Name}, Age: {deserializedPerson.Age}");
            }

            Console.ReadKey();
        }
    }
}
