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

        private void button1_Click(object sender, EventArgs e)
        {
            float.TryParse(textBox1.Text, out float n1);
            float.TryParse(textBox2.Text, out float n2);

            lblResult.Text = (n1 + n2).ToString();
        }

        private void ctrlSimpleCalculator_Load(object sender, EventArgs e)
        {

        }
    }
}
