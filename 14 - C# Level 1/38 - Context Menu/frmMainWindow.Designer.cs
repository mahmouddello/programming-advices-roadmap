namespace _38___Context_Menu
{
    partial class frmMainWindow
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
            this.components = new System.ComponentModel.Container();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.cmsTextbox = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.tsmChangeColor = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmChangeFont = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmClear = new System.Windows.Forms.ToolStripMenuItem();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.fontDialog1 = new System.Windows.Forms.FontDialog();
            this.button1 = new System.Windows.Forms.Button();
            this.cmsTextbox.SuspendLayout();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.ContextMenuStrip = this.cmsTextbox;
            this.textBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox1.Location = new System.Drawing.Point(136, 138);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(299, 35);
            this.textBox1.TabIndex = 1;
            // 
            // cmsTextbox
            // 
            this.cmsTextbox.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.cmsTextbox.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmChangeColor,
            this.tsmChangeFont,
            this.tsmClear});
            this.cmsTextbox.Name = "tsmTextbox";
            this.cmsTextbox.Size = new System.Drawing.Size(193, 100);
            // 
            // tsmChangeColor
            // 
            this.tsmChangeColor.Name = "tsmChangeColor";
            this.tsmChangeColor.Size = new System.Drawing.Size(240, 32);
            this.tsmChangeColor.Text = "Change Color";
            this.tsmChangeColor.Click += new System.EventHandler(this.tsmChangeColor_Click);
            // 
            // tsmChangeFont
            // 
            this.tsmChangeFont.Name = "tsmChangeFont";
            this.tsmChangeFont.Size = new System.Drawing.Size(240, 32);
            this.tsmChangeFont.Text = "Change Font";
            this.tsmChangeFont.Click += new System.EventHandler(this.tsmChangeFont_Click);
            // 
            // tsmClear
            // 
            this.tsmClear.Name = "tsmClear";
            this.tsmClear.Size = new System.Drawing.Size(240, 32);
            this.tsmClear.Text = "Clear";
            this.tsmClear.Click += new System.EventHandler(this.tsmClear_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(168, 248);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(192, 70);
            this.button1.TabIndex = 3;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // frmMainWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1320, 690);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textBox1);
            this.IsMdiContainer = true;
            this.Name = "frmMainWindow";
            this.Text = "Form1";
            this.cmsTextbox.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.ContextMenuStrip cmsTextbox;
        private System.Windows.Forms.ToolStripMenuItem tsmChangeColor;
        private System.Windows.Forms.ToolStripMenuItem tsmChangeFont;
        private System.Windows.Forms.ToolStripMenuItem tsmClear;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.FontDialog fontDialog1;
        private System.Windows.Forms.Button button1;
    }
}

