using System;
using System.Windows.Forms;

namespace _22___Traffic_Light_Control_Project
{
    public partial class TrafficLightControl : UserControl
    {
        public class TrafficLightEventArgs : EventArgs
        {
            public TrafficLight CurrentLight { get; }

            public TrafficLightEventArgs(TrafficLight currentLight)
            {
                CurrentLight = currentLight;
            }
        }

        public event EventHandler<TrafficLightEventArgs> TrafficLightChanged;

        public enum TrafficLight { RED = 0, ORANGE = 1, GREEN = 2}

        private TrafficLight _currentLight = TrafficLight.RED; // Default
        public TrafficLight CurrentLight
        {
            get => _currentLight;
            set
            {
                if (_currentLight == value)
                    return;

                _currentLight = value;
                UpdateImage();  

                TrafficLightChanged?.Invoke(this, new TrafficLightEventArgs(_currentLight));
            }
        }

        public int RedTime { get; set; } = 10;
        public int OrangeTime { get; set; } = 3;
        public int GreenTime { get; set; } = 10;

        private int _countDownValue;
        private int _index = 0;
        private bool _isForward = true;

        public void UpdateImage()
        {
            switch (_currentLight)
            {
                case TrafficLight.RED:
                    TrafficLightPictureBox.Image = Properties.Resources.Red;
                    break;
                case TrafficLight.ORANGE:
                    TrafficLightPictureBox.Image = Properties.Resources.Orange;
                    break;
                case TrafficLight.GREEN:
                    TrafficLightPictureBox.Image = Properties.Resources.Green;
                    break;
                default:
                    break;
            }
        }

        public void UpdateTimerLabel(int seconds)
        {
            TimeSpan timeSpan = TimeSpan.FromSeconds(seconds);
            TimerLabel.Text = timeSpan.ToString();
        }

        public TrafficLightControl()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (_countDownValue > 0)
            {
                UpdateTimerLabel(_countDownValue);
                _countDownValue--;
            }
            else
                NextLight();
        }

        private void NextLight()
        {
            if (_index == 2)
                _isForward = false;
            else if (_index == 0)
                _isForward = true;

            _index += _isForward ? 1 : -1;

            _countDownValue = GetDurationForIndex(_index);
            CurrentLight = (TrafficLight)_index;
        }

        private int GetDurationForIndex(int index)
        {
            switch(index)
            {
                case 0:
                    return RedTime;
                case 1:
                    return OrangeTime;
                case 2:
                    return GreenTime;
                default:
                    return RedTime;
            }
        }

        public void Start()
        {
            _index = 0;
            CurrentLight = TrafficLight.RED;
            _countDownValue = RedTime;
            timer1.Start();
        }

        public void Stop()
        {
            timer1.Stop();
        }
    }
}
