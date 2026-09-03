namespace _25___Introduction_to_Custom_Controls
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
            this.button1 = new System.Windows.Forms.Button();
            this.myCustomTextBox1 = new _25___Introduction_to_Custom_Controls.MyCustomTextBox();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(40, 121);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(178, 60);
            this.button1.TabIndex = 1;
            this.button1.Text = "Validate";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // myCustomTextBox1
            // 
            this.myCustomTextBox1.InputType = _25___Introduction_to_Custom_Controls.MyCustomTextBox.InputTypeEnum.NumberInput;
            this.myCustomTextBox1.IsRequired = true;
            this.myCustomTextBox1.Location = new System.Drawing.Point(40, 38);
            this.myCustomTextBox1.Margin = new System.Windows.Forms.Padding(5, 4, 5, 4);
            this.myCustomTextBox1.Name = "myCustomTextBox1";
            this.myCustomTextBox1.Size = new System.Drawing.Size(329, 35);
            this.myCustomTextBox1.TabIndex = 0;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(14F, 29F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1037, 575);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.myCustomTextBox1);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Margin = new System.Windows.Forms.Padding(5, 4, 5, 4);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private MyCustomTextBox myCustomTextBox1;
        private System.Windows.Forms.Button button1;
    }
}

