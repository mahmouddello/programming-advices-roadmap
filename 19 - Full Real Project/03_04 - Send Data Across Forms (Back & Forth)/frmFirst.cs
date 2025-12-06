using System;
using System.Drawing.Printing;
using System.Windows.Forms;

namespace _03_04___Send_Data_Across_Forms__Back___Forth_
{
    public partial class frmFirst : Form
    {
        public frmFirst()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int.TryParse(textBox1.Text, out int num1);
            frmSecond frm = new frmSecond(num1);

            frm.DataBack += Form2_DataBack;

            frm.ShowDialog();
        }

        private void Form2_DataBack(object sender, int personID)
        {
            MessageBox.Show($"Data Recieved back from Form 2: {personID}");
        }
    }
}
