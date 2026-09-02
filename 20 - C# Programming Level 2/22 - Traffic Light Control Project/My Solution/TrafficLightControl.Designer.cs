namespace _22___Traffic_Light_Control_Project
{
    partial class TrafficLightControl
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.TrafficLightPictureBox = new System.Windows.Forms.PictureBox();
            this.TimerLabel = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.TrafficLightPictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // TrafficLightPictureBox
            // 
            this.TrafficLightPictureBox.Image = global::_22___Traffic_Light_Control_Project.Properties.Resources.Red;
            this.TrafficLightPictureBox.Location = new System.Drawing.Point(3, 3);
            this.TrafficLightPictureBox.Name = "TrafficLightPictureBox";
            this.TrafficLightPictureBox.Size = new System.Drawing.Size(119, 213);
            this.TrafficLightPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.TrafficLightPictureBox.TabIndex = 0;
            this.TrafficLightPictureBox.TabStop = false;
            // 
            // TimerLabel
            // 
            this.TimerLabel.AutoSize = true;
            this.TimerLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TimerLabel.Location = new System.Drawing.Point(43, 239);
            this.TimerLabel.Name = "TimerLabel";
            this.TimerLabel.Size = new System.Drawing.Size(37, 29);
            this.TimerLabel.TabIndex = 1;
            this.TimerLabel.Text = "??";
            // 
            // timer1
            // 
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // TrafficLightControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.TimerLabel);
            this.Controls.Add(this.TrafficLightPictureBox);
            this.Name = "TrafficLightControl";
            this.Size = new System.Drawing.Size(126, 279);
            ((System.ComponentModel.ISupportInitialize)(this.TrafficLightPictureBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox TrafficLightPictureBox;
        private System.Windows.Forms.Label TimerLabel;
        private System.Windows.Forms.Timer timer1;
    }
}
