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
    }
}
