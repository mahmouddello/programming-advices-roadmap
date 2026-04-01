using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _01___Send_Data_Between_Forms
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnOpenForm_Click(object sender, EventArgs e)
        {
            if (int.TryParse(txtData.Text, out int userId))
            {
                Form2 form = new Form2(userId);
                form.Show();
            }
            else
            {
                MessageBox.Show("Please enter a valid number.", "Invalid Input", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txtData.Clear();
                txtData.Focus();
            }
        }
    }
}
