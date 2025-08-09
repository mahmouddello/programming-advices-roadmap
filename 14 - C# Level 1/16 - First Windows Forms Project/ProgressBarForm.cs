using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace _16___First_Windows_Forms_Project
{
    public partial class ProgressBarForm : Form
    {
        public ProgressBarForm()
        {
            InitializeComponent();
        }

        private void progressBar1_Click(object sender, EventArgs e)
        {
            MessageBox.Show(progressBar1.Value.ToString());
        }

        private void button1_Click(object sender, EventArgs e)
        {
            progressBar1.Minimum = 0;
            progressBar1.Maximum = 100;
            progressBar1.Value = 0;

            for (int i = 0; i < 10; i++) 
            {
                if (progressBar1.Value < progressBar1.Maximum)
                {
                    progressBar1.Value += 10;
                    Thread.Sleep(500); // half a second

                    label1.Text = "%" + progressBar1.Value.ToString();

                    label1.Refresh();
                    progressBar1.Refresh();

                    if (progressBar1.Value >= progressBar1.Maximum)
                        button1.Enabled = false;
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            progressBar1.Value = 0;
            button1.Enabled = true;
            label1.Text = "%" + progressBar1.Value.ToString();

            label1.Refresh();
        }
    }
}
