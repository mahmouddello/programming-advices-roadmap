using System;
using System.Windows.Forms;

namespace _16___First_Windows_Forms_Project
{
    public partial class TimerForm : Form
    {
        int Counter;
        public TimerForm()
        {
            InitializeComponent();
            Counter = 0;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Enabled = true;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            timer1.Enabled = false;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Counter++;
            label1.Text = Counter.ToString();
        }
    }
}
