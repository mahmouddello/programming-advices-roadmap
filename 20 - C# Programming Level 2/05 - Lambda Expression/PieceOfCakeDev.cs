using System;

namespace _05___Lambda_Expression
{
    internal class PieceOfCakeDev
    {
        delegate int Operation(int x, int y);
        delegate string SayHi(string name);
        delegate void SayMyName(string name);
        delegate void Greet();

        static void Main(string[] args)
        {
            // Old way to write delegates
            Operation addOperation = new Operation(Add);
            Console.WriteLine(addOperation(5, 10));

            Operation substractOperation = new Operation(Substract);
            Console.WriteLine(substractOperation(5, 10));
            Seperator();

            // C# 2.0 - Anonymous Methods
            Operation addOperation2 = delegate (int x, int y) { return x + y; };
            Console.WriteLine(addOperation2.Invoke(5, 10));

            Operation substractOperation2 = delegate (int x, int y) { return x - y; };
            Console.WriteLine(substractOperation2.Invoke(5, 10));
            Seperator();

            // C# 3.0 - Lambda Expression
            Operation addOperation3 = (int x, int y) =>  x + y;
            Console.WriteLine(addOperation3.Invoke(5, 10));

            Operation substractOperation3 = (int x, int y) => x - y;
            Console.WriteLine(substractOperation3.Invoke(5, 10));
            Seperator();

            // Another lambda expression examples

            // string return
            SayHi sayHi = (string name) => $"Hi There, {name}!";
            Console.WriteLine(sayHi("Mahmoud"));
            Seperator();

            // no return (void) we can use Action<string> instead
            SayMyName sayMyName = (string name) => Console.WriteLine($"Are you {name}?\nYou're god damn right!");
            sayMyName("Walter White");
            Seperator();

            // no param, no return
            Greet greet = () => Console.WriteLine("Welcome to Woldorf Astoria, Lusail");
            greet();
        }

        static int Add(int x, int y)
        {
            return x + y;
        }

        static void Seperator()
        {
            Console.WriteLine(new string('-', 50));
        }

        static int Substract(int x, int y)
        {
            return x - y;
        }
    }
}
 