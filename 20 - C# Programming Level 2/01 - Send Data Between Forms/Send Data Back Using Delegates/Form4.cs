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
    public partial class Form4 : Form
    {
        public delegate void DataBackHandler(int userId);
        public DataBackHandler OnDataBack;

        public Form4()
        {
            InitializeComponent();
        }

        private void btnSendDataBack_Click(object sender, EventArgs e)
        {
            if (int.TryParse(txtData.Text.Trim(), out int value))
            {
                OnDataBack?.Invoke(value); // if there's listeners, invoke the function with userId param
                this.Close();
            }
            else
            {
                MessageBox.Show("Please enter a valid number.");
            }
        }
    }
}
