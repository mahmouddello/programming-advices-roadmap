using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _04___Calculator
{
    class clsCalculator
    {
        private float _result = 0;
        private float _lastNumber = 0;
        private string _lastOpeartion = string.Empty;

        public void Add(float number)
        {
            _lastNumber = number;
            _result += _lastNumber;
            _lastOpeartion = "Adding";
        }

        public void Substract(float number)
        {
            _lastNumber = number;
            _result -= _lastNumber;
            _lastOpeartion = "Substracing";
        }

        public void Multiply(float number)
        {
            _lastNumber = number;
            _result *= _lastNumber;
            _lastOpeartion = "Multiplying";
        }

        public void Divide(float number)
        {
            if (number == 0)
                number = 1;

            _lastNumber = number;
            _result /= _lastNumber;
            _lastOpeartion = "Dividing";
        }

        public void Clear()
        {
            _result = 0;
            _lastOpeartion = "Clear";
        }

        public void PrintResult()
        {
            Console.WriteLine($"Result after {_lastOpeartion} {_lastNumber} is: {_result}");
        }
    }
    
    internal class Program
    {
        static void Main(string[] args)
        {
            clsCalculator calculator = new clsCalculator();

            calculator.Clear();

            calculator.Add(10);
            calculator.PrintResult();

            calculator.Add(100);
            calculator.PrintResult();

            calculator.Substract(20);
            calculator.PrintResult();

            calculator.Divide(0);
            calculator.PrintResult();

            calculator.Divide(2);
            calculator.PrintResult();

            calculator.Multiply(3);
            calculator.PrintResult();

            Console.ReadKey();
        }
    }
}
