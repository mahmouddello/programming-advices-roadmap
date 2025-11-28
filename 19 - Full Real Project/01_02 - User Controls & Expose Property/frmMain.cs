using System;
using System.Windows.Forms;

namespace _01___User_Controls
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (ctrlSimpleCalculator1.Visible)
            {
                ctrlSimpleCalculator1.Visible = false;
                button1.Text = "Show";
            }
            else
            {
                ctrlSimpleCalculator1.Visible = true;
                button1.Text = "Hide";
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (ctrlSimpleCalculator2.Visible)
            {
                ctrlSimpleCalculator2.Visible = false;
                button2.Text = "Show";
            }
            else
            {
                ctrlSimpleCalculator2.Visible = true;
                button2.Text = "Hide";
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (ctrlSimpleCalculator3.Visible)
            {
                ctrlSimpleCalculator3.Visible = false;
                button3.Text = "Show";
            }
            else
            {
                ctrlSimpleCalculator3.Visible = true;
                button3.Text = "Hide";
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            MessageBox.Show(ctrlSimpleCalculator1.Result.ToString());
        }

        private void button5_Click(object sender, EventArgs e)
        {
            MessageBox.Show(ctrlSimpleCalculator2.Result.ToString());
        }

        private void button4_Click(object sender, EventArgs e)
        {
            MessageBox.Show(ctrlSimpleCalculator3.Result.ToString());
        }
    }
}
