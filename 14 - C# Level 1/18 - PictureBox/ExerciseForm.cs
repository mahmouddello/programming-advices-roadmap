using _18___PictureBox.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _18___PictureBox
{
    public partial class ExerciseForm : Form
    {
        public ExerciseForm()
        {
            InitializeComponent();
        }

        void UpdateImageAndLabel()
        {
            if (radioButton1.Checked)
            {
                pictureBox1.Image = Resources.Boy;
                label1.Text = radioButton1.Text;
                return;
            }

            if (radioButton2.Checked)
            {
                pictureBox1.Image = Resources.Girl;
                label1.Text = radioButton2.Text;
                return;
            }

            if (radioButton3.Checked)
            {
                pictureBox1.Image = Resources.Book;
                label1.Text = radioButton3.Text;
                return;
            }

            if (radioButton4.Checked)
            {
                pictureBox1.Image = Resources.Pen;
                label1.Text = radioButton4.Text;
                return;
            }
        }
        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            UpdateImageAndLabel();
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            UpdateImageAndLabel();
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            UpdateImageAndLabel();
        }

        private void radioButton4_CheckedChanged(object sender, EventArgs e)
        {
            UpdateImageAndLabel();
        }

        private void ExerciseForm_Load(object sender, EventArgs e)
        {
            UpdateImageAndLabel();
        }

    }
}
