namespace _16___First_Windows_Forms_Project
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
            this.btnShowForm1 = new System.Windows.Forms.Button();
            this.btnShowFormDialo = new System.Windows.Forms.Button();
            this.btnShowDialogForm = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.ShowMoreAboutTextboxForm = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnShowForm1
            // 
            this.btnShowForm1.Location = new System.Drawing.Point(70, 71);
            this.btnShowForm1.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnShowForm1.Name = "btnShowForm1";
            this.btnShowForm1.Size = new System.Drawing.Size(169, 75);
            this.btnShowForm1.TabIndex = 0;
            this.btnShowForm1.Text = "Show Form 1";
            this.btnShowForm1.UseVisualStyleBackColor = true;
            this.btnShowForm1.Click += new System.EventHandler(this.btnShowForm1_Click);
            // 
            // btnShowFormDialo
            // 
            this.btnShowFormDialo.Location = new System.Drawing.Point(70, 224);
            this.btnShowFormDialo.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnShowFormDialo.Name = "btnShowFormDialo";
            this.btnShowFormDialo.Size = new System.Drawing.Size(169, 75);
            this.btnShowFormDialo.TabIndex = 1;
            this.btnShowFormDialo.Text = "Show Form 1 (dialog)";
            this.btnShowFormDialo.UseVisualStyleBackColor = true;
            this.btnShowFormDialo.Click += new System.EventHandler(this.btnShowFormDialo_Click);
            // 
            // btnShowDialogForm
            // 
            this.btnShowDialogForm.Location = new System.Drawing.Point(295, 71);
            this.btnShowDialogForm.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnShowDialogForm.Name = "btnShowDialogForm";
            this.btnShowDialogForm.Size = new System.Drawing.Size(169, 75);
            this.btnShowDialogForm.TabIndex = 2;
            this.btnShowDialogForm.Text = "Show Dialog Form";
            this.btnShowDialogForm.UseVisualStyleBackColor = true;
            this.btnShowDialogForm.Click += new System.EventHandler(this.btnShowDialogForm_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(295, 224);
            this.button1.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(169, 75);
            this.button1.TabIndex = 3;
            this.button1.Text = "Show Check, Radio, Group Form";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // ShowMoreAboutTextboxForm
            // 
            this.ShowMoreAboutTextboxForm.Location = new System.Drawing.Point(295, 368);
            this.ShowMoreAboutTextboxForm.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.ShowMoreAboutTextboxForm.Name = "ShowMoreAboutTextboxForm";
            this.ShowMoreAboutTextboxForm.Size = new System.Drawing.Size(169, 75);
            this.ShowMoreAboutTextboxForm.TabIndex = 4;
            this.ShowMoreAboutTextboxForm.Text = "More About TextBox";
            this.ShowMoreAboutTextboxForm.UseVisualStyleBackColor = true;
            this.ShowMoreAboutTextboxForm.Click += new System.EventHandler(this.ShowMoreAboutTextboxForm_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(518, 71);
            this.button2.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(169, 75);
            this.button2.TabIndex = 5;
            this.button2.Text = "Masked Textbox";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(518, 224);
            this.button3.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(169, 75);
            this.button3.TabIndex = 6;
            this.button3.Text = "Combobox Form";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(518, 368);
            this.button4.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(169, 75);
            this.button4.TabIndex = 7;
            this.button4.Text = "LinkLabel Form";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(900, 562);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.ShowMoreAboutTextboxForm);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.btnShowDialogForm);
            this.Controls.Add(this.btnShowFormDialo);
            this.Controls.Add(this.btnShowForm1);
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Name = "MainForm";
            this.Text = "Main Form";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnShowForm1;
        private System.Windows.Forms.Button btnShowFormDialo;
        private System.Windows.Forms.Button btnShowDialogForm;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button ShowMoreAboutTextboxForm;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
    }
}