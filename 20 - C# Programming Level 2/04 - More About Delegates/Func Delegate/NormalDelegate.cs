using System;

namespace _04___More_About_Delegates.Func_Delegate
{
    internal class NormalDelegate
    {
        public delegate int Square(int number);

        static void Main(string[] args)
        {
            Square square = new Square(SquareNumber);

            int result = square(5);
            Console.WriteLine($"The square of 5 = {result}");

            Console.ReadLine();
        }

        private static int SquareNumber(int number)
        {
            return number * number;
        }
    }
}
