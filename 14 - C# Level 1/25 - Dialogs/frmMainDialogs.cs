using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _25___Dialogs
{
    public partial class frmMainDialogs : Form
    {
        public frmMainDialogs()
        {
            InitializeComponent();
        }

        private void btnColorDialogForm_Click(object sender, EventArgs e)
        {
            Form form = new frmColorDialog();
            form.ShowDialog();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form form = new frmFontDialog();
            form.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form form = new frmFileSaveDialog();
            form.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form form = new frmOpenFileDialog();
            form.ShowDialog();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Form form = new frmFolderBrowseDialog();
            form.ShowDialog();
        }
    }
}
