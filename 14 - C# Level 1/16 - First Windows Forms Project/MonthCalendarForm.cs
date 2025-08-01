using System;
using System.Windows.Forms;

namespace _16___First_Windows_Forms_Project
{
    public partial class MonthCalendarForm : Form
    {
        public MonthCalendarForm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show(monthCalendar1.SelectionRange.Start.ToString());
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show(monthCalendar1.SelectionRange.End.ToString());
        }

        private void button3_Click(object sender, EventArgs e)
        {
            MessageBox.Show(monthCalendar1.SelectionRange.Start.ToShortDateString() + " - " + monthCalendar1.SelectionRange.End.ToShortDateString());
        }
    }
}
