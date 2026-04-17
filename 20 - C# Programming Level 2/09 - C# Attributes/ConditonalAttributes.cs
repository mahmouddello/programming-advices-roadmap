// #define DEBUG

using System;
using System.Diagnostics;

public class MyClass2
{
    [Conditional("DEBUG")]
    public void DebugMethod()
    {
        Console.WriteLine("Debug method executed.");
    }

    public void NormalMethod()
    {
        Console.WriteLine("Normal method executed.");
    }
}

public class ConditionalAttributes
{
    static void Main(string[] args)
    {
        MyClass2 myClass2 = new MyClass2();

        myClass2.NormalMethod(); // This will always be executed
        myClass2.DebugMethod(); // This will only be executed in DEBUG builds

        Console.ReadLine();
    }
}
