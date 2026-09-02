namespace _23___Pool_Club_Control_Project
{
    partial class MainForm
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
            this.poolClubControl3 = new _23___Pool_Club_Control_Project.PoolClubControl();
            this.poolClubControl4 = new _23___Pool_Club_Control_Project.PoolClubControl();
            this.poolClubControl2 = new _23___Pool_Club_Control_Project.PoolClubControl();
            this.poolClubControl1 = new _23___Pool_Club_Control_Project.PoolClubControl();
            this.SuspendLayout();
            // 
            // poolClubControl3
            // 
            this.poolClubControl3.HourlyRate = 0F;
            this.poolClubControl3.Location = new System.Drawing.Point(562, 446);
            this.poolClubControl3.Name = "poolClubControl3";
            this.poolClubControl3.PlayerName = "Player";
            this.poolClubControl3.Size = new System.Drawing.Size(515, 407);
            this.poolClubControl3.TabIndex = 3;
            this.poolClubControl3.TableName = "Table";
            this.poolClubControl3.SessionEnded += new System.EventHandler<_23___Pool_Club_Control_Project.PoolClubControl.SessionEndEventArgs>(this.poolClubControl1_SessionEnded);
            // 
            // poolClubControl4
            // 
            this.poolClubControl4.HourlyRate = 0F;
            this.poolClubControl4.Location = new System.Drawing.Point(12, 446);
            this.poolClubControl4.Name = "poolClubControl4";
            this.poolClubControl4.PlayerName = "Player";
            this.poolClubControl4.Size = new System.Drawing.Size(515, 407);
            this.poolClubControl4.TabIndex = 2;
            this.poolClubControl4.TableName = "Table";
            this.poolClubControl4.SessionEnded += new System.EventHandler<_23___Pool_Club_Control_Project.PoolClubControl.SessionEndEventArgs>(this.poolClubControl1_SessionEnded);
            // 
            // poolClubControl2
            // 
            this.poolClubControl2.HourlyRate = 0F;
            this.poolClubControl2.Location = new System.Drawing.Point(562, 12);
            this.poolClubControl2.Name = "poolClubControl2";
            this.poolClubControl2.PlayerName = "Player";
            this.poolClubControl2.Size = new System.Drawing.Size(515, 407);
            this.poolClubControl2.TabIndex = 1;
            this.poolClubControl2.TableName = "Table";
            this.poolClubControl2.SessionEnded += new System.EventHandler<_23___Pool_Club_Control_Project.PoolClubControl.SessionEndEventArgs>(this.poolClubControl1_SessionEnded);
            // 
            // poolClubControl1
            // 
            this.poolClubControl1.HourlyRate = 60F;
            this.poolClubControl1.Location = new System.Drawing.Point(12, 12);
            this.poolClubControl1.Name = "poolClubControl1";
            this.poolClubControl1.PlayerName = "Zakzouk";
            this.poolClubControl1.Size = new System.Drawing.Size(515, 407);
            this.poolClubControl1.TabIndex = 0;
            this.poolClubControl1.TableName = "Programming";
            this.poolClubControl1.SessionEnded += new System.EventHandler<_23___Pool_Club_Control_Project.PoolClubControl.SessionEndEventArgs>(this.poolClubControl1_SessionEnded);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(144F, 144F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Dpi;
            this.ClientSize = new System.Drawing.Size(1090, 877);
            this.Controls.Add(this.poolClubControl3);
            this.Controls.Add(this.poolClubControl4);
            this.Controls.Add(this.poolClubControl2);
            this.Controls.Add(this.poolClubControl1);
            this.Name = "MainForm";
            this.Text = "MainForm";
            this.ResumeLayout(false);

        }

        #endregion

        private PoolClubControl poolClubControl1;
        private PoolClubControl poolClubControl2;
        private PoolClubControl poolClubControl3;
        private PoolClubControl poolClubControl4;
    }
}