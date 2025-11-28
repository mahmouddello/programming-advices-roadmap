namespace _01___User_Controls
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
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.ctrlSimpleCalculator3 = new _01___User_Controls.ctrlSimpleCalculator();
            this.ctrlSimpleCalculator2 = new _01___User_Controls.ctrlSimpleCalculator();
            this.ctrlSimpleCalculator1 = new _01___User_Controls.ctrlSimpleCalculator();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.Location = new System.Drawing.Point(66, 343);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(119, 41);
            this.button1.TabIndex = 3;
            this.button1.Text = "Hide";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button2.Location = new System.Drawing.Point(327, 343);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(119, 41);
            this.button2.TabIndex = 4;
            this.button2.Text = "Hide";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button3.Location = new System.Drawing.Point(592, 343);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(119, 41);
            this.button3.TabIndex = 5;
            this.button3.Text = "Hide";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // ctrlSimpleCalculator3
            // 
            this.ctrlSimpleCalculator3.Location = new System.Drawing.Point(539, 31);
            this.ctrlSimpleCalculator3.Name = "ctrlSimpleCalculator3";
            this.ctrlSimpleCalculator3.Size = new System.Drawing.Size(238, 285);
            this.ctrlSimpleCalculator3.TabIndex = 2;
            // 
            // ctrlSimpleCalculator2
            // 
            this.ctrlSimpleCalculator2.Location = new System.Drawing.Point(278, 31);
            this.ctrlSimpleCalculator2.Name = "ctrlSimpleCalculator2";
            this.ctrlSimpleCalculator2.Size = new System.Drawing.Size(238, 285);
            this.ctrlSimpleCalculator2.TabIndex = 1;
            // 
            // ctrlSimpleCalculator1
            // 
            this.ctrlSimpleCalculator1.Location = new System.Drawing.Point(12, 31);
            this.ctrlSimpleCalculator1.Name = "ctrlSimpleCalculator1";
            this.ctrlSimpleCalculator1.Size = new System.Drawing.Size(238, 285);
            this.ctrlSimpleCalculator1.TabIndex = 0;
            // 
            // button4
            // 
            this.button4.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button4.Location = new System.Drawing.Point(592, 423);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(119, 41);
            this.button4.TabIndex = 8;
            this.button4.Text = "Result";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button5
            // 
            this.button5.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button5.Location = new System.Drawing.Point(327, 423);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(119, 41);
            this.button5.TabIndex = 7;
            this.button5.Text = "Result";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // button6
            // 
            this.button6.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button6.Location = new System.Drawing.Point(66, 423);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(119, 41);
            this.button6.TabIndex = 6;
            this.button6.Text = "Result";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 486);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.ctrlSimpleCalculator3);
            this.Controls.Add(this.ctrlSimpleCalculator2);
            this.Controls.Add(this.ctrlSimpleCalculator1);
            this.Name = "frmMain";
            this.Text = "Main Form";
            this.ResumeLayout(false);

        }

        #endregion

        private ctrlSimpleCalculator ctrlSimpleCalculator1;
        private ctrlSimpleCalculator ctrlSimpleCalculator2;
        private ctrlSimpleCalculator ctrlSimpleCalculator3;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
    }
}

