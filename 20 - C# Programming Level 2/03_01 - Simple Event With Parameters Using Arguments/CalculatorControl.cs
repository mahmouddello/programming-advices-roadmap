using System;
using System.Windows.Forms;

namespace _03_01___Simple_Event_With_Parameters_Using_Arguments
{
    public partial class CalculatorControl : UserControl
    {
        //// Old Code
        //public event Action<int> OnCalculationComplete;
        //protected virtual void CalculationComplete(int value)
        //{
        //    OnCalculationComplete?.Invoke(value);
        //}

        public class CalculationCompleteEventArgs : EventArgs
        {
            public int Result { get; }
            public int FirstValue { get; }
            public int SecondValue { get; }

            public CalculationCompleteEventArgs(int result, int firstValue, int secondValue)
            {
                Result = result;
                FirstValue = firstValue;
                SecondValue = secondValue;
            }
        }

        public event EventHandler<CalculationCompleteEventArgs> OnCalculationComplete;


        // overloaded version to construct an EventArgs
        public void RaiseOnCalculationComplete(int result, int firstValue, int secondValue)
        {
            // calls the main event trigger method
            RaiseOnCalculationComplete(new CalculationCompleteEventArgs(result, firstValue, secondValue));
        }

        // main event triggering method
        protected virtual void RaiseOnCalculationComplete(CalculationCompleteEventArgs e)
        {
            OnCalculationComplete?.Invoke(this, e);
        }

        public CalculatorControl()
        {
            InitializeComponent();
        }

        private void btnCalculate_Click(object sender, EventArgs e)
        {
            int value1 = Convert.ToInt32(txtNumber1.Text);
            int value2 = Convert.ToInt32(txtNumber2.Text);

            int result = value1 + value2;
            lblResult.Text = result.ToString();

            if (OnCalculationComplete != null)
                // Raise the event with parameters
                RaiseOnCalculationComplete(result, value1, value2);
        }
    }
}
