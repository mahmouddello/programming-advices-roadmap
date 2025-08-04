using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Windows.Forms;

namespace _21___NotifyIcon
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            notifyIcon1.Icon = SystemIcons.Application;
            notifyIcon1.BalloonTipIcon = ToolTipIcon.Warning;
            notifyIcon1.BalloonTipTitle = "Hi";
            notifyIcon1.BalloonTipText = "Hello Students!";
            notifyIcon1.ShowBalloonTip(2000);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            notifyIcon1.Visible = true;
        }
    }
}
