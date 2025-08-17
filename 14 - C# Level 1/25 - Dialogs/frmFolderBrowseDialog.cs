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
    public partial class frmFolderBrowseDialog : Form
    {
        public frmFolderBrowseDialog()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            folderBrowserDialog1.ShowNewFolderButton = true; // false by default

            if (folderBrowserDialog1.ShowDialog() == DialogResult.OK)
                MessageBox.Show(folderBrowserDialog1.SelectedPath);
        }
    }
}
