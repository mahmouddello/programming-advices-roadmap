using System;
using System.ComponentModel;
using System.Windows.Forms;

namespace _23___Pool_Club_Control_Project
{
    public partial class PoolClubControl : UserControl
    {
        public class SessionEndEventArgs : EventArgs
        {
            public string PlayerName { get; }
            public string TableName { get; }
            public string TimeConsumed { get; }
            public int TotalSeconds { get; }
            public float HourlyRate { get; }
            public double TotalFees { get; }

            public SessionEndEventArgs
            (
                string playerName, string tableName, string timeConsumed, int totalSeconds, float hourlyRate, double totalFees
            )
            {
                PlayerName = playerName;
                TableName = tableName;
                TimeConsumed = timeConsumed;
                TotalSeconds = totalSeconds;
                HourlyRate = hourlyRate;
                TotalFees = totalFees;
            }
        }

        public event EventHandler<SessionEndEventArgs> SessionEnded;

        private float _hourlyRate;

        [Category("Pool Config"), Description("The Table's name")]
        public string TableName
        {
            get => TableInfoGroupBox.Text;
            set
            {
                if (string.IsNullOrWhiteSpace(value))
                {
                    MessageBox.Show("Empty, Whitespace table name isn't allowed");
                    return;
                }

                TableInfoGroupBox.Text = value;
            }
        }

        [Category("Pool Config"), Description("The Players's name")]
        public string PlayerName
        {
            get => PlayerNameLabel.Text;
            set
            {
                if (string.IsNullOrWhiteSpace(value))
                {
                    MessageBox.Show("Empty, Whitespace table name isn't allowed");
                    return;
                }

                PlayerNameLabel.Text = value;
            }
        }

        [Category("Pool Config"), Description("Hourly rate of this table")]
        public float HourlyRate
        {
            get => _hourlyRate;
            set
            {
                if (value < 0)
                    return;

                _hourlyRate = value;
            }
        }

        private int _elapsedSeconds { get; set; } = 0;

        public PoolClubControl()
        {
            InitializeComponent();
            StartStopButton.Text = TableTimer.Enabled ? "Stop" : "Start";
        }

        public void StartOrContinueSession()
        {
            TableTimer.Enabled = true;
            TableTimer.Start();
            StartStopButton.Text = "Stop";
        }

        public void StopSession()
        {
            TableTimer.Enabled = false;
            TableTimer.Stop();
            StartStopButton.Text = "Start";
        }

        private void TableTimer_Tick(object sender, EventArgs e)
        {
            _elapsedSeconds++;
            UpdateTimerLabel();
        }

        private void UpdateTimerLabel()
        {
            TimeSpan timeSpan = TimeSpan.FromSeconds(_elapsedSeconds);
            TimerLabel.Text = timeSpan.ToString();
        }

        private void StartStopButton_Click(object sender, EventArgs e)
        {
            if (TableTimer.Enabled)
                StopSession();
            else
                StartOrContinueSession();
        }

        private void EndButton_Click(object sender, EventArgs e)
        {
            TableTimer.Stop();
            SessionEnded?.Invoke(this, ConstructObject());
            ResetTable();
        }

        private void ResetTable()
        {
            TableTimer.Enabled = false;
            StartStopButton.Text = "Start";
            _elapsedSeconds = 0;
            UpdateTimerLabel();
        }

        private SessionEndEventArgs ConstructObject()
        {
            TimeSpan timeSpan = TimeSpan.FromSeconds(_elapsedSeconds);

            SessionEndEventArgs obj = new SessionEndEventArgs
            (
                playerName: PlayerName,
                tableName: TableName,
                timeConsumed: timeSpan.ToString(),
                totalSeconds: _elapsedSeconds,
                hourlyRate: _hourlyRate,
                totalFees: (_elapsedSeconds / 3600.0) * _hourlyRate
            );

            return obj;
        }
    }
}
