using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _27___MenuStrip
{
    public partial class frmMainWindow : Form
    {
        public frmMainWindow()
        {
            InitializeComponent();
        }

        private void findClientToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Find Client Triggered!");
        }

        private void addNewClientToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Add new Client Triggered!");
        }

        private void deleteClientToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Delete Client Triggered!");
        }

        private void updateClientToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Update Client Triggered!");
        }

        private void fileToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void option1ToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void logoutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Logout Triggered!");
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Exit Triggered!");
        }

        private void helpToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("help Triggered!");

        }
    }
}
