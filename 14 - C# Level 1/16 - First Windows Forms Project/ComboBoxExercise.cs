using _16___First_Windows_Forms_Project.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;

namespace _16___First_Windows_Forms_Project
{
    public partial class ComboBoxExercise : Form
    {
        public ComboBoxExercise()
        {
            InitializeComponent();
        }

        private void UpdateLabelOnSelection()
        {
            if (comboBox1.SelectedIndex == 0)
            {
                label1.Text = "Book";
                return;
            }

            if (comboBox1.SelectedIndex == 1)
            {
                label1.Text = "Boy";
                return;
            }

            if (comboBox1.SelectedIndex == 2)
            {
                label1.Text = "Girl";
                return;
            }
            else
                label1.Text = "Pen";
        }

        private void UpdateImageOnSelection()
        {
            if (comboBox1.SelectedIndex == 0)
            {
                pictureBox1.Image = Properties.Resources.Book;
                return;
            }

            if (comboBox1.SelectedIndex == 1)
            {
                pictureBox1.Image = Properties.Resources.Boy;
                return;
            }

            if (comboBox1.SelectedIndex == 2)
            {
                pictureBox1.Image = Properties.Resources.Girl;
                return;
            }
            else
                pictureBox1.Image = Properties.Resources.Pen;
        }

        private void ComboBoxExercise_Load(object sender, EventArgs e)
        {
            comboBox1.SelectedIndex = 0;
            UpdateImageOnSelection();
            UpdateLabelOnSelection();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //UpdateImageOnSelection();
            //UpdateLabelOnSelection();

            // or

            switch (comboBox1.SelectedItem)
            {
                case "Boy":
                    {
                        pictureBox1.Image = Resources.Boy;

                        break;
                    }
                case "Girl":
                    {
                        pictureBox1.Image = Resources.Girl;

                        break;
                    }
                case "Pen":
                    {
                        pictureBox1.Image = Resources.Pen;
                        break;
                    }
                case "Book":
                    {
                        pictureBox1.Image = Resources.Book;

                        break;
                    }
            }
            label1.Text = comboBox1.Text;
        }
    }
}
