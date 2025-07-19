using _18___PictureBox.Properties;
using System;
using System.Drawing;
using System.Windows.Forms;

namespace _18___PictureBox
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Resources.Jiren1;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Resources.Jiren2;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Image.FromFile("E:\\Photos\\Important\\mads1.jpeg");
        }
    }
}
