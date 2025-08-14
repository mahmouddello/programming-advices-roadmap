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
    public partial class frmTabControl : Form
    {
        public frmTabControl()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            tabControl1.SelectedIndex = 1;
        }
    }
}
