namespace _01___Send_Data_Between_Forms.Send_Data_Back_Using_Delegates
{
    partial class Form3
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
            this.label1 = new System.Windows.Forms.Label();
            this.lblData = new System.Windows.Forms.Label();
            this.btnSendDataBack = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(286, 26);
            this.label1.TabIndex = 0;
            this.label1.Text = "Data Recieved from Form 4:";
            // 
            // lblData
            // 
            this.lblData.AutoSize = true;
            this.lblData.Location = new System.Drawing.Point(304, 22);
            this.lblData.Name = "lblData";
            this.lblData.Size = new System.Drawing.Size(48, 26);
            this.lblData.TabIndex = 1;
            this.lblData.Text = "???";
            // 
            // btnSendDataBack
            // 
            this.btnSendDataBack.Location = new System.Drawing.Point(370, 16);
            this.btnSendDataBack.Name = "btnSendDataBack";
            this.btnSendDataBack.Size = new System.Drawing.Size(209, 32);
            this.btnSendDataBack.TabIndex = 7;
            this.btnSendDataBack.Text = "Open Form 4";
            this.btnSendDataBack.UseVisualStyleBackColor = true;
            this.btnSendDataBack.Click += new System.EventHandler(this.btnSendDataBack_Click);
            // 
            // Form3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(13F, 26F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(681, 71);
            this.Controls.Add(this.btnSendDataBack);
            this.Controls.Add(this.lblData);
            this.Controls.Add(this.label1);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form3";
            this.Text = "Form3";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lblData;
        private System.Windows.Forms.Button btnSendDataBack;
    }
}