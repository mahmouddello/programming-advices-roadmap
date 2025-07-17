using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _16___First_Windows_Forms_Project
{
    public partial class frmChkRadioGroup : Form
    {
        public frmChkRadioGroup()
        {
            InitializeComponent();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            btnCheckStatus.Enabled = checkBox1.Checked; // true -> enables, false -> disabled
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show(checkBox1.Checked.ToString());
        }

        private void btnCheckStatus_Click(object sender, EventArgs e)
        {
        }

        private void btnRb1Status_Click(object sender, EventArgs e)
        {
            MessageBox.Show(rbSmall.Checked.ToString());
        }

        private void btnHidePizzaGroup_Click(object sender, EventArgs e)
        {
            gbSize.Visible = false;
        }
    }
}
