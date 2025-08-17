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
    public partial class frmOpenFileDialog : Form
    {
        public frmOpenFileDialog()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            openFileDialog1.InitialDirectory = @"C:\";
            openFileDialog1.Title = "KOKO";

            openFileDialog1.DefaultExt = "txt"; // saves in the specified extenstion if user didn't select any extension
            openFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*"; // Dialog has a filter mechanisim
            openFileDialog1.FilterIndex = 2; // starts from 1 (Not 0), Selects the initial filter when the dialog pops up

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                MessageBox.Show(openFileDialog1.FileName);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            openFileDialog1.Multiselect = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                foreach (string fileName in openFileDialog1.FileNames)
                {
                    MessageBox.Show(fileName);
                }
            }
        }
    }
}
