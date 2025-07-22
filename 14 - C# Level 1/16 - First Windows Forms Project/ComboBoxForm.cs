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
    public partial class ComboBoxForm : Form
    {
        public ComboBoxForm()
        {
            InitializeComponent();
        }

        private void ComboBoxForm_Load(object sender, EventArgs e)
        {
            comboBox1.SelectedIndex = 0; // selects first element on form load
        }

        private void button1_Click(object sender, EventArgs e)
        {
            comboBox1.Items.Add("Mahmoud"); // add items to ComboBox with code
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form form = new ComboBoxExercise();
            form.ShowDialog();
        }
    }
}
