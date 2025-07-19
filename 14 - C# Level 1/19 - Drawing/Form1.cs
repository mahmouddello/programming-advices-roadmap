using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _19___Drawing
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

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Color Blue = Color.FromKnownColor(KnownColor.Blue);
            Pen DrawingPen = new Pen(Blue);
            DrawingPen.Width = 5;

            DrawingPen.StartCap = System.Drawing.Drawing2D.LineCap.Round; 
            DrawingPen.EndCap = System.Drawing.Drawing2D.LineCap.Round;

            // draw horizontal line, shapes
            e.Graphics.DrawLine(DrawingPen, 100, 100, 100, 200);
            e.Graphics.DrawRectangle(DrawingPen, 150, 150, 100, 150);
            e.Graphics.DrawEllipse(DrawingPen, 200, 50, 100, 90);
        }
    }
}
