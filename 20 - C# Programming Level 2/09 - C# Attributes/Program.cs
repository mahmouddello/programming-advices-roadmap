using System;
using System.Diagnostics;

namespace _09___C__Attributes
{
    [Serializable] // An object from this class is serializable
    public class MyClass
    {
        // Will be serialized
        public int serializedField;

        // Will not be serialized
        [NonSerialized]
        public int nonSerializedField;

        [Obsolete("This method is deprecated")]
        public void DeprecatedMethod()
        {
            // implementation of the method
        }

        
        [Conditional("DEBUG")]
        public void DebugMethod()
        {
            // code to be executed only in Debug Mode
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {

        }
    }
}
