using System;
using System.ComponentModel;
using System.Windows.Forms;

namespace _24___ErrorProvider_Control
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void tbFirstName_Validating(object sender, CancelEventArgs e)
        {
            string ProcessedText = tbFirstName.Text.Trim();  

            if (string.IsNullOrEmpty(ProcessedText))
            {
                e.Cancel = true; // prevents user from leaving textbox when there is an error
                tbFirstName.Focus();
                errPrvFormValidation.SetError(tbFirstName, "This field can't be empty!");
            }
            else
            {
                e.Cancel = false;
                errPrvFormValidation.SetError(tbFirstName, ""); // removing the error
            }
        }

        private void tbLastName_Validating(object sender, CancelEventArgs e)
        {
            string ProcessedText = tbLastName.Text.Trim();

            if (string.IsNullOrEmpty(ProcessedText))
            {
                e.Cancel = true; // prevents user from leaving textbox when there is an error
                tbLastName.Focus();
                errPrvFormValidation.SetError(tbLastName, "This field can't be empty!");
            }
            else
            {
                e.Cancel = false;
                errPrvFormValidation.SetError(tbLastName, ""); // removing the error
            }
        }

        // Allows user to close the application even if there's an error triggered
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            e.Cancel = false;
        }
    }
}
