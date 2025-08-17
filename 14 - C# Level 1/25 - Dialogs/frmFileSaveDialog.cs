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
    public partial class frmFileSaveDialog : Form
    {
        public frmFileSaveDialog()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            saveFileDialog1.InitialDirectory = @"C:\";
            saveFileDialog1.Title = "KOKO";

            saveFileDialog1.DefaultExt = "txt"; // saves in the specified extenstion if user didn't select any extension
            saveFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*"; // Dialog has a filter mechanisim
            saveFileDialog1.FilterIndex = 2; // starts from 1 (Not 0), Selects the initial filter when the dialog pops up
            
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                MessageBox.Show(saveFileDialog1.FileName);
            }
        }
    }
}
