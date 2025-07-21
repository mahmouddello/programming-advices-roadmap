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
    public partial class MaskedTextboxForm : Form
    {
        public MaskedTextboxForm()
        {
            InitializeComponent();
        }

        private void maskedTextBox2_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {
            if (maskedTextBox2.MaskFull)
                maskedTextBox2.BackColor = Color.GreenYellow;
            else
                maskedTextBox2.BackColor = Color.Red;
        }
    }
}
