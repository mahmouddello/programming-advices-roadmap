namespace _22___Traffic_Light_Control_Project
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
            this.trafficLightControl1 = new _22___Traffic_Light_Control_Project.TrafficLightControl();
            this.SuspendLayout();
            // 
            // trafficLightControl1
            // 
            this.trafficLightControl1.CurrentLight = _22___Traffic_Light_Control_Project.TrafficLightControl.TrafficLight.RED;
            this.trafficLightControl1.GreenTime = 5;
            this.trafficLightControl1.Location = new System.Drawing.Point(156, 12);
            this.trafficLightControl1.Name = "trafficLightControl1";
            this.trafficLightControl1.OrangeTime = 3;
            this.trafficLightControl1.RedTime = 7;
            this.trafficLightControl1.Size = new System.Drawing.Size(112, 306);
            this.trafficLightControl1.TabIndex = 0;
            this.trafficLightControl1.TrafficLightChanged += new System.EventHandler<_22___Traffic_Light_Control_Project.TrafficLightControl.TrafficLightEventArgs>(this.trafficLightControl1_TrafficLightChanged);
            this.trafficLightControl1.Load += new System.EventHandler(this.trafficLightControl1_Load);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(448, 400);
            this.Controls.Add(this.trafficLightControl1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private TrafficLightControl trafficLightControl1;
    }
}