using System;
using System.Windows.Forms;

namespace _03_04___Send_Data_Across_Forms__Back___Forth_
{
    public partial class frmSecond : Form
    {
        private int _number;

        public delegate void DataBackEventHandler(object sender, int personID);

        public event DataBackEventHandler DataBack;

        public frmSecond(int number)
        {
            InitializeComponent();
            _number = number;
        }

        private void frmSecond_Load(object sender, EventArgs e)
        {
            label1.Text = $"Number = {_number}";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int personID = int.Parse(textBox1.Text);

            // Trigger the event to send data back to form 1
            DataBack?.Invoke(this, personID); // `this` represent the current form
        }
    }
}
