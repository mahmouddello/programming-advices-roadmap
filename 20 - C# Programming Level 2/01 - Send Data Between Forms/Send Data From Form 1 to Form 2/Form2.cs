using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _01___Send_Data_Between_Forms
{
    public partial class Form2 : Form
    {
        private int _userId;

        public Form2(int userId)
        {
            InitializeComponent();
            _userId = userId;
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            lblData.Text = _userId.ToString();
        }
    }
}
