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
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void btnShowForm1_Click(object sender, EventArgs e)
        {
            Form form1 = new Form1();
            form1.Show();
        }

        private void btnShowFormDialo_Click(object sender, EventArgs e)
        {
            Form form1 = new Form1();
            form1.ShowDialog();
        }

        private void btnShowDialogForm_Click(object sender, EventArgs e)
        {
            Form f = new DialogsForm();
            f.ShowDialog();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form frm = new frmChkRadioGroup();
            frm.ShowDialog();
        }

        private void ShowMoreAboutTextboxForm_Click(object sender, EventArgs e)
        {
            Form form = new MoreAboutTextBox();
            form.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form form = new MaskedTextboxForm();
            form.ShowDialog();
        }
    }
}
