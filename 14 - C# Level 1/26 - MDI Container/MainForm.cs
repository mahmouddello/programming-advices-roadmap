using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _26___MDI_Container
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private ChildForm form = new ChildForm();
        private void button1_Click(object sender, EventArgs e)
        {
            if (form.IsDisposed)
                form = new ChildForm();

            form.MdiParent = this;
            form.Show();
        }
    }
}
