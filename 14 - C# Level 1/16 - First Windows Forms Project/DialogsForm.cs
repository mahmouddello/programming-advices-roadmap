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
    public partial class DialogsForm : Form
    {
        public DialogsForm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Hello, this is a message box!");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show
             (
                "Hello, this is a message box with title", // Text
                "KOKO" // title or caption
             );
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show(
                "Are you sure you want to delete your data?",
                "Confirm",
                MessageBoxButtons.OKCancel) == DialogResult.OK) // fetching dialog result
            {
                // do something
                MessageBox.Show("User pressed OK");
            }
            else
            {
                MessageBox.Show("User Pressed Cancel");
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            // Icons: Question, Info, Exclamation, Error
            if (MessageBox.Show(
                "Are you sure you want to delete your data?",
                "Confirm",
                MessageBoxButtons.OKCancel,
                MessageBoxIcon.Exclamation) == DialogResult.OK) // fetching dialog result
            {
                // do something
                MessageBox.Show("User pressed OK");
            }
            else
            {
                MessageBox.Show("User Pressed Cancel");
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            // Icons: Question, Info, Exclamation, Error
            if (MessageBox.Show(
                "Are you sure you want to delete your data?",
                "Confirm",
                MessageBoxButtons.OKCancel,
                MessageBoxIcon.Question,
                MessageBoxDefaultButton.Button2) == DialogResult.OK) // button2 = cancel
            {
                // do something
                MessageBox.Show("User pressed OK");
            }
            else
            {
                MessageBox.Show("User Pressed Cancel");
            }
        }
    }
}
