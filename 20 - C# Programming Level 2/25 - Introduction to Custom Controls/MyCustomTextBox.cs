using System;
using System.Windows.Forms;

namespace _25___Introduction_to_Custom_Controls
{
    public partial class MyCustomTextBox : TextBox
    {
        public MyCustomTextBox()
        {
            InitializeComponent();
        }

        protected override void OnPaint(PaintEventArgs pe)
        {
            base.OnPaint(pe);
        }

        public bool IsRequired { get; set; }

        public enum InputTypeEnum { TextInput, NumberInput}

        public InputTypeEnum InputType { get; set; } = InputTypeEnum.TextInput;

        public bool IsValid()
        {
            if (IsRequired)
                if (this.Text.Trim().Length == 0)
                    return false;

            if (InputType == InputTypeEnum.NumberInput)
                return IsNumeric();

            return true;
        }

        private bool IsNumeric()
        {
            string str = this.Text.Trim();

            foreach (char c in str)
                if (!char.IsDigit(c) && c != '.') 
                    return false;

            return true;
        }
    }
}
