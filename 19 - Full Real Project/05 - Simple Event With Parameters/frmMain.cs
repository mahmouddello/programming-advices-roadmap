using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _05___Simple_Event_With_Parameters
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        private void ctrlSimpleCalculator1_OnCalculationComplete(float obj)
        {
            MessageBox.Show($"Calculation completed, result: {obj}");
        }

        private void ctrlSimpleCalculator1_Load(object sender, EventArgs e)
        {

        }
    }
}
