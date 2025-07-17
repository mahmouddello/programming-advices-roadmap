namespace _16___First_Windows_Forms_Project
{
    partial class frmChkRadioGroup
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
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.button1 = new System.Windows.Forms.Button();
            this.btnCheckStatus = new System.Windows.Forms.Button();
            this.rbSmall = new System.Windows.Forms.RadioButton();
            this.rbMedium = new System.Windows.Forms.RadioButton();
            this.rbLarge = new System.Windows.Forms.RadioButton();
            this.btnRb1Status = new System.Windows.Forms.Button();
            this.rbThick = new System.Windows.Forms.RadioButton();
            this.rbThin = new System.Windows.Forms.RadioButton();
            this.gbCrust = new System.Windows.Forms.GroupBox();
            this.gbSize = new System.Windows.Forms.GroupBox();
            this.btnHidePizzaGroup = new System.Windows.Forms.Button();
            this.gbCrust.SuspendLayout();
            this.gbSize.SuspendLayout();
            this.SuspendLayout();
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Location = new System.Drawing.Point(80, 62);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(95, 20);
            this.checkBox1.TabIndex = 0;
            this.checkBox1.Text = "checkBox1";
            this.checkBox1.UseVisualStyleBackColor = true;
            this.checkBox1.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(63, 149);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(122, 70);
            this.button1.TabIndex = 1;
            this.button1.Text = "Show Checkbox Value";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // btnCheckStatus
            // 
            this.btnCheckStatus.Enabled = false;
            this.btnCheckStatus.Location = new System.Drawing.Point(53, 281);
            this.btnCheckStatus.Name = "btnCheckStatus";
            this.btnCheckStatus.Size = new System.Drawing.Size(122, 70);
            this.btnCheckStatus.TabIndex = 2;
            this.btnCheckStatus.Text = "Enable Disable Button with Checkbox";
            this.btnCheckStatus.UseVisualStyleBackColor = true;
            this.btnCheckStatus.Click += new System.EventHandler(this.btnCheckStatus_Click);
            // 
            // rbSmall
            // 
            this.rbSmall.AutoSize = true;
            this.rbSmall.Location = new System.Drawing.Point(79, 34);
            this.rbSmall.Name = "rbSmall";
            this.rbSmall.Size = new System.Drawing.Size(62, 20);
            this.rbSmall.TabIndex = 3;
            this.rbSmall.TabStop = true;
            this.rbSmall.Text = "Small";
            this.rbSmall.UseVisualStyleBackColor = true;
            // 
            // rbMedium
            // 
            this.rbMedium.AutoSize = true;
            this.rbMedium.Location = new System.Drawing.Point(79, 100);
            this.rbMedium.Name = "rbMedium";
            this.rbMedium.Size = new System.Drawing.Size(76, 20);
            this.rbMedium.TabIndex = 4;
            this.rbMedium.TabStop = true;
            this.rbMedium.Text = "Medium";
            this.rbMedium.UseVisualStyleBackColor = true;
            // 
            // rbLarge
            // 
            this.rbLarge.AutoSize = true;
            this.rbLarge.Location = new System.Drawing.Point(79, 166);
            this.rbLarge.Name = "rbLarge";
            this.rbLarge.Size = new System.Drawing.Size(63, 20);
            this.rbLarge.TabIndex = 5;
            this.rbLarge.TabStop = true;
            this.rbLarge.Text = "Large";
            this.rbLarge.UseVisualStyleBackColor = true;
            // 
            // btnRb1Status
            // 
            this.btnRb1Status.Location = new System.Drawing.Point(323, 281);
            this.btnRb1Status.Name = "btnRb1Status";
            this.btnRb1Status.Size = new System.Drawing.Size(122, 70);
            this.btnRb1Status.TabIndex = 6;
            this.btnRb1Status.Text = "Check Radio Button 1 Status";
            this.btnRb1Status.UseVisualStyleBackColor = true;
            this.btnRb1Status.Click += new System.EventHandler(this.btnRb1Status_Click);
            // 
            // rbThick
            // 
            this.rbThick.AutoSize = true;
            this.rbThick.Location = new System.Drawing.Point(12, 100);
            this.rbThick.Name = "rbThick";
            this.rbThick.Size = new System.Drawing.Size(61, 20);
            this.rbThick.TabIndex = 8;
            this.rbThick.TabStop = true;
            this.rbThick.Text = "Thick";
            this.rbThick.UseVisualStyleBackColor = true;
            // 
            // rbThin
            // 
            this.rbThin.AutoSize = true;
            this.rbThin.Location = new System.Drawing.Point(12, 31);
            this.rbThin.Name = "rbThin";
            this.rbThin.Size = new System.Drawing.Size(54, 20);
            this.rbThin.TabIndex = 7;
            this.rbThin.TabStop = true;
            this.rbThin.Text = "Thin";
            this.rbThin.UseVisualStyleBackColor = true;
            // 
            // gbCrust
            // 
            this.gbCrust.Controls.Add(this.rbThick);
            this.gbCrust.Controls.Add(this.rbThin);
            this.gbCrust.Location = new System.Drawing.Point(643, 90);
            this.gbCrust.Name = "gbCrust";
            this.gbCrust.Size = new System.Drawing.Size(240, 141);
            this.gbCrust.TabIndex = 9;
            this.gbCrust.TabStop = false;
            this.gbCrust.Text = "Crust";
            // 
            // gbSize
            // 
            this.gbSize.Controls.Add(this.rbMedium);
            this.gbSize.Controls.Add(this.rbSmall);
            this.gbSize.Controls.Add(this.rbLarge);
            this.gbSize.Location = new System.Drawing.Point(278, 55);
            this.gbSize.Name = "gbSize";
            this.gbSize.Size = new System.Drawing.Size(315, 197);
            this.gbSize.TabIndex = 10;
            this.gbSize.TabStop = false;
            this.gbSize.Text = "Size";
            // 
            // btnHidePizzaGroup
            // 
            this.btnHidePizzaGroup.Location = new System.Drawing.Point(323, 374);
            this.btnHidePizzaGroup.Name = "btnHidePizzaGroup";
            this.btnHidePizzaGroup.Size = new System.Drawing.Size(122, 70);
            this.btnHidePizzaGroup.TabIndex = 11;
            this.btnHidePizzaGroup.Text = "Hide Pizza Size Group";
            this.btnHidePizzaGroup.UseVisualStyleBackColor = true;
            this.btnHidePizzaGroup.Click += new System.EventHandler(this.btnHidePizzaGroup_Click);
            // 
            // frmChkRadioGroup
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(939, 498);
            this.Controls.Add(this.btnHidePizzaGroup);
            this.Controls.Add(this.gbSize);
            this.Controls.Add(this.gbCrust);
            this.Controls.Add(this.btnRb1Status);
            this.Controls.Add(this.btnCheckStatus);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.checkBox1);
            this.Name = "frmChkRadioGroup";
            this.Text = "frmChkRadioGroup";
            this.gbCrust.ResumeLayout(false);
            this.gbCrust.PerformLayout();
            this.gbSize.ResumeLayout(false);
            this.gbSize.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button btnCheckStatus;
        private System.Windows.Forms.RadioButton rbSmall;
        private System.Windows.Forms.RadioButton rbMedium;
        private System.Windows.Forms.RadioButton rbLarge;
        private System.Windows.Forms.Button btnRb1Status;
        private System.Windows.Forms.RadioButton rbThick;
        private System.Windows.Forms.RadioButton rbThin;
        private System.Windows.Forms.GroupBox gbCrust;
        private System.Windows.Forms.GroupBox gbSize;
        private System.Windows.Forms.Button btnHidePizzaGroup;
    }
}