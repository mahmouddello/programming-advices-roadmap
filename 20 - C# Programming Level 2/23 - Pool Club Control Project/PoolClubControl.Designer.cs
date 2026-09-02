namespace _23___Pool_Club_Control_Project
{
    partial class PoolClubControl
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
            this.TableInfoGroupBox = new System.Windows.Forms.GroupBox();
            this.PlayerNameLabel = new System.Windows.Forms.Label();
            this.StartStopButton = new System.Windows.Forms.Button();
            this.EndButton = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.TableTimer = new System.Windows.Forms.Timer(this.components);
            this.TimerLabel = new System.Windows.Forms.Label();
            this.TableInfoGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // TableInfoGroupBox
            // 
            this.TableInfoGroupBox.Controls.Add(this.TimerLabel);
            this.TableInfoGroupBox.Controls.Add(this.pictureBox1);
            this.TableInfoGroupBox.Controls.Add(this.EndButton);
            this.TableInfoGroupBox.Controls.Add(this.StartStopButton);
            this.TableInfoGroupBox.Controls.Add(this.PlayerNameLabel);
            this.TableInfoGroupBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TableInfoGroupBox.Location = new System.Drawing.Point(3, 15);
            this.TableInfoGroupBox.Name = "TableInfoGroupBox";
            this.TableInfoGroupBox.Size = new System.Drawing.Size(501, 380);
            this.TableInfoGroupBox.TabIndex = 0;
            this.TableInfoGroupBox.TabStop = false;
            this.TableInfoGroupBox.Text = "Table";
            // 
            // PlayerNameLabel
            // 
            this.PlayerNameLabel.AutoSize = true;
            this.PlayerNameLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PlayerNameLabel.Location = new System.Drawing.Point(194, 26);
            this.PlayerNameLabel.Name = "PlayerNameLabel";
            this.PlayerNameLabel.Size = new System.Drawing.Size(106, 37);
            this.PlayerNameLabel.TabIndex = 0;
            this.PlayerNameLabel.Text = "Player";
            // 
            // StartStopButton
            // 
            this.StartStopButton.Location = new System.Drawing.Point(362, 110);
            this.StartStopButton.Name = "StartStopButton";
            this.StartStopButton.Size = new System.Drawing.Size(127, 52);
            this.StartStopButton.TabIndex = 1;
            this.StartStopButton.Text = "Start/Stop";
            this.StartStopButton.UseVisualStyleBackColor = true;
            this.StartStopButton.Click += new System.EventHandler(this.StartStopButton_Click);
            // 
            // EndButton
            // 
            this.EndButton.Location = new System.Drawing.Point(362, 184);
            this.EndButton.Name = "EndButton";
            this.EndButton.Size = new System.Drawing.Size(127, 52);
            this.EndButton.TabIndex = 2;
            this.EndButton.Text = "End";
            this.EndButton.UseVisualStyleBackColor = true;
            this.EndButton.Click += new System.EventHandler(this.EndButton_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::_23___Pool_Club_Control_Project.Properties.Resources._8ball_pool;
            this.pictureBox1.Location = new System.Drawing.Point(23, 87);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(254, 207);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 3;
            this.pictureBox1.TabStop = false;
            // 
            // TableTimer
            // 
            this.TableTimer.Interval = 1000;
            this.TableTimer.Tick += new System.EventHandler(this.TableTimer_Tick);
            // 
            // TimerLabel
            // 
            this.TimerLabel.AutoSize = true;
            this.TimerLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TimerLabel.Location = new System.Drawing.Point(98, 325);
            this.TimerLabel.Name = "TimerLabel";
            this.TimerLabel.Size = new System.Drawing.Size(97, 29);
            this.TimerLabel.TabIndex = 4;
            this.TimerLabel.Text = "??:??:??";
            // 
            // PoolClubControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.TableInfoGroupBox);
            this.Name = "PoolClubControl";
            this.Size = new System.Drawing.Size(515, 407);
            this.TableInfoGroupBox.ResumeLayout(false);
            this.TableInfoGroupBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox TableInfoGroupBox;
        private System.Windows.Forms.Label PlayerNameLabel;
        private System.Windows.Forms.Button EndButton;
        private System.Windows.Forms.Button StartStopButton;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Timer TableTimer;
        private System.Windows.Forms.Label TimerLabel;
    }
}
