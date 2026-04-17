using System;


public class MyClass3
{
    [Obsolete("This method is marked as obsolete, and will be deprecated in the future.")]
    public void Method1()
    {
        Console.WriteLine("This method is marked as obsolete, and will be deprecated in the future.");
    }

    [Obsolete("This method is marked as obsolete, and will be deprecated in the future.", true)]
    public void Method2()
    {
        Console.WriteLine("This method is marked as obsolete, and will be deprecated in the future.");
    }


    public void Method3()
    {
        Console.WriteLine("This is the recommended method to use.");
    }
}

class ObsoleteAttributeExample
{
    static void Main()
    {
        MyClass3 myObject = new MyClass3();


        // Deprecated method usage
        myObject.Method1(); // Generates a compiler warning


        // New method usage
        myObject.Method2();
        myObject.Method3();


        Console.ReadLine();
    }
}
