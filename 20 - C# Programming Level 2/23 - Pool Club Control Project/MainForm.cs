using System;
using System.Windows.Forms;

namespace _23___Pool_Club_Control_Project
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void poolClubControl1_SessionEnded(object sender, PoolClubControl.SessionEndEventArgs e)
        {
            MessageBox.Show
             (
                $"Table: {e.TableName} | Player: {e.PlayerName}\n" +
                $"{new string('-', 10)}\n" +
                $"Time Consumed: {e.TimeConsumed}\nTotal Seconds: {e.TotalSeconds}\n" +
                $"Hourly Rate: {e.HourlyRate}\n{new string('-', 10)}\n" +
                $"Total Fees: {e.TotalFees}"
             );
        }
    }
}
