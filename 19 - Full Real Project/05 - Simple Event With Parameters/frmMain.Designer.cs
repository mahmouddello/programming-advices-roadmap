namespace _05___Simple_Event_With_Parameters
{
    partial class frmMain
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
            this.ctrlSimpleCalculator1 = new _01___User_Controls.ctrlSimpleCalculator();
            this.SuspendLayout();
            // 
            // ctrlSimpleCalculator1
            // 
            this.ctrlSimpleCalculator1.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ctrlSimpleCalculator1.Location = new System.Drawing.Point(12, 12);
            this.ctrlSimpleCalculator1.Name = "ctrlSimpleCalculator1";
            this.ctrlSimpleCalculator1.Size = new System.Drawing.Size(528, 288);
            this.ctrlSimpleCalculator1.TabIndex = 0;
            this.ctrlSimpleCalculator1.OnCalculationComplete += new System.Action<float>(this.ctrlSimpleCalculator1_OnCalculationComplete);
            this.ctrlSimpleCalculator1.Load += new System.EventHandler(this.ctrlSimpleCalculator1_Load);
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.ctrlSimpleCalculator1);
            this.Name = "frmMain";
            this.Text = "Main Form";
            this.ResumeLayout(false);

        }

        #endregion

        private _01___User_Controls.ctrlSimpleCalculator ctrlSimpleCalculator1;
    }
}

