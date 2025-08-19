using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _38___Context_Menu
{
    public partial class frmMainWindow : Form
    {
        public frmMainWindow()
        {
            InitializeComponent();
        }

        private void tsmChangeColor_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                Control control = cmsTextbox.SourceControl;
                control.BackColor = colorDialog1.Color;
            }
        }

        private void tsmChangeFont_Click(object sender, EventArgs e)
        {
            if (fontDialog1.ShowDialog() == DialogResult.OK)
            {
                Control control = cmsTextbox.SourceControl;
                control.Font = fontDialog1.Font;
            }
        }

        private void tsmClear_Click(object sender, EventArgs e)
        {
            if (cmsTextbox.SourceControl is TextBox txt)
            {
                txt.Clear();
            }
        }
    }
}
