namespace _03_01___Simple_Event_With_Parameters_Using_Arguments
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.calculatorControl1 = new _03_01___Simple_Event_With_Parameters_Using_Arguments.CalculatorControl();
            this.SuspendLayout();
            // 
            // calculatorControl1
            // 
            this.calculatorControl1.BackColor = System.Drawing.Color.Yellow;
            this.calculatorControl1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.calculatorControl1.Location = new System.Drawing.Point(12, 16);
            this.calculatorControl1.Name = "calculatorControl1";
            this.calculatorControl1.Size = new System.Drawing.Size(507, 180);
            this.calculatorControl1.TabIndex = 0;
            this.calculatorControl1.OnCalculationComplete += new System.EventHandler<_03_01___Simple_Event_With_Parameters_Using_Arguments.CalculatorControl.CalculationCompleteEventArgs>(this.calculatorControl1_OnCalculationComplete);
            // 
            // Form1
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.None;
            this.ClientSize = new System.Drawing.Size(544, 208);
            this.Controls.Add(this.calculatorControl1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private CalculatorControl calculatorControl1;
    }
}

