using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _01___Send_Data_Between_Forms.Send_Data_Back_Using_Delegates
{
    public partial class Form3 : Form
    {
        private int _personId;

        public Form3()
        {
            InitializeComponent();
        }

        private void btnSendDataBack_Click(object sender, EventArgs e)
        {
            Form4 form = new Form4();
            form.OnDataBack += PopUpMessage; // Subscribe to the event
            form.ShowDialog();
        }

        private void PopUpMessage(int personId)
        {
            _personId = personId;
            lblData.Text = _personId.ToString();
            MessageBox.Show("Person ID:" + _personId);
        }
    }
}
