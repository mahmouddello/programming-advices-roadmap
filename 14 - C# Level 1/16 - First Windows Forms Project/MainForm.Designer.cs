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
            this.SuspendLayout();
            // 
            // btnShowForm1
            // 
            this.btnShowForm1.Location = new System.Drawing.Point(62, 57);
            this.btnShowForm1.Name = "btnShowForm1";
            this.btnShowForm1.Size = new System.Drawing.Size(150, 60);
            this.btnShowForm1.TabIndex = 0;
            this.btnShowForm1.Text = "Show Form 1";
            this.btnShowForm1.UseVisualStyleBackColor = true;
            this.btnShowForm1.Click += new System.EventHandler(this.btnShowForm1_Click);
            // 
            // btnShowFormDialo
            // 
            this.btnShowFormDialo.Location = new System.Drawing.Point(62, 179);
            this.btnShowFormDialo.Name = "btnShowFormDialo";
            this.btnShowFormDialo.Size = new System.Drawing.Size(150, 60);
            this.btnShowFormDialo.TabIndex = 1;
            this.btnShowFormDialo.Text = "Show Form 1 (dialog)";
            this.btnShowFormDialo.UseVisualStyleBackColor = true;
            this.btnShowFormDialo.Click += new System.EventHandler(this.btnShowFormDialo_Click);
            // 
            // btnShowDialogForm
            // 
            this.btnShowDialogForm.Location = new System.Drawing.Point(262, 57);
            this.btnShowDialogForm.Name = "btnShowDialogForm";
            this.btnShowDialogForm.Size = new System.Drawing.Size(150, 60);
            this.btnShowDialogForm.TabIndex = 2;
            this.btnShowDialogForm.Text = "Show Dialog Form";
            this.btnShowDialogForm.UseVisualStyleBackColor = true;
            this.btnShowDialogForm.Click += new System.EventHandler(this.btnShowDialogForm_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(262, 179);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(150, 60);
            this.button1.TabIndex = 3;
            this.button1.Text = "Show Check, Radio, Group Form";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.btnShowDialogForm);
            this.Controls.Add(this.btnShowFormDialo);
            this.Controls.Add(this.btnShowForm1);
            this.Name = "MainForm";
            this.Text = "Main Form";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnShowForm1;
        private System.Windows.Forms.Button btnShowFormDialo;
        private System.Windows.Forms.Button btnShowDialogForm;
        private System.Windows.Forms.Button button1;
    }
}