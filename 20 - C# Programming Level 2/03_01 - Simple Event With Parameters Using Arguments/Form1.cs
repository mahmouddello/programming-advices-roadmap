using System;
using System.Windows.Forms;

namespace _03_01___Simple_Event_With_Parameters_Using_Arguments
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void calculatorControl1_OnCalculationComplete(object sender, CalculatorControl.CalculationCompleteEventArgs e)
        {
            MessageBox.Show($"Result = {e.Result} | First Value = {e.FirstValue} | Second Value = {e.SecondValue}");
        }
    }
}
