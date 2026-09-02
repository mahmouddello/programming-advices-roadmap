using System;
using System.Windows.Forms;

namespace _22___Traffic_Light_Control_Project
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void trafficLightControl1_TrafficLightChanged(object sender, TrafficLightControl.TrafficLightEventArgs e)
        {
            MessageBox.Show("New Light " + trafficLightControl1.CurrentLight.ToString());
        }

        private void trafficLightControl1_Load(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            trafficLightControl1.Start();
        }
    }
}
