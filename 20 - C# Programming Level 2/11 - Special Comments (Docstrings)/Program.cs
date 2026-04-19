using System;


/// <summary>
/// This class represents a simple calculator.
/// </summary>
public class Calculator
{
    /// <summary>
    /// Adds two numbers and returns the result.
    /// </summary>
    /// <param name="a">The first number to be added.</param>
    /// <param name="b">The second number to be added.</param>
    /// <returns>The sum of the two numbers.</returns>
    public int Add(int a, int b)
    {
        return a + b;
    }


    /// <summary>
    /// Subtracts the second number from the first number and returns the result.
    /// </summary>
    /// <param name="a">The number from which to subtract.</param>
    /// <param name="b">The number to subtract.</param>
    /// <returns>The result of subtracting the second number from the first number.</returns>
    public int Subtract(int a, int b)
    {
        return b - a;
    }
}

public class Program
{
    static void Main(string[] args)
    {
        Calculator calculator = new Calculator();

        Console.WriteLine(calculator.Add(3, 7));
        Console.WriteLine(calculator.Subtract(3, 7));
    }
}