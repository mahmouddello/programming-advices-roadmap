namespace _23___ListView_Control
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.NameTextBox = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.listView1 = new System.Windows.Forms.ListView();
            this.ColumnID = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.ColumnName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.RBDetails = new System.Windows.Forms.RadioButton();
            this.RBTile = new System.Windows.Forms.RadioButton();
            this.RBSmallIcon = new System.Windows.Forms.RadioButton();
            this.RBList = new System.Windows.Forms.RadioButton();
            this.RBLargeIcon = new System.Windows.Forms.RadioButton();
            this.IDTextBox = new System.Windows.Forms.MaskedTextBox();
            this.smallImageList = new System.Windows.Forms.ImageList(this.components);
            this.largeImageList = new System.Windows.Forms.ImageList(this.components);
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(54, 73);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(36, 29);
            this.label1.TabIndex = 0;
            this.label1.Text = "ID";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(54, 140);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(78, 29);
            this.label2.TabIndex = 1;
            this.label2.Text = "Name";
            // 
            // NameTextBox
            // 
            this.NameTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.NameTextBox.Location = new System.Drawing.Point(149, 140);
            this.NameTextBox.Name = "NameTextBox";
            this.NameTextBox.Size = new System.Drawing.Size(208, 35);
            this.NameTextBox.TabIndex = 3;
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.Location = new System.Drawing.Point(386, 73);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(116, 47);
            this.button1.TabIndex = 5;
            this.button1.Text = "Add";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button2.Location = new System.Drawing.Point(508, 73);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(137, 47);
            this.button2.TabIndex = 6;
            this.button2.Text = "Remove";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button3.Location = new System.Drawing.Point(651, 73);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(213, 47);
            this.button3.TabIndex = 7;
            this.button3.Text = "Fill Random";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(935, 45);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(66, 29);
            this.label3.TabIndex = 8;
            this.label3.Text = "View";
            // 
            // listView1
            // 
            this.listView1.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColumnID,
            this.ColumnName});
            this.listView1.HideSelection = false;
            this.listView1.LargeImageList = this.largeImageList;
            this.listView1.Location = new System.Drawing.Point(26, 244);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(1200, 454);
            this.listView1.SmallImageList = this.smallImageList;
            this.listView1.TabIndex = 4;
            this.listView1.UseCompatibleStateImageBehavior = false;
            // 
            // ColumnID
            // 
            this.ColumnID.Text = "ID";
            // 
            // ColumnName
            // 
            this.ColumnName.Text = "Name";
            // 
            // RBDetails
            // 
            this.RBDetails.AutoSize = true;
            this.RBDetails.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RBDetails.Location = new System.Drawing.Point(917, 96);
            this.RBDetails.Name = "RBDetails";
            this.RBDetails.Size = new System.Drawing.Size(112, 33);
            this.RBDetails.TabIndex = 9;
            this.RBDetails.Tag = "Details";
            this.RBDetails.Text = "Details";
            this.RBDetails.UseVisualStyleBackColor = true;
            this.RBDetails.CheckedChanged += new System.EventHandler(this.ControlListView);
            // 
            // RBTile
            // 
            this.RBTile.AutoSize = true;
            this.RBTile.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RBTile.Location = new System.Drawing.Point(917, 190);
            this.RBTile.Name = "RBTile";
            this.RBTile.Size = new System.Drawing.Size(80, 33);
            this.RBTile.TabIndex = 11;
            this.RBTile.Tag = "SmallIcon";
            this.RBTile.Text = "Tile";
            this.RBTile.UseVisualStyleBackColor = true;
            this.RBTile.CheckedChanged += new System.EventHandler(this.ControlListView);
            // 
            // RBSmallIcon
            // 
            this.RBSmallIcon.AutoSize = true;
            this.RBSmallIcon.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RBSmallIcon.Location = new System.Drawing.Point(1118, 142);
            this.RBSmallIcon.Name = "RBSmallIcon";
            this.RBSmallIcon.Size = new System.Drawing.Size(150, 33);
            this.RBSmallIcon.TabIndex = 12;
            this.RBSmallIcon.Tag = "SmallIcon";
            this.RBSmallIcon.Text = "Small Icon";
            this.RBSmallIcon.UseVisualStyleBackColor = true;
            this.RBSmallIcon.CheckedChanged += new System.EventHandler(this.ControlListView);
            // 
            // RBList
            // 
            this.RBList.AutoSize = true;
            this.RBList.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RBList.Location = new System.Drawing.Point(917, 142);
            this.RBList.Name = "RBList";
            this.RBList.Size = new System.Drawing.Size(75, 33);
            this.RBList.TabIndex = 13;
            this.RBList.Tag = "List";
            this.RBList.Text = "List";
            this.RBList.UseVisualStyleBackColor = true;
            this.RBList.CheckedChanged += new System.EventHandler(this.ControlListView);
            // 
            // RBLargeIcon
            // 
            this.RBLargeIcon.AutoSize = true;
            this.RBLargeIcon.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RBLargeIcon.Location = new System.Drawing.Point(1118, 96);
            this.RBLargeIcon.Name = "RBLargeIcon";
            this.RBLargeIcon.Size = new System.Drawing.Size(151, 33);
            this.RBLargeIcon.TabIndex = 14;
            this.RBLargeIcon.Tag = "LargeIcon";
            this.RBLargeIcon.Text = "Large Icon";
            this.RBLargeIcon.UseVisualStyleBackColor = true;
            this.RBLargeIcon.CheckedChanged += new System.EventHandler(this.ControlListView);
            // 
            // IDTextBox
            // 
            this.IDTextBox.Location = new System.Drawing.Point(149, 77);
            this.IDTextBox.Mask = "000";
            this.IDTextBox.Name = "IDTextBox";
            this.IDTextBox.Size = new System.Drawing.Size(100, 26);
            this.IDTextBox.TabIndex = 15;
            this.IDTextBox.ValidatingType = typeof(int);
            // 
            // smallImageList
            // 
            this.smallImageList.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("smallImageList.ImageStream")));
            this.smallImageList.TransparentColor = System.Drawing.Color.Transparent;
            this.smallImageList.Images.SetKeyName(0, "Strong.png");
            this.smallImageList.Images.SetKeyName(1, "Weak.png");
            // 
            // largeImageList
            // 
            this.largeImageList.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("largeImageList.ImageStream")));
            this.largeImageList.TransparentColor = System.Drawing.Color.Transparent;
            this.largeImageList.Images.SetKeyName(0, "Strong.png");
            this.largeImageList.Images.SetKeyName(1, "Weak.png");
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1338, 755);
            this.Controls.Add(this.IDTextBox);
            this.Controls.Add(this.RBLargeIcon);
            this.Controls.Add(this.RBList);
            this.Controls.Add(this.RBSmallIcon);
            this.Controls.Add(this.RBTile);
            this.Controls.Add(this.RBDetails);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.listView1);
            this.Controls.Add(this.NameTextBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "List View";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox NameTextBox;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.RadioButton RBDetails;
        private System.Windows.Forms.RadioButton RBTile;
        private System.Windows.Forms.RadioButton RBSmallIcon;
        private System.Windows.Forms.RadioButton RBList;
        private System.Windows.Forms.RadioButton RBLargeIcon;
        private System.Windows.Forms.MaskedTextBox IDTextBox;
        private System.Windows.Forms.ColumnHeader ColumnID;
        private System.Windows.Forms.ColumnHeader ColumnName;
        private System.Windows.Forms.ImageList largeImageList;
        private System.Windows.Forms.ImageList smallImageList;
    }
}

