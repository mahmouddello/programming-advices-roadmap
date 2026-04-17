using System;


namespace _09___C__Attributes
{
    [AttributeUsage(AttributeTargets.Class | AttributeTargets.Method, AllowMultiple = true)]
    public class MyCustomAttribute : Attribute
    {
        public string Description { get; }

        public MyCustomAttribute(string description)
        {
            Description = description;
        }
    }

    [MyCustom("This is a class attribute")]
    public class CustomAttributeExample
    {

        [MyCustom("This is a method attribute")]
        public void MyMethod()
        {
            // implementation
        }
    }
}
