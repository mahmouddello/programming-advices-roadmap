using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _01___User_Controls
{
    public partial class ctrlSimpleCalculator : UserControl
    {
        public ctrlSimpleCalculator()
        {
            InitializeComponent();
        }

        public float Result {
            get
            {
                float v;
                return float.TryParse(lblResult.Text, out v) ? v : 0f;
            }
        }

        // Action is a template class that uses delegates inside of it
        public event Action<float> OnCalculationComplete;

        protected virtual void CalculationComplete(float result)
        {
            Action<float> handler = OnCalculationComplete; // copy the event into a temporary variable
            handler?.Invoke(result);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            float.TryParse(textBox1.Text, out float n1);
            float.TryParse(textBox2.Text, out float n2);

            float result = n1 + n2;
            lblResult.Text = result.ToString();

            if (OnCalculationComplete != null)
                CalculationComplete(result);
        }

        private void ctrlSimpleCalculator_Load(object sender, EventArgs e)
        {

        }
    }
}
